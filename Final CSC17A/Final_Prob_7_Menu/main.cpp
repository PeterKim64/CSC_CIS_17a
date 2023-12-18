/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim, Using Dr.Lehr Menu skeleton from github cs17a
 *
 * Created on December 17, 2023, 1:56 PM
 */

/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Purpose:  Menu using Functions,
 *           extend for midterm
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>      //prob 2
#include <string>       //prob 3
//Header Files
#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3Table.h"
#include "Prob3TableInherited.h"
#include "SavingsAccount.h"
#include "Employee.h"

using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5(); 

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='5');
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;   
    cout<<"Type 5 for Problem 5"<<endl<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1(){
    cout<<"Problem 1"<<endl;
      //Initialize Variables Here
    char n=5;
    char rndseq[]={19,34,57,79,126};
    int ntimes=100000;
    
    //Instantiate Class
    Prob1Random a(n,rndseq);
        
    for(int i=1;i<=ntimes;i++){
        a.randFromSet();        // pick random number from set
    }
    int *x=a.getFreq();             // get array of frequencies of each number
    char *y=a.getSet();             // get set of numbers used
    
    for(int i=0;i<n;i++){
    cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2(){
    cout<<"Problem 2"<<endl;
    //Declare variables 
    Prob2Sort<char> rc;
    bool ascending=true;
    ifstream infile;
    //Input and initialize variables 
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    //Process
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    //Output
    for(int i=0;i<10;i++){
    for(int j=0;j<16;j++){
    cout<<zc[i*16+j];
    }
    }
    delete []zc;
    cout<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){
    cout<<"Problem 3"<<endl;
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
        }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
        }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4(){
    cout<<"problem 4"<<endl;
    SavingsAccount mine(-300.0); 
    
    for(int i=1;i<=10;i++){
    mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
    <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
    <<mine.TotalRecursive((float)(0.10),7)
    <<" Recursive Calculation "<<endl;
}
void prblm5() {
    cout<<"problem 5"<<endl;
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
    
}

