/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: User
 *
 * Created on December 11, 2023, 3:38 PM
 */

#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <time.h>           //set random time seed
#include "Players.h"
#include "Deck.h"
#include "Dealer.h"
#include "Judge.h"
using namespace std;

/*
 * 
 */
struct Stats{
    string name;                   // player name
    float bet=0;                   // amount bet
    float win=0;                   // winnings
    float loss=0;                  // losses
    float net=0;                   // net money
};

int main(int argc, char** argv) {
    //Set random seed 
    srand(time(0)); 
    //Declare Variables Here
    int decks=1; 
    bool validInput=false;
    int gameResult=3;          // -1 tie, 0 lose, 1 win, 3 game running
    //Struct and class instantiation
    Stats info; 
    Players one;
    Deck card;
    Dealer dealer; 
    Judge judge; 
    //Dynamically create structure
    
    //Input dialogue
    cout<<"This program runs a game of blackjack for 2 players, ";
    cout<<"the user and the dealer."<<endl;
    cout<<"Please enter your name."<<endl; 
    getline(cin,info.name);
    one.setName(info.name); 
    cout<<"Please enter how many decks you would like to use. (1-8)"<<endl;
    cin>>decks;
    //Validate decks input
    while(validInput==false) {
        try{
            card.setDeckSize(decks);
            validInput=true;
        }
        catch(Deck::invalidDecksUsed) {
            cout<<"Invalid decks input. Please try again."<<endl; 
            cin>>decks; 
        }

        
    }
    //ask for bet amount
    cout<<"Please enter how much you'd like to bet for this hand."<<endl;
    cin>>info.bet; 
    validInput=false; 
    while(validInput==false) {
        try{
           one.setBet(info.bet);
           validInput=true; 
        }
        catch(Players::invalidBet) {
           cout<<"Invalid bet input. Please try again."<<endl; 
           cin>>info.bet; 
        }
    }

    //fill standard array
    card.setCards();
    int *deck=card.getCards();      // deck pointer now points to cards array
    //echo back un-shuffled deck
//    for(int i=0; i<card.getDeckSize();i++) {
//        cout<<deck[i]<<" "; 
//    }
//    cout<<endl; 
    //Dealer shuffles cards
    deck=dealer.shuffle(deck,card);
    //echo back shuffled deck 
//    for(int i=0; i<card.getDeckSize();i++) {
//        cout<<deck[i]<<" "; 
//    }
//    cout<<endl; 
    //Deal cards
    dealer.deal(deck);  //I love this line. You can really see the classes working to make the coding readable. Simply, dealer deals deck. 
    //sum the cards and check to see if one hit a blackjack off the go
    dealer.setSize(one);
    dealer.setSums();  
    //judge checks sums
    gameResult=judge.checks(dealer,one);
    dealer.showHand(); 
    dealer.showSums(); 
    //continue running if game doesn't end 
    while (gameResult==3) {
        dealer.loopDeal(one,judge,deck); 
        gameResult=judge.checks(dealer,one);      
    }
    
//    dealer.setSize(one); 
//    judge.checks(dealer,one); 
//    dealer.showHand(); 
//    dealer.showSums(); 
    
    
    return 0;
}

