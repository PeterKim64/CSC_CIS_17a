/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   RetailItem.cpp
 * Author: User
 * 
 * Created on November 21, 2023, 6:47 PM
 */

#include "RetailItem.h"
#include <string>

RetailItem::RetailItem(string desc,int units,float pricing) {
    description=desc; 
    unitsOnHand=units; 
    price=pricing; 
}

string RetailItem::getDesc() const {
    return description; 
}

int RetailItem::getUnits() const {
    return unitsOnHand; 
}

float RetailItem::getPrice() const {
    return price; 
}

