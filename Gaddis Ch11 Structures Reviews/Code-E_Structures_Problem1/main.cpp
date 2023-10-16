/* 
 * File:   
 * Author: 
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
// Strcuture Declaration 
struct North{
  float q1; 
  float q2; 
  float q3; 
  float q4; 
  float totAnnl; 
  float averageQrt; 
};
struct South{
  float q1; 
  float q2; 
  float q3; 
  float q4; 
  float totAnnl; 
  float averageQrt;   
};
struct East{
  float q1; 
  float q2; 
  float q3; 
  float q4; 
  float totAnnl; 
  float averageQrt;   
};
struct West{
  float q1; 
  float q2; 
  float q3; 
  float q4; 
  float totAnnl; 
  float averageQrt;   
};
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    North nsales; 
    South ssales; 
    East esales;  
    West wsales; 
    
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    //North Div
    cout<<"North"<<endl; 
    cout<<"Enter first-quarter sales:"<<endl; 
    cout<<"Enter second-quarter sales:"<<endl;
    cout<<"Enter third-quarter sales:"<<endl; 
    cout<<"Enter fourth-quarter sales:"<<endl; 
    cin>>nsales.q1; 
    cin>>nsales.q2; 
    cin>>nsales.q3; 
    cin>>nsales.q4; 
    nsales.totAnnl=nsales.q1+nsales.q2+nsales.q3+nsales.q4; 
    cout<<"Total Annual sales:$"<<fixed<<setprecision(2)<<nsales.totAnnl<<endl; 
    nsales.averageQrt=nsales.totAnnl/4.00; 
    cout<<"Average Quarterly Sales:$"<<fixed<<setprecision(2)<<nsales.averageQrt<<endl; 
    //West Div
    cout<<"West"<<endl; 
    cout<<"Enter first-quarter sales:"<<endl; 
    cout<<"Enter second-quarter sales:"<<endl;
    cout<<"Enter third-quarter sales:"<<endl; 
    cout<<"Enter fourth-quarter sales:"<<endl; 
    cin>>wsales.q1; 
    cin>>wsales.q2; 
    cin>>wsales.q3; 
    cin>>wsales.q4; 
    wsales.totAnnl=wsales.q1+wsales.q2+wsales.q3+wsales.q4; 
    cout<<"Total Annual sales:$"<<fixed<<setprecision(2)<<wsales.totAnnl<<endl; 
    wsales.averageQrt=wsales.totAnnl/4.00; 
    cout<<"Average Quarterly Sales:$"<<fixed<<setprecision(2)<<wsales.averageQrt<<endl; 
    //East Div 
    cout<<"East"<<endl; 
    cout<<"Enter first-quarter sales:"<<endl; 
    cout<<"Enter second-quarter sales:"<<endl;
    cout<<"Enter third-quarter sales:"<<endl; 
    cout<<"Enter fourth-quarter sales:"<<endl; 
    cin>>esales.q1; 
    cin>>esales.q2; 
    cin>>esales.q3; 
    cin>>esales.q4; 
    esales.totAnnl=esales.q1+esales.q2+esales.q3+esales.q4; 
    cout<<"Total Annual sales:$"<<fixed<<setprecision(2)<<esales.totAnnl<<endl; 
    esales.averageQrt=esales.totAnnl/4.00; 
    cout<<"Average Quarterly Sales:$"<<fixed<<setprecision(2)<<esales.averageQrt<<endl; 
    //South Div
    cout<<"South"<<endl; 
    cout<<"Enter first-quarter sales:"<<endl; 
    cout<<"Enter second-quarter sales:"<<endl;
    cout<<"Enter third-quarter sales:"<<endl; 
    cout<<"Enter fourth-quarter sales:"<<endl; 
    cin>>ssales.q1; 
    cin>>ssales.q2; 
    cin>>ssales.q3; 
    cin>>ssales.q4; 
    ssales.totAnnl=ssales.q1+ssales.q2+ssales.q3+ssales.q4; 
    cout<<"Total Annual sales:$"<<fixed<<setprecision(2)<<ssales.totAnnl<<endl; 
    ssales.averageQrt=ssales.totAnnl/4.00; 
    cout<<"Average Quarterly Sales:$"<<fixed<<setprecision(2)<<ssales.averageQrt; 
    //Display Outputs

    //Exit stage right!
    return 0;
}
