/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: User
 *
 * Created on October 23, 2023, 20:50 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout<<setw(20)<<left<<"Number";
    cout<<setw(20)<<left<<"Base 16";
    cout<<setw(20)<<left<<"Base 8";
    cout<<setw(20)<<left<<"Base 2";
    cout<<setw(20)<<left<<"NASA float"<<endl; 
    
    cout<<setw(20)<<left<<"49.1875";
    cout<<setw(20)<<left<<"31.3";
    cout<<setw(20)<<left<<"61.14";
    cout<<setw(20)<<left<<"120001";
    cout<<setw(20)<<left<<"626262FA"<<endl; 
    
    cout<<setw(20)<<left<<"3.07421875";
    cout<<setw(20)<<left<<"3.13";
    cout<<setw(20)<<left<<"3.046";
    cout<<setw(20)<<left<<"11.00020011";
    cout<<setw(20)<<left<<"626262FE"<<endl; 
    
    cout<<setw(20)<<left<<"0.2";
    cout<<setw(20)<<left<<"0.33...";
    cout<<setw(20)<<left<<"0.14631463...";
    cout<<setw(20)<<left<<"0.00110011...";
    cout<<setw(20)<<left<<"666666FE"<<endl<<endl; 
    
    cout<<setw(20)<<left<<"NASA float";
    cout<<setw(20)<<left<<"Base 10"<<endl; 
    
    cout<<setw(20)<<left<<"69999902";
    cout<<setw(20)<<left<<"3.25046875..."<<endl; 
    
    cout<<setw(20)<<left<<"69999903";
    cout<<setw(20)<<left<<"6.5421..."<<endl; 
    
    cout<<setw(20)<<left<<"966667FF";
    cout<<setw(20)<<left<<"0.587500035761"<<endl; 
    return 0;
}

