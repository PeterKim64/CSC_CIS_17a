/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Purpose: RetailItem class
 * Created on November 21, 2023, 6:45 PM
 */

/* Description: Create a class called "RetailItem that holds description,
 * unitsOnHand, and price member variables. Use a constructor that takes
 * these arguments and mutator functions to store them. 
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "RetailItem.h"
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
    RetailItem one("Jacket",12,59.95);      // the three items being stored using RetailItem class
    RetailItem two("Designer Jeans",40,34.95); 
    RetailItem three("Shirt",20,24.95); 
    //Initialize or input data here
    cout<<setw(15)<<left<<"";  
    cout<<setw(15)<<left<<"Description"; 
    cout<<setw(15)<<left<<"Units on Hand"; 
    cout<<setw(15)<<left<<"Price"<<endl; 
    
    cout<<setw(15)<<left<<"Item #1";
    cout<<setw(15)<<left<<one.getDesc(); 
    cout<<setw(15)<<left<<one.getUnits(); 
    cout<<setw(15)<<left<<one.getPrice()<<endl;
    
    cout<<setw(15)<<left<<"Item #2";
    cout<<setw(15)<<left<<two.getDesc(); 
    cout<<setw(15)<<left<<two.getUnits(); 
    cout<<setw(15)<<left<<two.getPrice()<<endl; 
    
    cout<<setw(15)<<left<<"Item #3";
    cout<<setw(15)<<left<<three.getDesc(); 
    cout<<setw(15)<<left<<three.getUnits(); 
    cout<<setw(15)<<left<<three.getPrice()<<endl;
    
    //Output
   
    return 0;
}
