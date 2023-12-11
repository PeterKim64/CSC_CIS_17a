/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 *
 * Created on December 10, 2023, 2:57 PM
 */

//System Libraries
#include <cstdlib>
#include<iostream>
#include "ProductionWorker.h"
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
    ProductionWorker a; 
    string name;            // employee name
    unsigned int number;    // employee number
    string date;            // date hired
    int s;                  //shift
    float r;                // rate
    //Initialize or input data here
    cout<<"Please input employee name, number, and date hired in (m/d/y)."<<endl; 
    getline(cin,name); 
    cin>>number; 
    cin.ignore(); 
    getline(cin,date); 
    cout<<"Now enter 1 for day shift, 2 for night shift. Then enter hourly rate."<<endl; 
    cin>>s>>r; 
    //set to class
    a.setName(name); 
    a.setNum(number); 
    a.setDate(date);
    a.setShift(s); 
    a.setRate(r); 
    
    //Output
    cout<<a.getName()<<endl;  
    cout<<a.getNum()<<endl;  
    cout<<a.getDate()<<endl; 
    cout<<a.getShift()<<endl;  
    cout<<a.getRate();

    return 0;
}

