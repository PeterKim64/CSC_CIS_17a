/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Dealer.h
 * Author: User
 *
 * Created on December 11, 2023, 8:58 PM
 */

#ifndef DEALER_H
#define DEALER_H
#include <vector>       // for hand
#include "Players.h"    // for inheritence
#include "Judge.h"      // for judge friend function
class Deck; 

class Dealer : public Players, public Judge { //dealer is a player
    private:
        int loopSize;
        int dealt;      //dealer keeps track of dealt cards
        int sums[2]; 
protected:
    vector<vector<int>> hand;           // dealer holds both hands for functionality's sake
public:
    Dealer();   //No copy constructor for *cards since dealer should be able to change cards[] directly
    //setters 
    void setSize(Players&);
    /*Idea for further functionality: Create a virtual function "deal" in base
     class that takes n player instances created in base class. Then increment
     or decrement list in Dealer class function "deal" so that you can deal
     to any amount of players specified. Not yet implemented.*/
    void deal(int*);     //Dealer can deal a hand to one instance of players
    void showHand(); 
    void setSums();
    void showSums() {
        cout<<endl<<"sums"<<endl;
        cout<<loopSize<<" within showSums."<<endl; 
        cout<<sums[0]<<endl; 
        cout<<sums[1]<<endl; 
    }
    //getters
    int getSize() const {return loopSize;}   
    int* shuffle(int*,Deck &);  //function friend of 'Deck' who can now shuffle, 
                                //returns the cards it was first given
    int* getSums() {return sums;}
    //process
    void loopDeal(Players&,Judge&,Dealer&,int*); 
    friend int checks(Dealer &,Players &);      // gets sums from dealer

    //Friends 
    
};

#endif /* DEALER_H */

