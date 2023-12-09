/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   DatesConverter.h
 * Author: Peter Kim
 * Created on December 8, 2023, 7:41 PM
 */

#ifndef DATES_CONVERTER_H
#define DATES_CONVERTER_H

class DatesConverter {
private:
    int inputDay, day, month;

public:
    DatesConverter();
    int convertDayToMonthDay();
    void displayConvertedDate();
};

#endif /* DATES_CONVERTER_H */


