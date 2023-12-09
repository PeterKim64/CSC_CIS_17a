/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Date.cpp
 * Author: User
 * 
 * Created on November 20, 2023, 5:17 PM
 */

#include "Date.h"
#include <iostream>
#include <cstdlib>
using namespace std; 

void Date::setMonth(int m) {
    if(m>0 && m<=12) {          // validate input
        month=m; 
    }
    else cout<<"Invalid month input.";
}

void Date::setDay(int d) {
    if(d>0 && d<=31) {          // validate input
        day=d; 
    }
    else cout<<"Invalid day input."; 
}

void Date::setYear(int y) {
    year=y; 
}

int Date::getMonth() const {
    return month; 
}

int Date::getDay() const {
    return day; 
}

int Date::getYear() const {
    return year; 
}

void Date::display1() {
    cout<<month<<"/"<<day<<"/"<<year<<endl; 
}

void Date::display2() {
    string monthName; 
    switch(month) {
        case 1: 
            monthName="January";
            break; 
        case 2: 
            monthName="February"; 
            break; 
        case 3: 
            monthName="March";
            break; 
        case 4: 
            monthName="April"; 
            break;
        case 5: 
            monthName="May";
            break; 
        case 6: 
            monthName="June"; 
            break;
        case 7: 
            monthName="July";
            break; 
        case 8: 
            monthName="August"; 
            break;
        case 9: 
            monthName="September"; 
            break; 
        case 10: 
            monthName="October";
            break; 
        case 11: 
            monthName="November"; 
            break;
        case 12: 
            monthName="December"; 
            break;
        default: 
            cout<<"Invalid Month input, cannot display month name."<<endl; 
    }
    cout<<monthName<<" "<<day<<","<<year<<endl; 
    cout<<day<<" "<<monthName<<" "<<year; 
    
}


