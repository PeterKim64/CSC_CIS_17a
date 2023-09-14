/* 
 * File:   main.cpp
 * Author: User
 * Date: September 10, 2023
 * Purpose: Output Weather Reports from a text file
 * Created on September 10, 2023, 4:23 PM
 */


#include <fstream>
#include <iostream>
#include <cstring>
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
    fstream inFile; 
    const int MONTHS=3; 
    const int DAYS=30; 
    char monthDays[MONTHS][DAYS];
    string filename="RainOrShine.txt"; 

    //Initialize or input data here
    inFile.open(filename.c_str());
    for(int i=0; i<MONTHS; i++) { 
        for(int j=0; j<DAYS; j++) {
            char tempchar;
            inFile>>tempchar;
            monthDays[i][j]=tempchar; 
            cout<<monthDays[i][j]<<"  ";  
        } 
        cout<<endl; 
    }
    
    //TESTING FILE READING
//    string s;                 
//    while(getline(inFile,s)) {
//        cout<<s;  
//    }
    //TESTING FILE OPENING CORRECTLY
//    if(inFile) {
//        cout<<"open"<<endl; 
//    }
//    else
//        cout<<"not open"; 
    inFile.close(); 
    //Process 
   
    //Output
     
    return 0;
}

