/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Players.cpp
 * Author: User
 * 
 * Created on December 11, 2023, 3:38 PM
 */

#include "Players.h"

Players::Players(string n,float b,float w,float l,float netEarn,bool h) {
    name=n; 
    if(b<1)  throw invalidBet();       // exception throw for bet
    if(b>=1) bet=b;                    // else input is valid
    win=w;
    loss=l;
    net=netEarn;             //else input is valid
}
void Players::setBet(float b) {
    if(b<1)  throw invalidBet();       // exception throw for bet
    if(b>=1) bet=b;                    // else input is valid    
}
void Players::setHit(bool h) { 
    if(h>1 || h<0) throw invalidHit(); //exception throw for hit 
    else if(h==1||h==0) hit=h;              //else input is valid
    else cout<<"didn't work, setHit in player class."<<endl; 
}
void Players::setCount() {
    if(hit==true) hitCount++;
}




