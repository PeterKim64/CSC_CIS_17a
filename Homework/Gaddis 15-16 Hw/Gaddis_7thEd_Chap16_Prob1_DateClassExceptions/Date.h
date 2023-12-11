/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Date.h
 * Author: User
 *
 * Created on December 9, 2023, 5:22 PM
 */

#ifndef DATE_H
#define DATE_H

class Date {
private:
    int month; 
    int day; 
    int year; 
public:
    Date();             // default constructor 
    class invalidDay {}; 
    class invalidMonth {}; 
    void setMonth(int); 
    void setDay(int); 
    void setYear(int); 
    int getMonth() const; 
    int getDay() const; 
    int getYear() const; 
    void display1(); 
    void display2(); 
};

#endif /* DATE_H */

