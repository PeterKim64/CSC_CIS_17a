/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 *
 * Created on December 10, 2023, 7:22 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
T absolute(T number) {
   if(number>=0) return number; 
   if(number<0) return (-1*number);   
}

/*
 * 
 */
int main(int argc, char** argv) {
    //Initialize
    int integer=0;
    float floating=0.0; 
    //Input
    cout<<"Input an integer and float, of which absolute values will be returned."<<endl; 
    cin>>integer>>floating; 
    //Process
    integer=absolute(integer); 
    floating=absolute(floating);
    //Output
    cout<<integer<<" was the integer absolute value."<<endl; 
    cout<<floating<<" was the floating point absolute value."<<endl; 
    return 0;
}

