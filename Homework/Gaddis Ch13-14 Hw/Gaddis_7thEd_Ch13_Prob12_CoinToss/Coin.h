/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Coin.h
 * Author: User
 *
 * Created on December 4, 2023, 3:05 PM
 */
#include <iostream>
using namespace std; 

#ifndef COIN_H
#define COIN_H

class Coin {
private: 
    string sideUp; 
public:
    Coin();
    void toss();
    string getSideUp() const; 
};

#endif /* COIN_H */

