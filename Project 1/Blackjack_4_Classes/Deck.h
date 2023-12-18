/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   deck.h
 * Author: User
 *
 * Created on December 11, 2023, 2:45 PM
 */
#include <fstream> 
#include <iostream>
using namespace std; 

#ifndef DECK_H
#define DECK_H

class Deck {
private:
    static int standard[13];  // array to hold standard card values for one suit
    static int fiftytwo;      // size of one deck of cards
    int deckSize;             // deck of deck depending on how many decks used
    int *cards;               // array that holds all values for all suits
public: 
    Deck();         // default constructor
    ~Deck();        // destructor for deck array 
    //Setters
    void setStandard(fstream &); 
    void setDeckSize(int); 
    void setCards(); 
    //Getters
    int getDeckSize() const {
        return deckSize; 
    }
    int* getCards() const {
        return cards; 
    }
};
//Static Variable Initialization
int Deck::standard[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
int Deck::fiftytwo=52; 

#endif /* DECK_H */

