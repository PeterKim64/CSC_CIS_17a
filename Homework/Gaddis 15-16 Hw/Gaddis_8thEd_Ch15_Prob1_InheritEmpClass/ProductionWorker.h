/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ProductionWorker.h
 * Author: User
 *
 * Created on December 10, 2023, 3:18 PM
 */
#include <iostream> 
#include "Employee.h"

using namespace std; 
#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

class ProductionWorker : public Employee {
private: 
    int shift; 
    float rate;   
public: 
    ProductionWoker() {
        shift=0; 
        rate=0.0; 
    } 
    void setShift(int s) {
        shift=s; 
    } 
    void setRate(float r) {
        rate=r;
    } 
    int getShift() const {
        return shift; 
    } 
    float getRate() const {
        return rate; 
    } 
};

#endif /* PRODUCTIONWORKER_H */

