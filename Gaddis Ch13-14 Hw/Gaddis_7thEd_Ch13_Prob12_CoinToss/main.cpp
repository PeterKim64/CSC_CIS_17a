/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Created on December 4, 2023, 3:04 PM
 * Purpose: Create a coin toss simulation using Coin class
 */

//System Libraries
#include <cstdlib>
#include<iostream>
#include<time.h>
#include "Coin.h"
using namespace std;

//User Libraries

//Global Constants
//Only Universal Physics/Math/Conversions found here
//No Global Variables 
//Higher Dimension arrays requiring definition prior to prototype only 

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random seed here
    srand(time(0));
    //Declare variables or constants here
    int heads=0;             // accumulate wins and losses
    int tails=0; 
    string result="";           // result of toss
    Coin c; 
    Coin b; 
    
    //Initialize or input data here
    cout<<"Initial side that coin is facing."<<c.getSideUp()<<endl;  
    for(int i=0; i<20; i++) {
        c.toss();  
        result=c.getSideUp(); 
        if(result=="heads") 
            heads++; 
        else if(result=="tails")
            tails++; 
    }

    
    //Output
    cout<<"This program runs a coin toss simulation for 20 iterations."<<endl; 
    cout<<"Number of heads: "<<heads<<endl; 
    cout<<"Number of tails: "<<tails<<endl; 
    return 0;
}



