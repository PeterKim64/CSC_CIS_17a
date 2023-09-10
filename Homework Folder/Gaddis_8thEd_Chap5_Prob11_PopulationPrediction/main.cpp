/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: User
 * Date: September 10, 2023
 * Purpose: Predict Population based on input days and starting point
 * Created on September 10, 2023, 1:55 PM
 */

//System Libraries
#include <cstdlib>
#include<iostream>
#include<iomanip>
using namespace std;

//User Libraries

//Global Constants
//Only Universal Physics/Math/Conversions found here
//No Global Variables 
//Higher Dimension arrays requiring definition prior to prototype only 

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables or constants here
    float days; 
    int startingPop;                // starting population
    float percentInc;               // percent increase per day 
    int dailyInc;                 // population increase per day

    
    //Initialize or input data here
    cout<<"Please enter starting number of organisms."<<endl; 
    cin>>startingPop; 
    
    cout<<"Please enter average daily population increase. (percentage)"<<endl; 
    cin>>percentInc;
    
    cout<<"Please enter amount of days the population will be increasing."<<endl;  
    cin>>days; 
    
    //Process 
    if (days<1)
        cout<<"Please enter a valid input for days. (At least above 1)";
    else if (percentInc<0)
        cout<<"Please enter a valid input for percent increase. (positive)"; 
    else if (startingPop<2)
        cout<<"Please enter a valid input for starting population. (At least 2)";
    else {          
    //Output
        percentInc=percentInc/100;              // turn input into a decimal %
        for (int i=1; i<=days; i++) {
            cout<<"Day "<<i<<": "<<startingPop<<endl; 
            dailyInc=startingPop*percentInc; 
            startingPop+=dailyInc; 
        }
    }
    
     
    return 0;
}


