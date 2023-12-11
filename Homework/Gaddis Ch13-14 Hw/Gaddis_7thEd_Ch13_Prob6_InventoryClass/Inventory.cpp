/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Inventory.cpp
 * Author: User
 * 
 * Created on December 4, 2023, 1:53 PM
 */
#include <iostream>
#include "Inventory.h"
using namespace std; 

void Inventory::setItemNumber(int i) {
    if(i>=0)
        itemNumber=i; 
    else
        cout<<"Invalid input for item number."<<endl; 
}
void Inventory::setQuantity(int q) {
    if(q>=0)
        quantity=q; 
    else
        cout<<"Invalid input for quantity."<<endl; 
}
void Inventory::setCost(float c) {
    if(c>=0)
        cost=c; 
    else
        cout<<"Invalid input for cost."<<endl; 
}
void Inventory::setTotalCost() {
    totalCost=quantity*cost; 
}
int Inventory::getItemNumber() const {
    return itemNumber;  
}
int Inventory::getQuantity() const {
    return quantity;  
}
float Inventory::getCost() const {
    return cost; 
}
float Inventory::getTotalCost() const {
    return totalCost;  
}

Inventory::Inventory(int itemNumber,int quantity,float cost) {
    if(itemNumber>=0 && quantity>=0 && quantity>=0 && cost>=0) {
    this->itemNumber=itemNumber; 
    this->quantity=quantity; 
    this->cost=cost; 
    setTotalCost(); 
    getTotalCost();
    } 
    else 
        cout<<"Invalid input. Please only enter positive numbers for input."<<endl; 
}




