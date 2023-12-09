/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Purpose: Create a Date Class 
 * Created on November 20, 2023, 5:13 PM
 */

/* Description: Design a class called "Date". Holds three ints: month, day
 * and year. It prints in three different formats: 
 * 12/25/2012
 * December 25, 2012
 * 25 December 2012
 * Write a complete program using the date class
 */

#include <cstdlib>
#include <iostream>
#include "Date.h"       // needed for Date class
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
    Date date;              //instantiation of date class 
    int m,
        d,
        y;                  // local variables for month, day and year. 
    
    //Initialize or input data here
    cout<<"Please enter a date in this order: Month Day Year."<<endl; 
    cin>>m>>d>>y; 
    
    //Setter functions for date
    date.setMonth(m); 
    date.setDay(d); 
    date.setYear(y); 
    
    //echo back using the getter functions
//    cout<<date.getMonth()<<endl;  
//    cout<<date.getDay()<<endl; 
//    cout<<date.getYear()<<endl;
    
    //Output
    date.display1();
    date.display2(); 
    return 0;
}

