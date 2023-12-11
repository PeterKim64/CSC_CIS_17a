/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   DatesConverter.cpp
 * Author: Peter Kim
 * Created on December 8, 2023, 7:41 PM
 */

#include <iostream>
using namespace std;

#include "DatesConverter.h"

DatesConverter::DatesConverter() {
    cout << "This Program Converts the day of a year to its corresponding date." << endl;
    cout << "Enter a day (1 - 365): ";
    cin >> inputDay;
    
    // Initialize month as 12 for loop and day as input
    month = 12;
    day = inputDay;

    // Calculate day and month
    convertDayToMonthDay();
}

int DatesConverter::convertDayToMonthDay() {
    for (int i = 0; i < month; i++) {
        // Subtract to get the exact day in the month
        if ((i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) && day > 31) {
            day -= 31;
        } else if ((i == 3 || i == 5 || i == 8 || i == 10) && day > 30) {
            day -= 30;
        } else if (i == 1 && day > 28) {
            day -= 28;
        } else {
            month = i;
        }
    }

    return 0; // Placeholder, replace with actual calculation
}

void DatesConverter::displayConvertedDate() {
    cout << "The converted day is calculated..." << endl;
    cout << "Day " << inputDay << " would be ";

    switch (month) {
        case 0:
            cout << "January ";
            break;
        case 1:
            cout << "February ";
            break;
        case 2:
            cout << "March ";
            break;
        case 3:
            cout << "April ";
            break;
        case 4:
            cout << "May ";
            break;
        case 5:
            cout << "June ";
            break;
        case 6:
            cout << "July ";
            break;
        case 7:
            cout << "August ";
            break;
        case 8:
            cout << "September ";
            break;
        case 9:
            cout << "October ";
            break;
        case 10:
            cout << "November ";
            break;
        case 11:
            cout << "December ";
            break;
    }

    cout << day << ".";
}


