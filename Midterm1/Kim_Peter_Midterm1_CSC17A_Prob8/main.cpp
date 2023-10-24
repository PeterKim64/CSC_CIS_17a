/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: User
 * Created on October 23, 2023, 8:31 PM
 * Purpose: Menu of problems 1-4 on the midterm
 */
//System Libraries
#include <iostream>
#include <iomanip>          // format
#include <cstring>          // c_string()
#include <string>           // for string cins
#include <cmath>            // math operations in prob 1
#include <stdlib.h>         // exit 
using namespace std;

//User Libraries

//Structures 
struct Info {               // struct for problem 1
    string accNum;             // size at 5 since accNum can only be 5 digits         
    string name;            // name
    string address;         // address
    float balanceBeg;       // balance at beginning of month
    float *checks=NULL;  // pointer to dynamic array of checks
    float  *deposits=NULL;  // pointer to dynamic array of deposits 
};

struct Employee {           // struct for problem 2
    string name;            // employee name
    string company;         // company name
    string address;         // address of employee
    unsigned int hours;              // hours worked
    float rate;             // rate of pay per hour 
    int grossPay;         // pay for this employee
};

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();

//Functions for problem 4
void encrypt(int[],int);         // encrypts array of numbers and includes size
void decrypt(int[],int);         // same as above but decrypts

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
            case '6':{prblm6();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='6');
    
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
    cout<<"Type 5 for Problem 5"<<endl; 
    cout<<"Type 6 for Problem 6"<<endl; 
    
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
/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Created on October 17, 2023, 6:08 PM
 * Purpose: Determine if customer has overdrawn account balance
 */
    
//Execution Begins Here
    //Declare variables or constants here
    Info *customer;              // struct pointer 
    unsigned int sizeChecks;             // size for checks
    unsigned int sizeDeposits;           // size for deposits
    float totalChecks=0;        // accumulator for checks
    float totalDeposits=0;      // accumulator for deposits
    float netMonth=0;           // net of checks and deposits
    int accLength;              // length of accNumber to validate 5 digits
    float const debt=-35.00;     // debt accrued if overdrawn
    
    //Create structure
    customer=new Info; 
    //Display Input Dialogue 
    cout<<"Please enter the following customer information:"<<endl; 
    cout<<"Account number, Name, Address, and balance";
    cout<<" at beginning of the month."<<endl; 
    //Initialize or input data here 
    getline(cin,customer->accNum); 
    accLength=(customer->accNum).length(); 
    if(accLength!=5){
        cout<<"Invalid input. Please enter 5 digits for the account."<<endl; 
    }
    getline(cin,(*customer).name); 
    getline(cin,(*customer).address);  
    cin>>(*customer).balanceBeg; 

    //Ask for checks and deposits - dynamically create two arrays for these
    cout<<"Please enter how many checks were sent this month." << endl; 
    cin>>sizeChecks; 
    cout<<"Please enter the check values. "<<endl; 
    
    //Create dynamic array and input checks
    customer->checks=new float[sizeChecks];
    for(int i=0; i<sizeChecks; i++) {       // input checks
        cin>>customer->checks[i];
        totalChecks+=customer->checks[i];        
    }
    
    //Ask for how many deposits and input
    cout<<"Please enter how many deposits were in this month."<<endl; 
    cin>>sizeDeposits; 
    cout<<"Please enter the deposits values."<<endl; 
    //Create and input deposits array
    customer->deposits=new float[sizeDeposits]; 
    for(int i=0; i<sizeDeposits; i++) {
        cin>>customer->deposits[i]; 
        totalDeposits+=customer->deposits[i]; 
    }
    
    //Subtract checks from deposits, then add net into the beginning balance
    netMonth=totalDeposits-totalChecks; 
    netMonth+=customer->balanceBeg;  
    
    //Output
    if(netMonth<0) {
        cout<<"Your account balance is: $ "<<netMonth<<endl;  
        cout<<"You have overdrawn your account and will be charged $35.00."<<endl; 
        netMonth+=debt; 
        cout<<"Your new balance with this charge is now: $"<<netMonth<<endl<<endl; 
    }
    else {
        cout<<setw(15)<<left<< "Account number: ";
        cout<<setw(15)<<left<<customer->accNum<<endl; 
        cout<<setw(16)<<left<<"Name: ";
        cout<<setw(16)<<left<<customer->name<<endl; 
        cout<<setw(16)<<left<<"Address: ";
        cout<<setw(16)<<left<<customer->address<<endl; 
        cout<<"Your balance at the end of this month is: $"<<netMonth<<endl; 
    }
       
    delete[] customer->checks;            // delete memory 
    delete[] customer->deposits; 
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
    cout<<"This program is held in another project.";
   
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
//Execution Begins Here

    //Declare variables or constants here
    const int SIZE=12;         // size of array to hold 4 digits, larger than specified
    int choice;                // choice to encrypt or decrypt
    string input;              // numbers to be input
    int numbers[SIZE]; 
    int length;                // length of string to validate 4 digits  
    
    // Input  
        cout<<"Please enter a 4 digit integer. "; 
        cout<<"Enter only digits 0-7."<<endl;
        cin>>input;
    //read in
        for(int i=0; i<SIZE; i++) {
            numbers[i]=input[i]-'0';  // string to int array so adjust for acii codes -'0'
        }
    //validate input length of 4 digits
        length=input.length();
        if(length!=4) {
            cout<<"You did not input a number of 4 digits. Please try again.";
            exit(1); 
        }
    // validate numbers being input
//        for(int i=0; i<length; i++) {
//         
//        }
    // validate input range 0-7
        for(int i=0; i<length; i++) { 
            if(numbers[i]>7) {
                cout<<"The input includes a number not in 0-7 range, or a character."<<endl; 
                exit(1);
            }
        }
    //choice of whether to encrypt or decrypt 
    cout<<"Would you like to encrypt or decrypt your input?"<<endl; 
    cout<<"Press 0 to encrypt, 1 to decrypt."<<endl;  
    cin>>choice;            // encrypt or decrypt
    //begin processing
    switch(choice) {
    case 0:         // choice encrypt
        cout<<"You chose to encrypt."<<endl; 
        //process
        encrypt(numbers,length); 
        //output
        cout<<"The number "<<input<<" is ";
        for(int i=0; i<length; i++) {
            cout<<numbers[i]; 
        }
        cout<<" after encryption."<<endl; 
        break; 
    case 1:         //choice decrypt
        cout<<"You chose to decrypt."<<endl; 
        //process
        decrypt(numbers,length); 
        //output
        cout<<"The number "<<input<<" is ";
        for(int i=0; i<length; i++) {
            cout<<numbers[i]; 
        }
        cout<<" after decryption."<<endl; 
        break;
    default: 
        cout<<"You did not enter a valid choice input."<<endl; 
        cout<<"Please try again: 0 to encrypt, 1 to decrypt."<<endl;   
    } 

    //Output
   




}
void encrypt(int array[], int size) {
    for(int i=0; i<size; i++) {
        array[i]+=6; 
        array[i]=array[i]%8;
    }
}
void decrypt(int array[], int size) {
    for(int i=0; i<size; i++) {
        array[i]=(array[i]+2)%8; 
    }
}
void prblm5(){
    cout<<"problem 5"<<endl;
        //Output
    cout<<"Largest n! that can be held in each data type."<<endl; 
    
    cout<<setw(45)<<left<<"char range: 0 to 305 or -127 to 127. ";
    cout<<setw(30)<<right<<"n!=5!=120"<<endl;
    
    cout<<setw(45)<<left<<"unsigned char range: 0 to 305. ";
    cout<<setw(30)<<right<<"n!=5!=120"<<endl; 
    
    cout<<setw(45)<<left<<"signed char range:-127 to 127. ";
    cout<<setw(30)<<right<<"n!=5!=120"<<endl;
    
    cout<<setw(45)<<left<<"int range: -2147483648 to 2147483648. ";
    cout<<setw(30)<<right<<"n!=12!=479,001,600"<<endl;
    
    cout<<setw(45)<<left<<"unsigned int range: 0 to 4294967295. ";
    cout<<setw(30)<<right<<"n!=12!=479,001,600"<<endl;
    
    cout<<setw(45)<<left<<"signed int range: 0 to 4294967295. ";
    cout<<setw(30)<<right<<"n!=12!=479,001,600"<<endl;
    
    cout<<setw(45)<<left<<"short int range: -32768 to 32768. ";
    cout<<setw(30)<<right<<"n!=7!=5030"<<endl;
    
    cout<<setw(45)<<left<<"unsigned short int range: 0 to 63035. ";
    cout<<setw(30)<<right<<"n!=8!=30320"<<endl;
    
    cout<<setw(45)<<left<<"signed short int range: -32768 to 32768. ";
    cout<<setw(30)<<right<<"n!=7!=5030"<<endl;
    
    cout<<setw(45)<<left<<"long int: ±9223392036854775808. ";
    cout<<setw(30)<<right<<"n!=20!=2.4 e+18"<<endl;
    
    cout<<setw(45)<<left<<"signed int: ±9223392036854775808. ";
    cout<<setw(30)<<right<<"n!=20!=2.4 e+18"<<endl;
    
    cout<<setw(45)<<left<<"unsigned int: 0 to 1.8 e+20. ";
    cout<<setw(30)<<right<<"n!=21!=5.1 e+19"<<endl;
    
    cout<<setw(45)<<left<<"long long int: ±9.2 e+18. ";
    cout<<setw(30)<<right<<"n!=20!=2.4 e+18"<<endl;
}

void prblm6() {
   cout<<"problem 6"<<endl;
    
    cout<<setw(20)<<left<<"Number";
    cout<<setw(20)<<left<<"Base 16";
    cout<<setw(20)<<left<<"Base 8";
    cout<<setw(20)<<left<<"Base 2";
    cout<<setw(20)<<left<<"NASA float"<<endl; 
    
    cout<<setw(20)<<left<<"49.1875";
    cout<<setw(20)<<left<<"31.3";
    cout<<setw(20)<<left<<"61.14";
    cout<<setw(20)<<left<<"120001";
    cout<<setw(20)<<left<<"626262FA"<<endl; 
    
    cout<<setw(20)<<left<<"3.07421875";
    cout<<setw(20)<<left<<"3.13";
    cout<<setw(20)<<left<<"3.046";
    cout<<setw(20)<<left<<"11.00020011";
    cout<<setw(20)<<left<<"626262FE"<<endl; 
    
    cout<<setw(20)<<left<<"0.2";
    cout<<setw(20)<<left<<"0.33...";
    cout<<setw(20)<<left<<"0.14631463...";
    cout<<setw(20)<<left<<"0.00110011...";
    cout<<setw(20)<<left<<"666666FE"<<endl<<endl; 
    
    cout<<setw(20)<<left<<"NASA float";
    cout<<setw(20)<<left<<"Base 10"<<endl; 
    
    cout<<setw(20)<<left<<"69999902";
    cout<<setw(20)<<left<<"3.25046875..."<<endl; 
    
    cout<<setw(20)<<left<<"69999903";
    cout<<setw(20)<<left<<"6.5421..."<<endl; 
    
    cout<<setw(20)<<left<<"966667FF";
    cout<<setw(20)<<left<<"0.587500035761"<<endl; 
}

