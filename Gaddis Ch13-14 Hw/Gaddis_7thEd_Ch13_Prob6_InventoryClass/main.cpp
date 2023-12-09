/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Created on December 4, 2023, 1:51 PM
 * Purpose: Create Inventory class using constructor and manual inputs
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Inventory.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //initialize
    Inventory i;            // i is the instance of Inventory class
    int num=0; 
    int quant=0; 
    float cost=0.00; 
    float totalCost=0.00; 
    //input
        cout<<"Please input item number, item quantity, and item cost."<<endl; 
        cin>>num>>quant>>cost;  
        i.setItemNumber(num); 
        i.setQuantity(quant); 
        i.setCost(cost); 
        i.setTotalCost(); 
        cout<<"Item Number: "<<i.getItemNumber()<<endl;  
        cout<<"Item Quantity: "<<i.getQuantity()<<endl; 
        cout<<"Item Cost: $"<<i.getCost()<<endl;
        cout<<fixed<<setprecision(2); 
        cout<<"Total Cost: $"<<i.getTotalCost()<<endl<<endl; 
        
        Inventory x(1265,2,10.20); 
        cout<<"Item Number: "<<x.getItemNumber()<<endl;  
        cout<<"Item Quantity: "<<x.getQuantity()<<endl;  
        cout<<"Item Cost: $"<<x.getCost()<<endl; 
        cout<<fixed<<setprecision(2); 
        cout<<"Total Cost: $"<<x.getTotalCost()<<endl;    
    return 0;
}

