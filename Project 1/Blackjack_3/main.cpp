/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/*
 * File:   main.cpp
 * Author: User
 * Created on October 25, 2023, 5:02 PM
 * Purpose: Project 1 for Lehr, create a card game:
 * I choose blackjack.
 */
/*
 * Version 3: Add strings and cstrings for names. Add binary file writing 
 * for record storage. Maybe a leader board. 
 */

//System Libraries
#include <cstdlib>      // exit()
#include <iostream>
#include <time.h>       // time for srand(time(0)); possibly also for runtime stat
#include <vector>       // holds the inital cards dealt and new hits
#include <iomanip>      // format
#include <string>       // include player name
#include <fstream>      // input and output files
using namespace std;

//User Libraries

//Global Constants
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only
//Structures
struct Stats{
    string name;                   // player name
    float bet=0;                   // amount bet
    float win=0;                   // winnings
    float loss=0;                  // losses
    float net=0;                   // net money
};

//Function Prototypes
void fillStandard(int [],fstream &);                                   // reads from a file to set standard array; 
int *fillCards(const int [],const int,int&);           // creates array "cards" that holds values for deck of cards
void shuffle(int *,const int);                         // shuffles cards
void sum(vector<vector<int>> &,const int, int, int,int [],int&);  //sums cards in vector deal
void check(const int, int [], Stats *,int,int,bool &,int &,unsigned int &,unsigned int &);      // checks if you got a blackjack or busted
void dealing(vector<vector<int>> &,int [],int &,int &,int,int,const int);                    // deals cards according to how big the vector is sized after hits or stays
void display(vector<vector<int>> &, int, int[],bool); 
void writeResults();                                    // attempting a leader board

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables or constants here
    Stats *player;                       // pointer to info on player
    int standard[13];            // values for one suit of cards in a deck. 4 included in each deck
    int decks=1;                         // amount of decks to increase random chance. 1 minimum. 8 max. 
    int sizeCards=0;                     // size of cards array
    srand(time(0));                      // randomize seed using time for shuffling
    const int dealSize=2;                // initial deal is only two cards always 
    vector<vector<int>> deal(2,vector<int> (dealSize,0));
    int countAces=0;             // number of aces in each hand 
    int aceIndex;                // index where ace was found
    int sums[dealSize]={0,0};    // sums of each players hands [0] being dealer [1] being player
    int playerHit=0;             // counting the hits to resize vector
    int dealerHit=0;             //counter for dealer hitting
    int loopSize=0;              // size of loop when vector gets bigger based on player or dealer hits
    int choice=1;                     // hit or stay
    int dealerChoice=1;               // dealer hits or stays 
    int dealt=0;                      // dealt cards get value of 0
    bool gameEnd=false;               // put into if statements and validation 
    int gameResult=3;                // did the player win or lose? 0 is lose, 1 is true, -1 is tie
    unsigned int gameWon=0;          // accumulator for games won
    unsigned int gameLost=0;         // accumulator for games lost
    fstream inFile;                   // input file for standard array
    fstream outBin;                   // output file in binary
    fstream records;                  // records to modify leader board
    fstream outFile;                  // output file for leader board
    
    //Dynamically Create Structure
    player=new Stats;
    
    //Input dialogue
    cout<<"This program runs a game of blackjack for 2 players, ";
    cout<<"the user and the dealer."<<endl;
    cout<<"Please enter your name."<<endl; 
    getline(cin,player->name); 
    
    cout<<"Please enter how many decks you would like to use. (1-8)"<<endl;
    cin>>decks;
    //validate decks input
    while(decks>8 || decks<=0) {
        cout<<"Please enter a valid range of decks from 1-8 decks."<<endl;
        cin>>decks;
    }
    
    //ask for bet amount
    cout<<"Please enter how much you'd like to bet for this hand."<<endl;
    cin>>player->bet;
    
    while(player->bet <=0) {
        cout<<"Please enter a positive number only for player bet."<<endl; 
        cin>>player->bet; 
    }
    
    //Fill standard array 
    fillStandard(standard,inFile); 
    
    //Create cards array
    int *cards=fillCards(standard,decks,sizeCards);
    
    //Shuffle cards
    shuffle(cards,sizeCards);
    
    //Deal cards
    dealing(deal,cards,loopSize,dealt,dealerHit,playerHit,dealSize);
    //check input
//    deal[0][0]=1; 
//    deal[0][1]=1; 
//    deal[1][0]=1; 
//    deal[1][1]=2;
    
    //get sums of initial deal
    sum(deal,dealSize,dealerHit,playerHit,sums,loopSize);  
     //check for natural blackjack
    check(dealSize,sums,player,choice,dealerChoice,gameEnd,gameResult,gameLost,gameWon);
    //show cards
    display(deal,loopSize,sums,gameEnd);
 

    //Hit or stay
    bool loopEnd=false;
    while(choice==1 && sums[0]<21 && sums[1]<21 && loopEnd==false) {
        cout<<"Would you like to hit or stay? Press 0 to stay, 1 to hit."<<endl; 
        cin>>choice; 
        switch(choice) {
            case 0:
                cout<<"Player stays."<<endl; 
                choice=0; 
                break; 
            case 1: 
                cout<<"Player hits."<<endl; 
                playerHit++;
                while(cards[dealt]==0) dealt++;     // make sure the card being dealt isn't one that's already been used
                deal[1][(playerHit+dealSize)-1]=cards[dealt];
                cards[dealt]=0; 
                dealt++;  
                choice=1;
                break; 
            default: 
                cout<<"Enter only a 0 or a 1."<<endl;  
                choice=1; 
                loopEnd=true; 
                break; 
        }
    //Dealer hit or stay
        if(loopEnd==false) {             // validate the choice by player
            
            if(sums[0]<17) {
                cout<<"Dealer hits."<<endl;  
                dealerHit++;                        // count hits of dealer to size 2d vector 
                while(cards[dealt]==0) dealt++;     // make sure the card being dealt isn't one that's already been used
                deal[0][(dealerHit+dealSize)-1]=cards[dealt];   // give a new card
                cards[dealt]=0;                     // set card values to 0
                dealt++;                            // move to the next index of cards
                dealerChoice=1;                     // dealer hits
    
        }
            else if(sums[0]>=17) {
                cout<<"Dealer stays."<<endl; 
                dealerChoice=0;             // dealer stops. if player stays then stop loop 
        }
    // checks sums again
        sum(deal,dealSize,dealerHit,playerHit,sums,loopSize);
     // check
        check(dealSize,sums,player,choice,dealerChoice,gameEnd,gameResult,gameLost,gameWon);
    // display new cards
        display(deal,loopSize,sums,gameEnd);  
    }
        loopEnd=false;               // allow player to retry the input for choice
 }
    
    //while loop ends when either player stops hitting or busts. sometimes dealer still hits so this accounts for that
    dealerChoice=1;         // keeps hitting? 
    while(sums[0]<17 && gameEnd==false) {
        cout<<"Dealer hits after players stays."<<endl; 
        dealerHit++; 
        while(cards[dealt]==0) dealt++;     // make sure the card being dealt isn't one that's already been used
        deal[0][(dealerHit+dealSize)-1]=cards[dealt++]; 
        cards[dealt]=0;  
        // checks sums again
        sum(deal,dealSize,dealerHit,playerHit,sums,loopSize); 
        // display again
        display(deal,loopSize,sums,gameEnd);
    }
    dealerChoice=0;         // now stays after while loop is done 
    
    
    //while loop ends now check conditions
    check(dealSize,sums,player,choice,dealerChoice,gameEnd,gameResult,gameLost,gameWon); 
    
    //Output changes into records
    records.open("records.txt", ios::out|ios::app); 
    records<<player->name<<endl;  
    records<<gameWon<<endl; 
    records<<gameLost<<endl; 
    records<<player->net<<endl;   
    records.close(); 
    
    //couldn't figure out how to read in records and change them based on previous games. I can read them in but I can't figure out how to change them after the fact

    //Output File
    if(gameEnd=true) {
        outFile.open("results.txt", ios::out|ios::app); 
        if(gameResult==0) {
            outFile<<player->name<<" has lost the game."<<endl; 
            outFile<<"Wins: "<<gameWon<<endl;  
            outFile<<"Losses: "<<gameLost<<endl; 
            outFile<<"Net $: "<<player->net<<endl<<endl; 
        }
        else if(gameResult==1) {
            outFile<<player->name<<" has won the game."<<endl; 
            outFile<<"Wins: "<<gameWon<<endl;  
            outFile<<"Losses: "<<gameLost<<endl; 
            outFile<<"Net $: "<<player->net<<endl<<endl; 
        }
        else if(gameResult==-1) {
            outFile<<player->name<<" has tied the game."<<endl; 
            outFile<<"Wins: "<<gameWon<<endl;  
            outFile<<"Losses: "<<gameLost<<endl; 
            outFile<<"Net $: "<<player->net<<endl<<endl; 
        }
        outFile.close(); 
        
    }
    
    //Output in binary to a txt file
    outBin.open("recordsBinary.txt", ios::out|ios::binary); 
    outBin<<player->name<<endl;  // couldn't figure out how to write this in binary
    outBin<<(reinterpret_cast<char *>(gameWon), sizeof(gameWon))<<endl; 
    outBin<<(reinterpret_cast<char *>(gameLost), sizeof(gameLost))<<endl; 
    //    outBin<<(reinterpret_cast<char *>(player->net), sizeof(player->net));   // couldn't figure out how to write this in binary 
    outBin.close(); 
    
    //Delete new memory

    delete[] cards;
    delete player;

    return 0;
}


int *fillCards(const int standard[],const int decks, int& sizeCards) {
    
        sizeCards=decks*52;       // size of array
    int *ary=new int[sizeCards];  // dynamic array creation
    int j=0;                                // counter for standard index
    for(int i=0; i<sizeCards; i++) {        // fill cards array
        if(j!=12) {
        ary[i]=standard[j];                 // keep going until one suit is filled
        j++;
        }
        else if(j==12) {
            ary[i]=standard[j];
            j=0;                            // reset if reach end one suit, move to next suit
        }
    }
    return ary;
}
void shuffle(int *cards, const int sizeCards) {
    for(int i=0; i<sizeCards; i++) {
        int random;
        int temp;
        int lowerBound=0;           // lowest array index
        int upperBound=sizeCards-1; // highest array index
        // generate a random number from lower to upper bound
        random=(rand()%(upperBound-lowerBound+1))+ lowerBound;
        temp=cards[i];
        cards[i]=cards[random];
        cards[random]=temp;
    }
}

void sum(vector<vector<int>> &deal,const int dealSize,int dealerHit, int playerHit, int sums[],int &loopSize) {
    sums[0]=0; 
    sums[1]=0;                     
    // size of the loop based on dealerHit or playerHit
    if(dealerHit>playerHit)      loopSize=dealerHit+dealSize; 
    else if(dealerHit<playerHit) loopSize=playerHit+dealSize;
    else if(dealerHit==playerHit)loopSize=dealerHit+dealSize; 
    
    for(int i=0; i<2; i++) {
        for(int j=0; j<loopSize; j++) {
        sums[i]+=deal[i][j];    
        }
    }
    for(int players=0; players<2; players++) {      // go thru each player
        int countAces=0;                                // reset count aces for each player
            for(int j=0; j<(loopSize); j++) {             // go thru each card
                if(deal[players][j]==1 || deal[players][j]==11) {       // initial sums don't get touched unless they have an ace
                    //check if 1 being 11 busts (ace = 1 or 11)
                    countAces++;  
                    int aceIndex=j; 
                    if(countAces>0) {
                        sums[players]-=deal[players][aceIndex];                 // subtract the 1
                        deal[players][aceIndex]=11; 
                        if(players==0) {
                            sums[players]+=deal[players][aceIndex];             // add 11 instead                             
                        } 
                        else if(players==1) {
                            sums[players]+=deal[players][aceIndex];             // add 11 instead
                            }
                        
                    if(sums[players]>21) {
                        sums[players]-=deal[players][aceIndex];                 // subtract the 11 that breaks 21
                        deal[players][aceIndex]=1;                              // revert the 11 back to one in the cards
                        sums[players]+=deal[players][aceIndex];                 //add 1 back
                    }
                }
            }
        }
    }
}


void check(const int dealSize, int sums[], Stats *player,int choice,int dealerChoice,bool &gameEnd,int &gameResult, unsigned int &gameLost, unsigned int &gameWon) {
    if(gameEnd==false) { 
        
        if(sums[0]==21 && sums[1]==21 && gameEnd==false) {
            cout<<"You and the dealer have tied for blackjack."<<endl;
            gameEnd=true; 
            gameResult=-1;
            }
        else if(sums[0]==21 && gameEnd==false) {
            cout<<"The dealer has won with a blackjack."<<endl;
            player->loss+=player->bet;
            cout<<"You lost $"<<player->bet<<endl; 
            gameEnd=true;
            gameResult=0; 
            gameLost++; 
            }
        else if(sums[1]==21 && gameEnd==false) {
            cout<<"You have won with a blackjack. Congratulations!"<<endl;
            player->win=2*(player->bet);
            cout<<"You won $"<<player->win<<endl; 
            gameEnd=true;
            gameResult=1; 
            gameWon++;
        }

        //next: did they bust? 
        for(int players=0; players<2; players++) {
            if(sums[0]>21 && sums[1]>21 && gameEnd==false) {
                cout<<"Both of you went over 21! It's a tie!"<<endl; 
                gameEnd=true;
                gameResult=-1;
            }
            if(sums[players]>21 && gameEnd==false) {
                if(players==0 && gameEnd==false) {
                    player->win=2*player->bet; 
                    cout<<setprecision(2)<<fixed; 
                    cout<<"The dealer has busted. You won $"<<player->win<<endl;  
                    gameEnd=true; 
                    gameResult=1; 
                    gameWon++;
                }
                else if(players==1 && gameEnd==false) {
                    player->loss+=player->bet; 
                    cout<<setprecision(2)<<fixed; 
                    cout<<"You have busted. You lost $"<<player->loss<<endl; 
                    gameEnd=true;
                    gameResult=0; 
                    gameLost++; 
                }
            }
        } 
        //next: if they didn't bust, who's closer to 21? 
        int diffPlayer=0;         // differences from 21: player
        int diffDealer=0;         // differences from 21: dealer
        if(choice==0 && dealerChoice==0 && gameEnd==false) {
            diffDealer=21-(sums[0]); 
            diffPlayer=21-(sums[1]); 
            if(diffPlayer<diffDealer && gameEnd==false) {            // player was closer to 21
                player->win=2*player->bet; 
                cout<<setprecision(2)<<fixed; 
                cout<<"Congrats! You won $"<<player->win<<endl;
                gameEnd=true; 
                gameResult=1; 
                gameWon++;
            }
            else if(diffPlayer>diffDealer && gameEnd==false) {       // dealer was closer to 21 
                player->loss+=player->bet;
                cout<<setprecision(2)<<fixed; 
                cout<<"Aw, you lost $"<<player->loss<<endl; 
                gameEnd=true;
                gameResult=0; 
                gameLost++; 
            }
            else if(diffPlayer==diffDealer && gameEnd==false) {      // player and dealer tied
                cout<<"Dealer and Player tied with same sum of "<<sums[0]<<" and "<<sums[1]<<endl; 
                gameEnd=true; 
                gameResult=-1;
            }
        }
    }
    else if(gameEnd==true) {                                         // validation if something goes wrong
        player->net=player->win - player->loss; 
    } 
}
void dealing(vector<vector<int>> &deal,int cards[],int &loopSize,int &dealt,int dealerHit,int playerHit,const int dealSize) {
    if(dealerHit>playerHit)      loopSize=dealerHit+dealSize; 
    else if(dealerHit<playerHit) loopSize=playerHit+dealSize;
    else if(dealerHit==playerHit)loopSize=dealerHit+dealSize; 
    for(int i=0; i<2; i++) {            // only two players 
        for(int j=0; j<loopSize; j++) { // two cards inital deal
            while(cards[dealt]==0){     // make sure the card being dealt isn't one that's already been used
                dealt++; 
            }
            deal[i][j]=cards[dealt];    // go thru random card[] array
            cards[dealt]=0;             // set dealt card values to 0;
            dealt++;                    // increment dealt index
        }
    }
    
}
void display(vector<vector<int>> &deal, int loopSize,int sums[],bool gameEnd) {
    string names[2]={"Dealer","Player"}; 
    if(gameEnd==false) {
        //display dealer
        cout<<setw(12)<<left<<names[0]; 
        cout<<setw(12)<<left<<"hidden"; 
            for(int j=1; j<loopSize; j++) {
                cout<<setw(12)<<left<<deal[0][j]<<" "; 
            }
        cout<<endl; 
        //display player
        cout<<setw(12)<<left<<names[1]; 
        for(int j=0; j<loopSize; j++) {
            cout<<setw(12)<<left<<deal[1][j]<<" "; 
        }
        
        cout<<" is at "<<sums[1]<<endl; 
        
    } 
    
    else if(gameEnd==true) {
        cout<<"\nDisplaying cards after game has ended."<<endl; 
        for(int i=0; i<2; i++) {
            cout<<setw(10)<<left<<names[i]; 
                for(int j=0; j<loopSize; j++) {
                    cout<<setw(5)<<left<<deal[i][j]<<" ";
                }
            cout<<" is at "<<sums[i]<<"...\n"<<endl; 
        }  
    }    
}

void fillStandard(int standard[],fstream &inFile) {
    //open file
    inFile.open("deck.txt", ios::in); 
    
    //read in cards
    for(int i=0; i<13; i++) {
        inFile>>standard[i]; 
    } 
    
    //close file 
    inFile.close();    
}



