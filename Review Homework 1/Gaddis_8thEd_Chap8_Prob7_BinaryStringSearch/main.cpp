/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Date: September 10, 2023
 * Purpose: Binary Search for a string
 * Created on September 10, 2023, 8:27 PM
 */

//System Libraries
#include <cstdlib>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//User Libraries

//Global Constants
//Only Universal Physics/Math/Conversions found here
//No Global Variables 
//Higher Dimension arrays requiring definition prior to prototype only 

//Function Prototypes
void alphabetize(string, const int);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables or constants here
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill",
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                               "James, Jean", "Weaver, Jim", "Pore, Bob",
                               "Rutherford, Greg", "Javens, Renee",
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };  
    //Initialize or input data here
     alphabetize(names[20], NUM_NAMES); 
  
    //Process 
   
    //Output
     
    return 0;
}


void alphabetize(string names[], const int NUM_NAMES) {
    int startScan; 
    int minIndex; 
    string minLet;             // min letter
    for(startScan=0; startScan<(NUM_NAMES-1); startScan++) {
        minIndex=startScan; 
        minLet=names[startScan]; 
        for(int index=startScan+1; index<NUM_NAMES; index++) {
            if(names[index]<minLet) {
                names[index]=minLet;
                minIndex=index;                 
            }
            names[minIndex]=names[startScan];
            names[startScan]=minLet; 
        }
    }
    
    //Output 
    for(int i=0; i<NUM_NAMES; i++) {
        cout<<"The names in alphabetical order (hopefully) are: "<< names[i]<<endl;
    }
}

