/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   WorkDaysCounter.h
 * Author: User
 *
 * Created on December 8, 2023, 7:51 PM
 */

#ifndef WORK_DAYS_COUNTER_H
#define WORK_DAYS_COUNTER_H

class WorkDaysCounter {
private:
    float totalDays, workHours;
    char userChoice;

public: 
    WorkDaysCounter();
    void countDays();
    void displayTotalDays();
};

#endif /* WORK_DAYS_COUNTER_H */


