/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Deck.cpp
 * Author: User
 * 
 * Created on December 11, 2023, 4:16 PM
 */

#include "Deck.h"
using namespace std; 

//Static Variable Initialization
int Deck::standard[13]={1,2,3,4,5,6,7,8,9,10,10,10,10};
int Deck::fiftytwo=52; 

Deck::Deck() {  //default constructor
    deckSize=fiftytwo; 
}
//Calculate and validate size of array to hold the cards
void Deck::setDeckSize(int decksUsed) { //get deckSize by multiplying decks used by 52
    if(decksUsed<1 || decksUsed>8) throw invalidDecksUsed(); 
    deckSize=decksUsed*fiftytwo; 
}
//Set the cards[] using the standard values array
void Deck::setCards() { //dynamically create cards array and fill using standard
        cards = new int[deckSize];
    int j=0;                               // counter for standard index
    for(int i=0; i<deckSize; i++) {        // fill cards array
        if(j!=12) {
        cards[i]=standard[j];              // keep going until one suit is filled
        j++;
        }
        else if(j==12) {
            cards[i]=standard[j];
            j=0;                           // reset if reach end one suit, move to next suit
        }
    }
}
//destroy dynamically created memory using destructor
Deck::~Deck() { 
    delete []cards;
}

