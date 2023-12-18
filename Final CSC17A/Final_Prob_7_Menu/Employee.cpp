/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Employee.cpp
 * Author: User
 * 
 * Created on December 17, 2023, 2:19 PM
 */

#include "Employee.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std; 

Employee::Employee(char name[],char job[],float rate) {
    //set char[]
    for(int i=0; i<20; i++) {
        MyName[i]=name[i];
        JobTitle[i]=job[i]; 
    }
    //validation
    if(rate>0 && rate<200)
        HourlyRate=rate;
    else {
        string rateError="Invalid hourly rate, please try again.(1-83)";  //exception
        cout<<rateError<<endl;  
        HourlyRate=0.0; 
    }

    //set everything else to 0
    HoursWorked=0; 
    GrossPay=0.0; 
    NetPay=0.0; 
  
}

float Employee::setHourlyRate(float r) {
    if(r>0 && r<200)
        HourlyRate=r;
    else {
        string rateError="Invalid hourly rate, please try again.(1-83)";  //exception
        cout<<rateError<<endl;     
    }
    return HourlyRate; 
}
int Employee::setHoursWorked(int w) {
    if(w>0 && w <200)
        HoursWorked=w; 
    else {
        string workError="Invalid hours worked, please try again.(1-199)"; //exception
        cout<<workError<<endl;  
    }
    return HoursWorked; 
}
float Employee::getGrossPay(float rate,int hours) {
    int hoursMod40=40;           //modified hours from longer than 40
    int hoursMod50=50;
    if(hours<=40)
        GrossPay=hours*rate;
    if(hours>40 && hours<=50) {
        hours-=hoursMod40;  
        GrossPay=(hours*1.5*rate) + (hoursMod40*rate);  
    }
    if(hours>50) {
        hours-=hoursMod50; 
        GrossPay=(hours*2*rate) + (10*1.5*rate) + (hoursMod40*rate); 
        
    }
    return GrossPay;    
}
double Employee::Tax(float gross) {
    double tax=0.0; 
    float grossMod500=500.0;  
    float grossMod1000=1000.0;
    if(gross<=500){
       tax=gross*0.1;  
    }
    if(gross>500 && gross<=1000) {
        gross-=grossMod500; 
        tax=(grossMod500*0.1) + (gross*0.2); 
    }
    if(gross>1000) {
        gross-=grossMod1000; 
        tax=(grossMod500*0.1) + (grossMod500*0.2) + (gross*0.3); 
    }
    return tax; 
}
float Employee::getNetPay(float gross) {
    float Pay=0.0; 
    Pay=getGrossPay(HourlyRate,HoursWorked); 
    NetPay=Pay-Tax(GrossPay);
    return NetPay;    
}
float Employee::CalculatePay(float rate,int hours) {
    return getNetPay(getGrossPay(setHourlyRate(rate),setHoursWorked(hours)));
}
void Employee::toString() {
    cout<<"Name: "<<MyName;
    cout<<" Title: "<<JobTitle;
    cout<<" Hourly Rate: "<<HourlyRate<<" Hours Worked: "<<HoursWorked;
    cout<<" Gross Pay: $"<<GrossPay<<" Net Pay: $"<<NetPay;
    cout<<endl; 
}

