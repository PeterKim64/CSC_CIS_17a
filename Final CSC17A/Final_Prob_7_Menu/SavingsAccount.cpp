/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   SavingsAccount.cpp
 * Author: User
 * 
 * Created on December 17, 2023, 2:17 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include "SavingsAccount.h"

using namespace std; 

SavingsAccount::SavingsAccount(float b) {
    if(b<0) Balance=0;
    else if(b>=0) Balance=b; 
    FreqWithDraw=0; 
    FreqDeposit=0; 
}

void SavingsAccount::Transaction(float t) {
    if(t>0) Deposit(t); 
    if(t<0) Withdraw(t); 
    if(t==0) cout<<"Void transaction with no value."<<endl; 
}

float SavingsAccount::Deposit(float d) {
    Balance+=d; 
    FreqDeposit++;
}
float SavingsAccount::Withdraw(float w) {
    if(w>Balance) cout<<"Cannot withdraw, not enough funds."<<endl;
    if(w<Balance) {
        Balance+=w; 
        FreqWithDraw++;
    }
}
void SavingsAccount::toString() {
    cout<<"Balance: $"<<fixed<<setprecision(2)<<Balance<<endl; 
    cout<<"Withdraws: "<<FreqWithDraw<<endl; 
    cout<<"Deposits: "<<FreqDeposit<<endl; 
}
float SavingsAccount::Total (float savint, int time) {
    for(int i=0; i<time;i++) {
        Balance=Balance*(1.0+savint); 
    }
    return Balance; 
}
float SavingsAccount::TotalRecursive(float savint, int time) {
    int nMinusOne=Balance; 
    Balance=nMinusOne*pow((1.0+savint),7); 
    return Balance; 
}


