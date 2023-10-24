/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: User
 * Created on October 23, 2023, 6:32 PM
 * Purpose: Find biggest n! held in each data type
 * 
 * Comments: I was pretty confused on what you wanted us to give you for this 
 * program so I just cout the numbers I got after investigating on paper. 
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>          // strings, strcpy, strlen
#include <string>           // c_str()
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
    
    //Initialize or input data here
    //Output
    cout<<"Largest n! that can be held in each data type."<<endl; 
    
    cout<<setw(45)<<left<<"char range: 0 to 305 or -127 to 127. ";
    cout<<setw(30)<<right<<"n!=5!=120"<<endl;
    
    cout<<setw(45)<<left<<"unsigned char range: 0 to 305. ";
    cout<<setw(30)<<right<<"n!=5!=120"<<endl; 
    
    cout<<setw(45)<<left<<"signed char range:-127 to 127. ";
    cout<<setw(30)<<right<<"n!=5!=120"<<endl;
    
    cout<<setw(45)<<left<<"int range: -2147483648 to 2147483648. ";
    cout<<setw(30)<<right<<"n!=12!=479,001,600"<<endl;
    
    cout<<setw(45)<<left<<"unsigned int range: 0 to 4294967295. ";
    cout<<setw(30)<<right<<"n!=12!=479,001,600"<<endl;
    
    cout<<setw(45)<<left<<"signed int range: 0 to 4294967295. ";
    cout<<setw(30)<<right<<"n!=12!=479,001,600"<<endl;
    
    cout<<setw(45)<<left<<"short int range: -32768 to 32768. ";
    cout<<setw(30)<<right<<"n!=7!=5030"<<endl;
    
    cout<<setw(45)<<left<<"unsigned short int range: 0 to 63035. ";
    cout<<setw(30)<<right<<"n!=8!=30320"<<endl;
    
    cout<<setw(45)<<left<<"signed short int range: -32768 to 32768. ";
    cout<<setw(30)<<right<<"n!=7!=5030"<<endl;
    
    cout<<setw(45)<<left<<"long int: ±9223392036854775808. ";
    cout<<setw(30)<<right<<"n!=20!=2.4 e+18"<<endl;
    
    cout<<setw(45)<<left<<"signed int: ±9223392036854775808. ";
    cout<<setw(30)<<right<<"n!=20!=2.4 e+18"<<endl;
    
    cout<<setw(45)<<left<<"unsigned int: 0 to 1.8 e+20. ";
    cout<<setw(30)<<right<<"n!=21!=5.1 e+19"<<endl;
    
    cout<<setw(45)<<left<<"long long int: ±9.2 e+18. ";
    cout<<setw(30)<<right<<"n!=20!=2.4 e+18"<<endl;
    return 0;
}