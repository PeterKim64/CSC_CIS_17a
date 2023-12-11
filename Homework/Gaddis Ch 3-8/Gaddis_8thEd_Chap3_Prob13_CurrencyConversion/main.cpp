/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Date: September 9, 2023
 * Purpose: Convert U.S. Dollars into Japanese Yen and European Euro
 * Created on September 9, 2023, 3:28 PM
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
    const float YEN_PER_DOLLAR=147.78; 
    const float EUROS_PER_DOLLAR=0.93;
    float dollar;
    float resultYen; 
    float resultEuro; 

    //Initialize or input data here
    cout<<"Please enter an amount of U.S. dollars you would like to convert "
        <<"into Yen and Euros. " <<endl; 
    cin>>dollar; 
    //Process 
    if(dollar>=0) {                     // how do I validate only 2 decimals? 
        resultYen=dollar * YEN_PER_DOLLAR; 
        resultEuro=dollar * EUROS_PER_DOLLAR;   
        
        //Output 
        cout<<"$"<<setprecision(2)
        <<showpoint<<fixed<<dollar<<" is equivalent to "
        <<showpoint<<fixed<<resultYen<< " Yen and "
        <<showpoint<<fixed<<resultEuro<<" Euros."; 
    }
    else if (dollar<0) {
        cout<<"Invalid input, please enter only positive numbers."<<endl; 
    }
     
    return 0;
}

