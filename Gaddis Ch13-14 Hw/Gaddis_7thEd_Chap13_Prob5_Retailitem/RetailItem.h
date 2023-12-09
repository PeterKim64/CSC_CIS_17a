/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   RetailItem.h
 * Author: User
 *
 * Created on November 21, 2023, 6:47 PM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H
#include <string>
using namespace std; 

class RetailItem {
private: 
    string description; 
    int unitsOnHand;
    float price; 
public: 
    RetailItem(string, int, float); 
    string getDesc() const;
    int getUnits() const; 
    float getPrice() const; 
};

#endif /* RETAILITEM_H */

