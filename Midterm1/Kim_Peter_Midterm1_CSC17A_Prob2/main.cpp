/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: User
 * Created on October 21, 2023, 2:28 PM
 * Purpose: Calculate Pay 
 */

//System Libraries
#include <cstdlib>
#include <iostream>         // output
#include <string>           // string 
#include <iomanip>          // formmating
using namespace std;

//User Libraries

//Global Constants
//Only Universal Physics/Math/Conversions found here
//No Global Variables 
//Higher Dimension arrays requiring definition prior to prototype only 


//Structure
struct Employee {
    string name;            // employee name
    string company;         // company name
    string address;         // address of employee
    unsigned int hours;              // hours worked
    float rate;             // rate of pay per hour 
    int grossPay;         // pay for this employee
};
//Function Prototypes
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables or constants here
    Employee *emp;          //struct pointer
    unsigned int empSize;   //amount of employees being inputted 
    int index=0;            // index for struct array 
    const int TWENTY=20;    // to help calculate hours past 20
    const int FOURTY=40;    // calculate hours past 40
    const int DOUBLE=2;     // double the rate
    const int TRIPLE=3;     // triple the rate; 
    string numToEnglish; 
    
    
    //Initialize or input data here
    cout<<"Please enter amount of employees"<<endl;
    cin>>empSize;               // input size of struct array 
    
    //Dynamically create array of structures of size "empSize" 
    emp=new Employee[empSize]; 
    while(emp[empSize].hours>=0 && emp[empSize].rate>=0 && index<empSize) {
        cout<<"Please enter employee name. "<<endl; 
        cin.ignore();                                 // for the get line 
        getline(cin, emp[index].name); 
        cout<<"Please enter amount of hours worked. "<<endl; 
        cin>>emp[index].hours; 
        cout<<"Please enter pay rate. "<<endl; 
        cin>>emp[index].rate; 
    
        // calculations of pay done here 
        if(emp[index].hours<=20) {
            emp[index].grossPay=emp[index].hours * emp[index].rate;   // straight rate
        }
        else if(emp[index].hours>20 && emp[index].hours<=40) {
            emp[index].hours-=TWENTY;           // hours above 20 
            emp[index].grossPay+=(TWENTY*emp[index].rate);  // 20 hours paid straight
            emp[index].grossPay+=(emp[index].hours * (DOUBLE*emp[index].rate));     //overtime pay           
        }
        else if(emp[index].hours>40) {
            emp[index].hours-=FOURTY;           // hours above 40
            emp[index].grossPay+=(TWENTY*emp[index].rate);              // 20 hours paid straight 
            emp[index].grossPay+=(TWENTY*(DOUBLE*emp[index].rate));     // 20 more paid double 
            emp[index].grossPay+=(emp[index].hours * (TRIPLE*emp[index].rate)); // hours after 40, payed triple rate
        }

        //  output dialogue after input as specified in problem       
        cout<<endl; 
        cout<<setw(15)<<left<<"Company: The Good Company"<<endl;
        
        cout<<setw(12)<<left<<"Name: ";
        cout<<setw(30)<<right<<emp[index].name<<endl;
        
        cout<<setw(12)<<left<<"Address: ";
        cout<<setw(30)<<right<<emp[index].address<<endl;
        
        cout<<setw(12)<<left<<"Amount earned: $";
        cout<<setw(30)<<right<<emp[index].grossPay<<endl;
        
        cout<<setw(12)<<left<<"Amount: ";
        
    //convert num to english  
    if(emp[index].grossPay>=1 && emp[index].grossPay<=3000){
    //Process or map Inputs to Outputs
        //Determine 1000's, 100's, 10's, 1's
        int n1000s,n100s,n10s,n1s;
        n1000s=emp[index].grossPay/1000;   //Shift 3 places to the left
        n100s=emp[index].grossPay%1000/100;//Remainder of division of 1000 then shift 2 left
        n10s=emp[index].grossPay%100/10;   //Remainder of division of 100 then shift 1 left
        n1s=emp[index].grossPay%10;        //Remainder of division by 10
        
        //Output the number of 1000's in Roman Numerals
        //Using the Switch Statement
        switch(n1000s){
            case 3:cout<<"Three Thousand ";
            case 2:cout<<"Two Thousand ";
            case 1:cout<<"One Thousand ";
        }
        
        //Output the number of 100's
        //Using the Ternary Operator
        cout<<(n100s==9?"Nine hundred ":
               n100s==8?"Eight hundred ":
               n100s==7?"Seven hundred ":
               n100s==6?"Six hundred ":
               n100s==5?"Five hundred ":
               n100s==4?"Four hundred ":
               n100s==3?"Three hundred ":
               n100s==2?"Two hundred ":
               n100s==1?"One hundred ":"");
        
        //Output the number of 10's
        //Using Independent If Statements
        if(n10s==9)cout<<"Ninety";
        if(n10s==8)cout<<"Eighty";
        if(n10s==7)cout<<"Seventy";
        if(n10s==6)cout<<"Sixty";
        if(n10s==5)cout<<"Fifty";
        if(n10s==4)cout<<"Fourty";
        if(n10s==3)cout<<"Thirty";
        if(n10s==2)cout<<"Twenty";
        if(n10s==1)cout<<"One";
        
        //Teens
        if(n1s==19)cout<<"nineteen ";
        else if(n1s==18)cout<<"Eighteen ";
        else if(n1s==17)cout<<"Seventeen ";
        else if(n1s==16)cout<<"Sixteen ";
        else if(n1s==15)cout<<"Fifteen ";
        else if(n1s==14)cout<<"Fourteen ";
        else if(n1s==13)cout<<"Thirteen ";
        else if(n1s==12)cout<<"Twelve  ";
        else if(n1s==11)cout<<"Eleven ";
        
        //Output the number of 1's
        //Using Dependent If Statements
        if(n1s==9)cout<<"Nine ";
        else if(n1s==8)cout<<"Eight ";
        else if(n1s==7)cout<<"Seven ";
        else if(n1s==6)cout<<"Six ";
        else if(n1s==5)cout<<"Five ";
        else if(n1s==4)cout<<"Four ";
        else if(n1s==3)cout<<"Three ";
        else if(n1s==2)cout<<"Two  ";
        else if(n1s==1)cout<<"One ";
        
        //Reiterate the input value
        cout<<"Dollars";
                
    //The Path to Exit
    }
          
    else{
        cout<<"Could not convert gross pay into English."<<endl; 
    } 
    
        cout<<endl; 
        //input validation message   
        if(emp[index].hours <0 || emp[index].rate<0) {
            cout<<"Please enter positive hours or rates only."<<endl; 
        }
        index++; 
    }
    //Output
   
    //delete memory for array of structure  
    delete [] emp; 
    return 0;
}

 

