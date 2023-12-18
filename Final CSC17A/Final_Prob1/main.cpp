/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 *
 * Created on December 7, 2023, 1:08 PM
 */

#include <cstdlib>
#include <iostream> 
#include "Prob1Random.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
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
    return 0;

}

