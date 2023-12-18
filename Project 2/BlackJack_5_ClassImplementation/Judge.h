/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Judge.h
 * Author: User
 *
 * Created on December 12, 2023, 7:15 PM
 */

/*Has access to all other classes through friend classes. Can modify all other 
 * classes. It's purpose is to sum the cards dealt, and check to see what 
 * conditions give what results.
 */
#include "Players.h"
#include "Dealer.h"

#ifndef JUDGE_H
#define JUDGE_H 
class Dealer;                  //for when judge takes a sums from dealer
class Players; 

class Judge {
private:
    int* sums;
    bool gameEnd; 
    int gameResult; 
public:
    Judge();
    Judge(const Judge& orig);
    //Setters
    void checks(Dealer &,Players &);      // gets sums from dealer
    //Getters
    
    
};

#endif /* JUDGE_H */

