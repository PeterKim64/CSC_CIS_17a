/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Date: September 8, 2023
 * Purpose: Convert Celsius to Fahrenheit 
 * Created on September 8, 2023, 6:05 PM
 */

//System Libraries
#include <cstdlib>
#include<iostream>
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
    float celsius, fahrenheit; 
    
    //Initialize or input data here
    cout<<"Input a temperature in degrees Celsius."<<endl; 
    cin>>celsius; 
    //Process degrees Celsius into Fahrenheit
    fahrenheit= 1.8 * celsius + 32;             // conversion from Celsius into Fahrenheit 
   
    //Output
    cout<<celsius<<" degrees Celsius in degrees Fahrenheit is "<<fahrenheit<<endl;  
    return 0;
}
