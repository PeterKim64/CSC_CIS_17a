/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: User
 * Purpose: Create three instances of a personal info class
 * Created on November 20, 2023, 9:02 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include "person.h"
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
    //3 instances of the class "person" 
    Person me; 
    Person brother; 
    Person sister; 
    //local variables to be set into the class "person"
    string localName; 
    string localAddy; 
    int localAge; 
    string localPhone; 
    //Initialize or input data here
    cout<<"Please enter your name, address, age, and phone number (no dashes in phone number)."<<endl; 
    getline(cin,localName); 
    getline(cin,localAddy); 
    cin>>localAge; 
    cin>>localPhone; 
    cin.ignore(); 
    //setters
    me.setName(localName); 
    me.setAddy(localAddy); 
    me.setAge(localAge); 
    me.setPhone(localPhone); 
    //for second instance
    cout<<"Please enter another name, address, age, and phone number (no dashes in phone number)."<<endl; 
    getline(cin,localName); 
    getline(cin,localAddy); 
    cin>>localAge; 
    cin>>localPhone;
    cin.ignore(); 
    //setters for second instance
    brother.setName(localName); 
    brother.setAddy(localAddy); 
    brother.setAge(localAge); 
    brother.setPhone(localPhone);
    //for third instance
    cout<<"Please one more name, address, age, and phone number (no dashes in phone number)."<<endl; 
    getline(cin,localName); 
    getline(cin,localAddy); 
    cin>>localAge; 
    cin>>localPhone;
    cin.ignore(); 
    //setters for third and last instance
    sister.setName(localName); 
    sister.setAddy(localAddy); 
    sister.setAge(localAge); 
    sister.setPhone(localPhone);
    //Output
    me.display(); 
    brother.display(); 
    sister.display(); 
   
    return 0;
}

