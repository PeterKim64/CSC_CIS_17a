/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Deck.h
 * Author: User
 *
 * Created on December 11, 2023, 4:16 PM
 */

#include <fstream> 
#include <iostream>
#include <cstdlib>
#include <string>
#include "Dealer.h"       //for declaration of friend function "Dealer::shuffle"
using namespace std; 

#ifndef DECK_H
#define DECK_H


class Deck {
private:
    static int standard[13]; // array to hold standard card values for one suit
    int *cards;              // array that holds all values for all suits

protected:                   //pass these into dealer class, therefore protected
    static int fiftytwo;     // size of one deck of cards 
    int deckSize;            // deck of deck depending on how many decks used
public: 
    Deck();         // default constructor
    ~Deck();        // destructor for deck array 
    //Exceptions
    class invalidDecksUsed{}; 
    //Setters 
    void setDeckSize(int); 
    void setCards(); 
    //Getters
    int getDeckSize() const {
        return deckSize; 
    }
    int* getCards() const {
        return cards; 
    }
    //friend
    friend int* Dealer::shuffle(int*,Deck &);
};


#endif /* DECK_H */

