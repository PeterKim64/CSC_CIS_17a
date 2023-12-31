/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Employee.h
 * Author: User
 *
 * Created on December 16, 2023, 10:10 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee {
public:
    Employee(char[],char[],float); //Constructor
    float CalculatePay(float,int); //Procedure
    float getGrossPay(float,int); //Procedure
    float getNetPay(float); //Procedure
    void toString(); //Procedure
    int setHoursWorked(int); //Procedure
    float setHourlyRate(float); //Procedure
private:
    double Tax(float); //Utility Procedure
    char MyName[20]; //Property
    char JobTitle[20]; //Property
    float HourlyRate; //Property
    int HoursWorked; //Property
    float GrossPay; //Property
    float NetPay; //Property
};

#endif /* AEMPLOYEE_H */

