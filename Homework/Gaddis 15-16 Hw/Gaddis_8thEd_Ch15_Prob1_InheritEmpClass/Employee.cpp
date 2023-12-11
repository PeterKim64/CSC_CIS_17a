/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Employee.cpp
 * Author: User
 * 
 * Created on December 10, 2023, 3:04 PM
 */

#include "Employee.h"

void Employee::setName(string n) {
    name=n; 
}
void Employee::setNum(unsigned int number) {
    num=number;
}
void Employee::setDate(string d) {
    dateHired=d; 
}
string Employee::getName() const{
    return name; 
}
unsigned int Employee::getNum() const{
    return num; 
}
string Employee::getDate() const{
    return dateHired; 
}


