/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   person.cpp
 * Author: User
 * 
 * Created on November 20, 2023, 9:04 PM
 */

#include "person.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std; 

void Person::setName(string nameIn) {
    name=nameIn; 
}

void Person::setAddy(string addressIn) {
    address=addressIn; 
}

void Person::setAge(int ageIn) {
    if(ageIn>0) age=ageIn; 
    else cout<<"Invalid age input."<<endl; 
}

void Person::setPhone(string phoneIn) {
    phone=phoneIn; 
}

//getters
string Person::getName() const {
    return name; 
}

string Person::getAddy() const {
   return address;  
}

int Person::getAge() const {
    return age; 
}

string Person::getPhone() const {
    return phone; 
}

//output
void Person::display() const {
    cout<<endl; 
    cout<<name<<endl; 
    cout<<address<<endl; 
    cout<<age<<endl; 
    cout<<phone<<endl;
}


