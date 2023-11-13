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

//System Libraries
#include <cstdlib>      // exit()
#include <iostream>
#include <time.h>       // time for srand(time(0)); possibly also for runtime stat
#include <vector>       // holds the inital cards dealt and new hits
#include <iomanip>      // format
using namespace std;

//User Libraries

//Global Constants
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only
//Structures
struct Stats{
    float bet=0;                   // amount bet
    float win=0;                   // winnings
    float loss=0;                  // losses
};

//Function Prototypes
int *fillCards(const int [],const int,int&);           // creates array "cards" that holds values for deck of cards
void shuffle(int *,const int);                         // shuffles cards
void sum(vector<vector<int>> &,const int, int, int,int [],int&);  //sums cards in vector deal
void check(const int, int [], Stats *,int,int);                                           // checks if you got a blackjack or busted
void dealing(vector<vector<int>> &,int [],int &,int &,int,int,const int);                    // deals cards according to how big the vector is sized after hits or stays
void display(vector<vector<int>> &, int, int[]); 

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables or constants here
    Stats *player;                       // pointer to info on player
    const int standard[13]=
                            {1,2,3,4,5,6,7,8,9,10,10,10,10};                        // values for one suit of cards in a deck. 4 included in each deck
    int decks=1;                         // amount of decks to increase random chance. 1 minimum.
    int sizeCards=0;                     // size of cards array
    srand(time(0));                      // randomize seed using time for shuffling
    const int dealSize=2;                // initial deal is only two cards always 
    vector<vector<int>> deal(2,vector<int> (dealSize,0));   // 2d vector to hold each hand. rows are dealer/player, columns are cards
    int countAces=0;             // number of aces in each hand 
    int aceIndex;                // index where ace was found
    int sums[dealSize]={0,0};    // sums of each players hands [0] being dealer [1] being player
    int playerHit=0;             // counting the hits to resize vector
    int dealerHit=0;             //counter for dealer hitting
    int loopSize=0;             // size of loop when vector gets bigger based on player or dealer hits
    int choice=1;                     // hit or stay
    int dealerChoice=1;               // dealer hits or stays 
    int dealt=0;                // dealt cards are given a value of 0 to skip and go to next card
    
    //Initialize or input data here
    cout<<"This program runs a game of blackjack for 2 players, ";
    cout<<"the user and the dealer."<<endl;
    cout<<"Please enter how many decks you would like to use. (1-8)"<<endl;
    cin>>decks;
    //validate decks input
    if(decks>8) {
        cout<<"Please enter a range of decks from 1-8 decks."<<endl;
        exit(0);
    }
    //Dynamically Create Structure
    player=new Stats;
    cout<<"Please enter how much you'd like to bet for this hand."<<endl;
    cin>>player->bet;
    
    //validate bets
    if(player->bet<=0) {
        cout<<"Please enter a minimum bet above 0."<<endl; 
        exit(0); 
    }
    
    //Create cards array
    int *cards=fillCards(standard,decks,sizeCards);
    
    //Shuffle cards
    shuffle(cards,sizeCards);
    
    //Deal cards
    dealing(deal,cards,loopSize,dealt,dealerHit,playerHit,dealSize);
    
    //get sums of initial deal
    sum(deal,dealSize,dealerHit,playerHit,sums,loopSize); 
    
    //show cards
    display(deal,loopSize,sums);
    //check for natural blackjack
    check(dealSize,sums,player,choice,dealerChoice);

    //Hit or stay
    while(choice==1 && sums[0]<21 && sums[1]<21) {
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
                deal[1][(playerHit+dealSize)-1]=cards[dealt];
                cards[dealt]=0; 
                dealt++;  
                choice=1;
                break; 
            default: 
                cout<<"Enter only a 0 or a 1."<<endl;  
                break; 
        }
    //Dealer hit or stay
        if(sums[0]<17) {
            cout<<"Dealer hits."<<endl;  
            dealerHit++; 
            deal[0][(dealerHit+dealSize)-1]=cards[dealt];
            cards[dealt]=0; 
            dealt++; 
            dealerChoice=1;             // dealer hits, continue loop
    
        }
        else if(sums[0]>=17) {
            cout<<"Dealer stays."<<endl; 
            dealerChoice=0;             // dealer stops. if player stays then stop loop 
        }
    
    // checks sums again
        sum(deal,dealSize,dealerHit,playerHit,sums,loopSize); 
    
    // display new cards
        display(deal,loopSize,sums);
    }
    //while loop ends when either player stops hitting or busts. sometimes dealer still hits so this accounts for that
    while(sums[0]<17) {
        cout<<"Dealer hits after players stays."<<endl; 
        dealerHit++; 
        deal[0][(dealerHit+dealSize)-1]=cards[dealt++]; 
        cards[dealt]=0;  
        // checks sums again
        sum(deal,dealSize,dealerHit,playerHit,sums,loopSize); 
    }
    //while loop ends now check conditions: did they hit blackjack or bust? 
    check(dealSize,sums,player,choice,dealerChoice); 
    
    //write everything to a file
    
    //Output

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
                        deal[players][aceIndex]=11; 
                        if(players==0) {
                            sums[0]+=10; 

                        } 
                        else if(players==1) {
                            sums[1]+=10; 
                        }
                    if(sums[players]>21) {
                        sums[players]-=10;              // if an ace busts the hand, revert by subtracting 10.
                        deal[players][aceIndex]=1;      // revert the 11 back to one in the cards

                    }   
                }
            }
        }
    }
}


void check(const int dealSize, int sums[], Stats *player,int choice,int dealerChoice) {
    if(sums[0]==21 && sums[1]==21) {
        cout<<"You and the dealer have tied for blackjack."<<endl;
        exit(0); 
        }
    else if(sums[0]==21) {
        cout<<"The dealer has won with a blackjack."<<endl;
        player->loss+=player->bet;
        cout<<"You lost $"<<player->bet; 
        exit(0); 
        }
    else if(sums[1]==21) {
        cout<<"You have won with a blackjack. Congratulations!"<<endl;
        player->win=2*(player->bet);
        cout<<"You won $"<<(player->win)<<endl; 
        exit(0); 
    }
    
    //next: did they bust? 
    for(int players=0; players<2; players++) {
        if(sums[0]>21 && sums[1]>21) {
            cout<<"Both of you went over 21! It's a tie!"<<endl; 
        }
        if(sums[players]>21) {
            if(players==0) {
                player->win=2*player->bet; 
                cout<<setprecision(2)<<fixed; 
                cout<<"The dealer has busted. You won $"<<player->win<<endl;  
                exit(0); 
            }
            else if(players==1) {
                player->loss+=player->bet; 
                cout<<setprecision(2)<<fixed; 
                cout<<"You have busted. You lost$"<<player->loss<<endl; 
                exit(0); 
            }
        }
    } 
    int diffPlayer=0;              // difference from 21; lower person wins. 
    int diffDealer=0; 
    if(choice==0 && dealerChoice==0) {
        diffDealer=21-(sums[0]); 
        diffPlayer=21-(sums[1]); 
        if(diffPlayer<diffDealer) {
            player->win=2*player->bet; 
            cout<<setprecision(2)<<fixed; 
            cout<<"Congrats! You won $"<<player->win<<endl;
            exit(0); 
        }
        else if(diffPlayer>diffDealer) {  
            player->loss+=player->bet;
            cout<<setprecision(2)<<fixed; 
            cout<<"Aw, you lost $"<<player->loss<<endl; 
            exit(0); 
        }
        else if(diffPlayer==diffDealer) {
            cout<<"Dealer and Player tied with same sum of "<<sum[0]<<" and "<<sum[1]<<endl; 
            exit(0); 
        }
    }
}
void dealing(vector<vector<int>> &deal,int cards[],int &loopSize,int &dealt,int dealerHit,int playerHit,const int dealSize) {
    if(dealerHit>playerHit)      loopSize=dealerHit+dealSize; 
    else if(dealerHit<playerHit) loopSize=playerHit+dealSize;
    else if(dealerHit==playerHit)loopSize=dealerHit+dealSize; 
    for(int i=0; i<2; i++) {            // only two players 
        for(int j=0; j<loopSize; j++) { // two cards inital deal
            deal[i][j]=cards[dealt];    // go thru random card[] array
            cards[dealt]=0;             // set dealt card values to 0;
            dealt++;                    // increment dealt index
        }
    }
    
}
void display(vector<vector<int>> &deal, int loopSize,int sums[]) {
    string names[2]={"Dealer","Player"};  
    for(int i=0; i<2; i++) {
        cout<<setw(10)<<left<<names[i]; 
        for(int j=0; j<loopSize; j++) {
            cout<<setw(5)<<left<<deal[i][j]<<" ";
        }
        cout<<" is at "<<sums[i]<<"..."<<endl; 
    }
    
}



