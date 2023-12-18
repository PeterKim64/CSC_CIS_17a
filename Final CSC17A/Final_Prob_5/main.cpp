/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 *
 * Created on December 16, 2023, 10:09 PM
 */

//System Libraries
#include <cstdlib>
#include<iostream>
#include <string>
#include "Employee.h"

using namespace std;

//User Libraries

//Global Constants
//Only Universal Physics/Math/Conversions found here
//No Global Variables 
//Higher Dimension arrays requiring definition prior to prototype only 

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables or constants here
//    char name[20];            // name of employee
//    char title[20];           // job title
//    float rate;             // rate
//    int hours;              //hours worked
////    //Initialize or input data here
//    cout<<"Please input your name, job title, and hourly rate."<<endl; 
//    cin>>name; 
//    cin>>title; 
//    cin>>rate; 
//    cout<<"Please input hours worked."<<endl; 
//    cin>>hours;
////    //Instantiate using constructor
//    Employee emp(name,title,rate); 
//    emp.toString(); 
//    emp.CalculatePay(rate,hours); 
//    emp.toString(); 
//    //Process   
Employee Mark("Mark","Boss",215.50);
Mark.setHoursWorked(-3);
Mark.toString();
Mark.CalculatePay(Mark.setHourlyRate(20.0),Mark.setHoursWorked(25));
Mark.toString();
Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHoursWorked(25));
Mark.toString();
Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHoursWorked(25));
Mark.toString();
Employee Mary("Mary","VP",50.0);
Mary.toString();
Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(40));
Mary.toString();
Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(50));
Mary.toString();
Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(60));
Mary.toString();

 
     
    //Output
   
    return 0;
}

