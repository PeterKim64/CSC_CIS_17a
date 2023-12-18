/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 *
 * Created on December 11, 2023, 12:27 PM
 */

//System Libraries
#include <cstdlib>
#include<iostream>
#include <fstream>
#include"Prob2Sort.h"
using namespace std;

//User Libraries

//Global Constants
//Only Universal Physics/Math/Conversions found here
//No Global Variables 
//Higher Dimension arrays requiring definition prior to prototype only 

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables 
    Prob2Sort<char> rc;
    bool ascending=true;    //can be set to true or false 
    ifstream infile;
    //Input and initialize variables 
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    //Process
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    //Output
    for(int i=0;i<10;i++){
    for(int j=0;j<16;j++){
    cout<<zc[i*16+j];
    }
    }
    delete []zc;
    cout<<endl;
    return 0;
}

