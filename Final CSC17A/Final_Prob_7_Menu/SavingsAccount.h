/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   SavingsAccount.h
 * Author: User
 *
 * Created on December 17, 2023, 2:17 PM
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount {
public:
    SavingsAccount(float); //Constructor
    void Transaction(float); //Procedure
    float Total(float=0,int=0); //Savings Procedure
    float TotalRecursive(float=0,int=0);
    void toString(); //Output Properties

private:
    float Withdraw(float); //Utility Procedure
    float Deposit(float); //Utility Procedure
    float Balance; //Property
    int FreqWithDraw; //Property
    int FreqDeposit; //Property
};

#endif /* SAVINGSACCOUNT_H */

