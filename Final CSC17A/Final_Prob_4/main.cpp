/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 *
 * Created on December 7, 2023, 2:35 PM
 */
#include <iostream>
#include <cstdlib>
#include "SavingsAccount.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    SavingsAccount mine(-300.0); 
    
    for(int i=1;i<=10;i++){
    mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
    <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
    <<mine.TotalRecursive((float)(0.10),7)
    <<" Recursive Calculation "<<endl;
    return 0;
}

