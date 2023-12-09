/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Inventory.h
 * Author: User
 *
 * Created on December 4, 2023, 1:53 PM
 */
#include<iostream>
using namespace std; 

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
private:
    int itemNumber; 
    int quantity; 
    float cost; 
    float totalCost; 
public:
    Inventory()
    {itemNumber=0; quantity=0; cost=0.00; totalCost=0.00;};
    Inventory(int, int, float);
   void  setItemNumber(int); 
   void  setQuantity(int); 
   void setCost(float); 
   void setTotalCost(); 
   int getItemNumber() const; 
   int getQuantity() const; 
   float getCost() const; 
   float getTotalCost() const; 
};

#endif /* INVENTORY_H */

