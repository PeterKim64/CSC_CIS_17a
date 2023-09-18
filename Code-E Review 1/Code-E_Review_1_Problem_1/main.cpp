/* 
 * File:   main.cpp
 * Author: Peter Kim 
 * Created on 9/6/2023 9:34 P.M.
 * Purpose:  Hello World
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}
int  read(char array[]) {
    int count;
    for(count=0;count<20;count++) {
        cin>>array[count]; 
        if(array[count]==' ') 
            count=19; 
    }
    return count;   
}
void sort(char array[],int sizeIn) {
    int minIndex, minValue; 
    
    for(int start=0; start<(sizeIn-1); start++)
    {
        minIndex = start;
        minValue = array[start];
        for(int index = (start+1); index<sizeIn; index++) {
            if (array[index]<minValue) {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
 
}
void print(const char array[],int size) {
     for(int i=0; i<size; i++) {
        cout<<array[i];

     }  
     cout<<endl; 
}

