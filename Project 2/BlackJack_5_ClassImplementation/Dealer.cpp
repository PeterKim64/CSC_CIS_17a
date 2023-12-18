/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Dealer.cpp
 * Author: User
 * 
 * Created on December 11, 2023, 8:58 PM
 */
#include <iostream>
#include <cstdlib>
#include "Dealer.h"
#include "Deck.h"   // for friend function Dealer::shuffle();

using namespace std; 

Dealer::Dealer() {
    hit=true; 
    hitCount=0;
    dealt=0;
    loopSize=2;                         // starting hand size
    hand.resize(2,vector<int>(loopSize, 0));
    sums[0]=0;
    sums[1]=1;

}

void Dealer::setSize(Players& instance) {
    loopSize=2; 
    if(instance.getCount()>=hitCount) loopSize=2+instance.getCount(); 
    if(instance.getCount()<hitCount) loopSize=2+hitCount;
//    cout<<loopSize<<" from setSize"<<endl; 
}

void Dealer::deal(int* deck) {
    for(int i=0; i<2; i++) {            // only two players 
        for(int j=0; j<loopSize; j++) { // two cards inital deal
            while(deck[dealt]==0){     // make sure the card being dealt isn't one that's already been used
                dealt++; 
            }
            hand[i][j]=deck[dealt];    // go thru random card[] array
            deck[dealt]=0;             // set dealt card values to 0;
            dealt++;                    // increment dealt index
        }
        cout<<endl; 
    }
}
int* Dealer::shuffle(int* deck,Deck &d) {
     for(int i=0; i<d.getDeckSize(); i++) {
        int random;
        int temp;
        int lowerBound=0;           // lowest array index
        int upperBound=d.getDeckSize(); // highest array index
        // generate a random number from lower to upper bound
        random=(rand()%(upperBound-lowerBound+1))+ lowerBound;
        temp=deck[i];
        deck[i]=deck[random];
        deck[random]=temp;
    }
     return deck;
}
void Dealer::setSums() {
    sums[0]=0;
    sums[1]=0; 
    for(int i=0; i<2; i++) {
        for(int j=0; j<loopSize; j++) {
        sums[i]+=hand[i][j];    
        }
    }
    for(int players=0; players<2; players++) {      // go thru each player
        int countAces=0;                                // reset count aces for each player
            for(int j=0; j<(loopSize); j++) {             // go thru each card
                if(hand[players][j]==1 || hand[players][j]==11) {       // initial sums don't get touched unless they have an ace
                    //check if 1 being 11 busts (ace = 1 or 11)
                    countAces++;  
                    int aceIndex=j; 
                    if(countAces>0) {
                        sums[players]-=hand[players][aceIndex];                 // subtract the 1
                        hand[players][aceIndex]=11; 
                        if(players==0) {
                            sums[players]+=hand[players][aceIndex];             // add 11 instead                             
                        } 
                        else if(players==1) {
                            sums[players]+=hand[players][aceIndex];             // add 11 instead
                            }
                        
                    if(sums[players]>21) {
                        sums[players]-=hand[players][aceIndex];                 // subtract the 11 that breaks 21
                        hand[players][aceIndex]=1;                              // revert the 11 back to one in the cards
                        sums[players]+=hand[players][aceIndex];                 //add 1 back
                    }
                }
            }
        }
    }
}

void Dealer::showHand() {
//    cout<<loopSize<<" loopsize within show hand."<<endl; 
    for(int i=0; i<2; i++) {
        if(i==0) cout<<"Dealer:    "; 
        if(i==1) cout<<"Player:    "; 
        for(int j=0; j<loopSize; j++) {
            cout<<hand[i][j]<<"    \t";  
        }
        cout<<"score: "<<sums[i]<<endl; 
    }
}
void Dealer::loopDeal(Players &player,Judge &judge,Dealer & dealer,int* cards) {
    bool choice=0; 
    bool loopEnd=false; 
    while(player.getHit()==1 && sums[0]<21 && sums[1]<21 && loopEnd==false) {
        cout<<"Would you like to hit or stay? Press 0 to stay, 1 to hit."<<endl; 
        cin>>choice; 
        try{
            player.setHit(choice);
        }
        catch(invalidHit) {
            cout<<"Invalid choice, please try again."<<endl; 
        }
        player.setHit(choice);
        switch(choice) {
            case 0:
                cout<<"Player stays."<<endl; 
                choice=0; 
                break; 
            case 1: 
                cout<<"Player hits."<<endl; 
                player.setCount();                  // hit gets incremented
                cout<<player.getCount()<<" getcount player."<<endl; 
                cout<<loopSize<<" inside loop."<<endl; 
                while(cards[dealt]==0) dealt++;     // make sure the card being dealt isn't one that's already been used 
                hand[1][(player.getCount()+2)-1]=cards[dealt];
                
                cout<<"the card dealt was "<<cards[dealt]<<endl; 
                cards[dealt]=0; 
                dealt++;  
                choice=1;
                break; 
            default: 
                cout<<"Enter only a 0 or a 1."<<endl;  
                choice=1; 
                loopEnd=true; 
        }
    //Dealer hit or stay
              // validate the choice by player
        if(loopEnd==false) { 
            if(sums[0]<17) {
                cout<<"Dealer hits."<<endl;  
                hitCount++;                       // count hits of dealer to size 2d vector 
                while(cards[dealt]==0) dealt++;     // make sure the card being dealt isn't one that's already been used
                hand[0][(hitCount+2)-1]=cards[dealt];   // give a new card
                cards[dealt]=0;                     // set card values to 0
                dealt++;                            // move to the next index of cards
                hit=1;                     // dealer hits
    
        }
            else if(sums[0]>=17) {
                cout<<"Dealer stays."<<endl; 
               
                hit=0;             // dealer stops. if player stays then stop loop 
            }
        setSize(player); 
        setSums(); 
        showHand(); 
        checks(dealer,player);  //judge is brought into this class of dealer
         
        }
        loopEnd=false; 
    }
    while(sums[0]<17) {
        cout<<"Dealer hits after players stays."<<endl; 
        hitCount++; 
        while(cards[dealt]==0) dealt++;     // make sure the card being dealt isn't one that's already been used
        hand[0][(hitCount+2)-1]=cards[dealt++]; 
        cards[dealt]=0;  
        // checks sums again
        setSize(player);        //reset size 
        setSums();  
        // display again
        showHand(); 
    }
}
    




