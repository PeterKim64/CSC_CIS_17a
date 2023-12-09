/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NumberDescription.cpp
 * Author: Peter Kim
 * Created on December 8, 2023, 7:32 PM
 */
#include <iostream>
using namespace std;

#include "convert.h"

Convert::Convert() {
    cout << "This Program Converts a numerical value to its English description." << endl;
    cout << "Enter a number value (0 - 9999): ";
    cin >> fullNum;
    if(fullNum < 0) {
        cout << "Inputed number is invalid..." << endl;
        cout << "Try again: ";
        cin >> fullNum;
    }
    //Call Calculate;
    calcIndiv();
}

int Convert::calcIndiv() {
    //Calculate the 1000's, 100's, 10's and 1's
    num1 = fullNum % 10;
    num2 = (fullNum / 10) % 10;
    num3 = (fullNum / 100) % 10;
    num4 = (fullNum / 1000) % 10;
}

void Convert::display() {
    cout << endl << "The Converted form of numerical value is..." << endl;
    //Convert to English numerical Value
    //Thousands Place
    switch(num4) {
        case 1:
            cout << "One Thousand ";
            break;
        case 2:
            cout << "Two Thousand ";
            break;
        case 3:
            cout << "Three Thousand ";
            break;
        case 4:
            cout << "Four Thousand ";
            break;
        case 5:
            cout << "Five Thousand ";
            break;
        case 6:
            cout << "Six Thousand ";
            break;
        case 7:
            cout << "Seven Thousand ";
            break;
        case 8:
            cout << "Eight Thousand ";
            break;
        case 9:
            cout << "Nine Thousand ";
            break;
    }
    //Hundreths place
    switch(num3) {
        case 1:
            cout << "One Hundred ";
            break;
        case 2:
            cout << "Two Hundred ";
            break;
        case 3:
            cout << "Three Hundred ";
            break;
        case 4:
            cout << "Four Hundred ";
            break;
        case 5:
            cout << "Five Hundred ";
            break;
        case 6:
            cout << "Six Hundred ";
            break;
        case 7:
            cout << "Seven Hundred ";
            break;
        case 8:
            cout << "Eight Hundred ";
            break;
        case 9:
            cout << "Nine Hundred ";
            break;
    }
    //Tenths place depending on teen or not
    if (num2 == 1) {
        switch(num1) {
            case 0:
                cout << "Ten ";
                break;
            case 1:
                cout << "Eleven ";
                break;
            case 2:
                cout << "Twelve ";
                break;
            case 3:
                cout << "Thirteen ";
                break;
            case 4:
                cout << "Fourteen ";
                break;
            case 5:
                cout << "Fifteen ";
                break;
            case 6:
                cout << "Sixteen ";
                break;
            case 7:
                cout << "Seventeen ";
                break;
            case 8:
                cout << "Eighteen ";
                break;
            case 9:
                cout << "Nineteen ";
                break;
        }
    }
    else {
        switch(num2) {
            case 2:
                cout << "Twenty ";
                break;
            case 3:
                cout << "Thirty ";
                break;
            case 4:
                cout << "Forty ";
                break;
            case 5:
                cout << "Fifty ";
                break;
            case 6:
                cout << "Sixty ";
                break;
            case 7:
                cout << "Seventy ";
                break;
            case 8:
                cout << "Eighty ";
                break;
            case 9:
                cout << "Ninety ";
                break;
        }
        //Ones place
        switch(num1) {
            case 0:
                cout << "";
                break;
            case 1:
                cout << "One ";
                break;
            case 2:
                cout << "Two ";
                break;
            case 3:
                cout << "Three ";
                break;
            case 4:
                cout << "Four ";
                break;
            case 5:
                cout << "Five ";
                break;
            case 6:
                cout << "Six ";
                break;
            case 7:
                cout << "Seven ";
                break;
            case 8:
                cout << "Eight ";
                break;
            case 9:
                cout << "Nine ";
                break;
        }
    }
    //If the number is just 0
    if(fullNum == 0) {
        cout << "Zero";
    }
}

