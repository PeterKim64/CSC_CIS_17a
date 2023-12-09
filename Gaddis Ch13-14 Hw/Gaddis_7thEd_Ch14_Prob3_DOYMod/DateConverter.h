/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   DateConverter.h
 * Author: User
 *
 * Created on December 8, 2023, 7:47 PM
 */

#ifndef DATE_CONVERTER_H
#define DATE_CONVERTER_H

#include <string>

class DateConverter {
private:
    std::string inputMonth;
    int totalDays, inputDay, monthNumber;

public:
    DateConverter();
    int mapMonthToNumber();
    int countTotalDays();
    void displayConvertedDays();
};

#endif /* DATE_CONVERTER_H */


