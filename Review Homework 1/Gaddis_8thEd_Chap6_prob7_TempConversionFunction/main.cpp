/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Date: September 10, 2023
 * Purpose: Fahrenheit to Celsius using a function
 * Created on September 10, 2023, 3:26 PM
 */

//System Libraries
#include <cstdlib>
#include<iostream>
#include<iomanip>
using namespace std;

//User Libraries

//Global Constants
//Only Universal Physics/Math/Conversions found here
const float CONVRATIO=5.0/9.0;      //constant ration in conversion rate*
const int CONVCONST=32;             //constant in conversion rate*

//* Formula from Fahrenheit to Celsius is (5/9) * (Fahrenheit-32) 

//No Global Variables 
//Higher Dimension arrays requiring definition prior to prototype only 

//Function Prototypes
void celsius(float, int); 
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables or constants here
    float celsiusOutput; 
    int count=0; 
    
    //Initialize or input data here
    for(count; count<=20; count++)
    celsius(celsiusOutput, count); 

    return 0;
}
 // makes a table from Fahrenheit to Celsius
void celsius(float celsiusOutput, int count) {      
        celsiusOutput=CONVRATIO*(count-CONVCONST);       // Calculate conversion
        cout<<count<<" degrees Fahrenheit is "<<fixed    // Output with format
            <<setprecision(2)<<celsiusOutput<<" degrees Celsius."<<endl;  
}

