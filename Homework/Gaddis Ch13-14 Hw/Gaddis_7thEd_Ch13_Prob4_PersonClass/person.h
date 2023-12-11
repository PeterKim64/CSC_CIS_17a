/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   person.h
 * Author: User
 *
 * Created on November 20, 2023, 9:04 PM
 */

#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std; 

class Person {
    private:
        string name; 
        string address; 
        int age; 
        string phone; 
    public:
        //setters
        void setName(string); 
        void setAddy(string); 
        void setAge(int); 
        void setPhone(string);
        //getters
        string getName() const; 
        string getAddy() const ; 
        int    getAge() const;
        string getPhone() const; 
        //output
        void display() const; 
       
};

#endif /* PERSON_H */

