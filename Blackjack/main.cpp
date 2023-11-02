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
using namespace std;

//User Libraries

//Global Constants
//Only Universal Physics/Math/Conversions found here
//No Global Variables 
//Higher Dimension arrays requiring definition prior to prototype only 
//Structures
struct Stats{
    int bet;                    // amount bet
    int win;                    // winnings
    int loss;                    // net money lost or won
    int net; 
};

//Function Prototypes
int *fillCards(const int [],const int, int *, int&); 
void shuffle(int *, const int); 

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables or constants here
    Stats *player;                       // pointer to info on player
    const int standard[13]=
                            {1,2,3,4,5,6,7,8,9,10,10,10,10};                        // values for one suit of cards in a deck. 4 included in each deck 
    int decks=1;                         // amount of decks to increase random chance. 1 minimum. 
    int *ary;                            // array to hold the cards
    int sizeCards=0;                     // size of cards array 
    srand(time(0));                      // randomize seed using time for shuffling                    
    vector<vector<int>> deal(2,vector<int> (2,0));
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
    //Create cards array 
    int *cards=fillCards(standard,decks,ary,sizeCards); 
    //Shuffle cards 
    shuffle(cards,sizeCards); 
    //Deal cards
    int dealt=0; 
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            deal[i][j]=cards[dealt];    // go thru random card[] array
            cards[dealt]=0;             // set dealt card values to 0; 
            dealt++;                    // increment dealt index
        } 
    }
    
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            cout<<deal[i][j]<<" "; 
        }
        cout<<endl; 
    }
    
    int sum[2]; 
    //check for aces
//    for(int i=0; i<2; i++) {
//        for(int j=0; j<2; j++) {
//            if(deal[i][j]==1) {
//                //check if 1 being 11 busts
//                deal[i][j]=11; 
//                sum[0]=deal[0][0]+deal[0][1];          // check dealer
//                sum[1]=deal[1][0]+deal[1][1];          // check player
//                cout<<"sum"<<i<<" is now "<<sum[i]<<endl; 
//            }
//        }
//    }
//    
    //check for natural blackjack
//    if(sum[0]==21 && sum[1]==21) {
//        cout<<"You and the dealer have tied for blackjack."<<endl; 
//        }
//    else if(sum[0]==21) {
//        cout<<"The dealer has won with a natural blackjack."<<endl; 
//        player->loss-=player->bet; 
//        cout<<"You lost $"<<player->bet; 
//        }
//    else if(sum[1]==21) {
//        cout<<"You have won with a natural blackjack. Congratulations!"<<endl;
//        player->win+=(player->bet *1.5); 
//        cout<<"You won $"<<(player->bet*1.5); 
//    }
    
    //Display cards given
    cout<<"Why is this program not ending..."<<endl; 
    
    
 
////    /*
//     * idea: 2d array. columns of how many players
//     *                 rows with amount of cards. would have to resize for every hit. 
//     *                 consider using a vector in this scenario
//     * do while player hand <21 continue dealing
//     * stops when 21 or over 21 happens, use if else for win or loss
//     * 
//     * within the loop, have to validate every time another card is dealt. 
//     * first check if initial hand is 21. sum the two. if a '1' is dealt, check
//     * to see if an 11 gives a blackjack. only case for this is 1 and 10, so
//     * consider using a switch. however, the 1 changes depending whether it busts
//     * the player or not once the third card+ is dealt, so make an algorithm for
//     * that. something like, if 1 is dealt, do check(); temp has array1=array11; 
//     * if array11 <21, use 11. if array11=21, win. if array11>21, array11=array1. 
//     * 
//     * will this game take input from every user? ask professor. 
//     * 
//     * dealer will follow algorithm according to best statistics. figure that 
//     * out online. 
//     * remember to pay out if win, lose out if loss. consider inputting initial
//     * balance, so you can have net win/losses, or have infinite money.  
//     */
//    
    
    
    
    //Output
    
    //Delete new memory
    delete[] cards; 
    delete[] ary; 
    delete player; 
    return 0;
}

int *fillCards(const int standard[],const int decks, int *ary, int& sizeCards) {
        sizeCards=decks*52;       // size of array        
    ary=new int[sizeCards];  // dynamic array creation
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


