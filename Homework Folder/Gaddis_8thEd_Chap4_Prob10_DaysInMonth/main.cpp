/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Date: September 9, 2023
 * Purpose: Output days in a month based on user input month and year
 * Created on September 9, 2023, 4:08 PM
 */

//System Libraries
#include <cstdlib>
#include<iostream>
#include<iomanip>
using namespace std;

//User Libraries

//Global Constants
//Only Universal Physics/Math/Conversions found here
const int JAN=31;           //months with 31 days 
const int MAR=31;
const int MAY=31;
const int JUL=31;
const int AUG=31;
const int OCT=31;
const int DEC=31;
const int APR=30;           // months with 30 days
const int JUN=30;
const int SEP=30;
const int NOV=30; 
const int FEB=29;           // feb depending on leap year or no
const int FEBLEAP=28;
//No Global Variables 
//Higher Dimension arrays requiring definition prior to prototype only 

//Function Prototypes
bool calculateLeap(int); 
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables or constants here
    int month; 
    int year; 
    int day;
    bool leap; 
    
    //Initialize or input data here
    cout<<"Please enter a year"<<endl;  
    cin>>year;
    cout<<"Please enter a month 1-12." <<endl; 
    cin>>month; 
    //Process
    leap=calculateLeap(year);
//    cout<<"Is it a leap year? " << leap<<endl; //echoback
    //Output depending on leap year or not
    if(leap=true) {
            switch(month) {
                case 1:cout<<"January of "<<year<<" has "<<JAN<<" days.";
                break; 
                case 2:cout<<"February of "<<year<<" has "<<FEBLEAP<<" days.";
                break; 
                case 3:cout<<"March of "<<year<<" has "<<MAR<<" days.";
                break; 
                case 4:cout<<"April of "<<year<<" has "<<APR<<" days.";
                break; 
                case 5:cout<<"May of "<<year<<" has "<<MAY<<" days.";
                break; 
                case 6:cout<<"June of "<<year<<" has "<<JUN<<" days.";
                break; 
                case 7:cout<<"July of "<<year<<" has "<<JUL<<" days.";
                break; 
                case 8:cout<<"August of "<<year<<" has "<<AUG<<" days.";
                break; 
                case 9:cout<<"September of "<<year<<" has "<<SEP<<" days.";
                break; 
                case 10:cout<<"October of "<<year<<" has "<<OCT<<" days."; 
                break; 
                case 11:cout<<"November of "<<year<<" has "<<NOV<<" days.";
                break; 
                case 12:cout<<"Dec of "<<year<<" has "<<DEC<<" days.";
                break;
                default: cout<<"You did not enter a month 1-12."<<endl; 
            
            }
        }
    else if (leap=false) {
            switch(month) {
                case 1:cout<<"January of "<<year<<" has "<<JAN<<" days.";
                break; 
                case 2:cout<<"February of "<<year<<" has "<<FEB<<" days.";
                break; 
                case 3:cout<<"March of "<<year<<" has "<<MAR<<" days.";
                break; 
                case 4:cout<<"April of "<<year<<" has "<<APR<<" days.";
                break; 
                case 5:cout<<"May of "<<year<<" has "<<MAY<<" days.";
                break; 
                case 6:cout<<"June of "<<year<<" has "<<JUN<<" days.";
                break; 
                case 7:cout<<"July of "<<year<<" has "<<JUL<<" days.";
                break; 
                case 8:cout<<"August of "<<year<<" has "<<AUG<<" days.";
                break; 
                case 9:cout<<"September of "<<year<<" has "<<SEP<<" days.";
                break; 
                case 10:cout<<"October of "<<year<<" has "<<OCT<<" days."; 
                break; 
                case 11:cout<<"November of "<<year<<" has "<<NOV<<" days.";
                break; 
                case 12:cout<<"Dec of "<<year<<" has "<<DEC<<" days.";
                break;
                default: cout<<"You did not enter a month 1-12."<<endl; 
            
            }
    }
     
    return 0;
}

bool calculateLeap(int year) {     //Function to calculate if leap year or no
    bool result;  
if((year%100==0)&&(year%400==0)) {
       result=true;  
    } 

else if(year%100!=0&&year%4==0) {
        result=true; 
    }
else result=false; 
return result; 
}

