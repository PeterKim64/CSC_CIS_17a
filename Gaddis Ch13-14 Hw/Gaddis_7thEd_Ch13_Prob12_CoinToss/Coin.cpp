/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Coin.cpp
 * Author: User
 * 
 * Created on December 4, 2023, 3:05 PM
 */

#include "Coin.h"
#include <iostream>
using namespace std; 


Coin::Coin () {
    int side; 
    side=rand()%2+1; 
    if(side==1)
        sideUp="tails"; 
    else if(side==2)
        sideUp="heads"; 
    else
        cout<<"Something went wrong with tossing in constructor."<<endl; 
}
void Coin::toss() {
    int toss; 
    toss=rand()%2+1; 
    if(toss==1)
        sideUp="tails"; 
    else if(toss==2)
        sideUp="heads"; 
    else
        cout<<"Something went wrong with tossing."<<endl; 
}

string Coin::getSideUp() const{
    return sideUp; 
}





