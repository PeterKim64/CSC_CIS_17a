/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   DateConverter.cpp
 * Author: User
 * 
 * Created on December 8, 2023, 7:47 PM
 */

#include <iostream>
using namespace std;

#include "DateConverter.h"

DateConverter::DateConverter() {
    cout << "This Program Inputs a date and converts it to its corresponding number of days." << endl;
    cout << "Enter a Date (Month) (Day): ";
    cin >> inputMonth >> inputDay;
    
    // Initialize totalDays
    totalDays = 0;

    // Count Months and totalDays
    mapMonthToNumber();
    countTotalDays();
}

int DateConverter::mapMonthToNumber() {
    if (inputMonth == "January") monthNumber = 1;
    else if (inputMonth == "February") monthNumber = 2;
    else if (inputMonth == "March") monthNumber = 3;
    else if (inputMonth == "April") monthNumber = 4;
    else if (inputMonth == "May") monthNumber = 5;
    else if (inputMonth == "June") monthNumber = 6;
    else if (inputMonth == "July") monthNumber = 7;
    else if (inputMonth == "August") monthNumber = 8;
    else if (inputMonth == "September") monthNumber = 9;
    else if (inputMonth == "October") monthNumber = 10;
    else if (inputMonth == "November") monthNumber = 11;
    else if (inputMonth == "December") monthNumber = 12;

    return 0; // Placeholder, replace with actual calculation
}

int DateConverter::countTotalDays() {
    for (int i = 0; i < monthNumber; i++) {
        // Add to get the exact day in the month
        if (i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
            totalDays += 31;
        } else if (i == 3 || i == 5 || i == 8 || i == 10) {
            totalDays += 30;
        } else if (i == 1) {
            totalDays += 28;
        }
    }
    totalDays += inputDay;

    return 0; // Placeholder, replace with actual calculation
}

void DateConverter::displayConvertedDays() {
    cout << endl << "The Converted Date amounts to " << totalDays << " Day(s)";
}


