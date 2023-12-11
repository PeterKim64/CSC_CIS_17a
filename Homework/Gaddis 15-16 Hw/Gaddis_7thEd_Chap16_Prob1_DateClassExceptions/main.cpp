/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: User
 *
 * Created on December 9, 2023, 5:21 PM
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
    bool tryAgain=true; 
    
    //Initialize or input data here
    cout<<"Please enter a date in this order: Month Day Year."<<endl; 
    cin>>m>>d>>y;    
    //Use exceptions to error catch while setting month and day 
    while(tryAgain==true) {
        try {
            date.setMonth(m); 
            date.setDay(d); 
            tryAgain=false;             // if no exception is thrown, this statement will be read and end the while loop. 
        }
        catch (Date::invalidMonth) {
            cout<<"Invalid month input. Try again."<<endl; 
            cin>>m; 
                }
        catch (Date::invalidDay) {
            cout<<"Invalid day input. Try again."<<endl; 
            cin>>d; 
        }    
    } 
    
    
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
