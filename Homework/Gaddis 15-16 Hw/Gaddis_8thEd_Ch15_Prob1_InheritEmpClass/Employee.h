/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Employee.h
 * Author: User
 *
 * Created on December 10, 2023, 3:04 PM
 */
#include <iostream> 
using namespace std; 

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
private: 
    string name; 
    unsigned int num; 
    string dateHired;  
public:
    Employee() {name=" "; 
                num=0; 
                dateHired=" ";} 
    
    void setName(string); 
    void setNum(unsigned int); 
    void setDate(string); 
    string getName() const; 
    unsigned int getNum() const; 
    string getDate() const; 
};

#endif /* EMPLOYEE_H */

