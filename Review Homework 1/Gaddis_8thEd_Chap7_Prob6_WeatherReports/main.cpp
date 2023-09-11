/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: User
 * Date: September 10, 2023
 * Purpose: Output Weather Reports from a text file
 * Created on September 10, 2023, 4:23 PM
 */


#include <fstream>
#include <iostream>
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
    ifstream inFile; 
    const int MONTHS=3; 
    const int DAYS=30; 
    char monthDays[MONTHS][DAYS]; 

    //Initialize or input data here
    inFile.open("RainOrShine.txt");
    for(int i=0; i<MONTHS; i++) { 
        for(int j=0; j<DAYS; j++) {
            inFile>>monthDays[i][j];
            cout<<monthDays[i][j]<<"  ";  
        } 
         
    }
 
    //Process 
   
    //Output
     
    return 0;
}

