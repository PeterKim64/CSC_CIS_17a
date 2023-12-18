/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Players.h
 * Author: User
 *
 * Created on December 11, 2023, 3:38 PM
 */
#include <iostream>
#include <vector>
using namespace std;

#ifndef PLAYERS_H
#define PLAYERS_H


class Players {
private:
    string name;
    float bet; 
    float win;
    float loss;
    float net;
protected:
    int hitCount;    // amount of times player has hit
    bool hit;        // choose to hit or stay. 
    vector<int> hand; 
public:
    //Default constructor
    Players() {
    name=""; 
    bet=0.0;
    win=0.0;
    loss=0.0;
    net=0.0;
    hitCount=0;
    hit=true;
    }
    //Constructor #2
    Players(string,float,float,float,float,bool); 
    //Exception cases
    class invalidBet{};       // invalid bet catch type
    class invalidHit{};       // invalid hit catch type
    //Setters
    void setName(string n) {name=n;} 
    void setBet(float b);
    void setWin(float w) {win=w;} 
    void setLoss(float l) {loss=l;} 
    void setNet() {net=win-loss;}
    void setHit(bool h); 
    void setCount(); 
    //Getters
    string getName() const {return name;}
    float getBet() const   {return bet;}
    float getWin() const   {return win;}
    float getLoss() const  {return loss;}
    float getNet() const   {return net;}
    bool getHit() const    {return hit;}
    int getCount() const   {return hitCount;}
    
};

#endif /* PLAYERS_H */

