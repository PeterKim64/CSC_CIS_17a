/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   deck.cpp
 * Author: User
 * 
 * Created on December 11, 2023, 2:45 PM
 */
#include "standardValues.txt"
#include "Deck.h"
#include <fstream>
using namespace std; 

Deck::Deck() {  //default constructor
    deckSize=fiftytwo; 
    cards=NULL; 
}
void Deck::setStandard(fstream& inFile) {   //read in standard  values from file
    //open file
    inFile.open("standardValues.txt", ios::in);     
    //read in cards
    for(int i=0; i<13; i++) {
        inFile>>standard[i]; 
    } 
    //close file 
    inFile.close(); 
}
void Deck::setDeckSize(int decksUsed) { //get deckSize by multiplying decks used by 52
    deckSize=decksUsed*fiftytwo; 
}
void Deck::setCards() { //dynamically create cards array and fill using standard
    cards=new int[deckSize]; 
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

int Deck::getDeckSize() const{
    return deckSize;
}
int* Deck::getCards() const{
    return cards; 
}

Deck::~Deck() {
    delete []cards;
}


