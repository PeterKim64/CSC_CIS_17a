/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Created on October 17, 2023, 6:08 PM
 * Purpose: Determine if customer has overdrawn account balance
 */

/*
 * Description: 
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>          // set precision, showpoint, etc
#include <cmath>            // to do math to count digits for accNum
#include <stdlib.h>         // exit 
using namespace std;

//User Libraries

//Global Constants
//Only Universal Physics/Math/Conversions found here
//No Global Variables 
//Higher Dimension arrays requiring definition prior to prototype only 

//Function Prototypes

//Structures
struct Info {
    int accNum;             // size at 5 since accNum can only be 5 digits         
    string name;            // name
    string address;         // address
    float balanceBeg;       // balance at beginning of month
    float *checks=NULL;  // pointer to dynamic array of checks
    float  *deposits=NULL;  // pointer to dynamic array of deposits 
};
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables or constants here
    Info *customer;              // struct pointer 
    unsigned int sizeChecks;             // size for checks
    unsigned int sizeDeposits;           // size for deposits
    float totalChecks=0;        // accumulator for checks
    float totalDeposits=0;      // accumulator for deposits
    float netMonth=0;           // net of checks and deposits
    int accLength;              // length of accNumber to validate 5 digits
    float const debt=-35.00;     // debt accrued if overdrawn
    
    //Create structure
    customer=new Info; 
    //Display Input Dialogue 
    cout<<"Please enter the following customer information:"<<endl; 
    cout<<"Account number, Name, Address, and balance";
    cout<<" at beginning of the month."<<endl; 
    //Initialize or input data here 
    cin>>(*customer).accNum;
    accLength=(log10((*customer).accNum) + 1);
//    cout<<accLength;          // echoback 
    if(accLength!=5) {
        cout<<"Please enter a 5 digit account number."<<endl; 
    }
    else {
    cin.ignore();
    getline(cin,(*customer).name); 
    getline(cin,(*customer).address);  
    cin>>(*customer).balanceBeg; 

    //Ask for checks and deposits - dynamically create two arrays for these
    cout<<"Please enter how many checks were sent this month." << endl; 
    cin>>sizeChecks; 
    cout<<"Please enter the check values. "<<endl; 
    
    //Create dynamic array and input checks
    customer->checks=new float[sizeChecks];
    for(int i=0; i<sizeChecks; i++) {       // input checks
        cin>>customer->checks[i];
        totalChecks+=customer->checks[i];        
    }
    
    //Ask for how many deposits and input
    cout<<"Please enter how many deposits were in this month."<<endl; 
    cin>>sizeDeposits; 
    cout<<"Please enter the deposits values."<<endl; 
    //Create and input deposits array
    customer->deposits=new float[sizeDeposits]; 
    for(int i=0; i<sizeDeposits; i++) {
        cin>>customer->deposits[i]; 
        totalDeposits+=customer->deposits[i]; 
    }
    
    //Subtract checks from deposits, then add net into the beginning balance
    netMonth=totalDeposits-totalChecks; 
    netMonth+=customer->balanceBeg; 
//    cout<<showpoint<<fixed<<setprecision(2)<<(*customer).balanceBeg<<endl; 
    
    //Output
    if(netMonth<0) {
        cout<<"Your account balance is: $ "<<netMonth<<endl;  
        cout<<"You have overdrawn your account and will be charged $35.00."<<endl; 
        netMonth+=debt; 
        cout<<"Your new balance with this charge is now: $"<<netMonth<<endl<<endl; 
    }
    else {
        cout<<setw(15)<<left<< "Account number: ";
        cout<<setw(15)<<left<<customer->accNum<<endl; 
        cout<<setw(16)<<left<<"Name: ";
        cout<<setw(16)<<left<<customer->name<<endl; 
        cout<<setw(16)<<left<<"Address: ";
        cout<<setw(16)<<left<<customer->address<<endl; 
        cout<<"Your balance at the end of this month is: $"<<netMonth<<endl; 
    }
    }   
    delete[] customer->checks;            // delete memory 
    delete[] customer->deposits; 
    return 0;
}  
       
   
