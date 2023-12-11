/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ModifiedScore.h
 * Author: User
 *
 * Created on December 10, 2023, 6:29 PM
 */

// ModifiedScore.h
#ifndef MODIFIEDSCORE_H
#define MODIFIEDSCORE_H

class ModifiedScore
{
protected:
    float customGrammar, customSpell, customLength, customContent;

public:
    ModifiedScore();
};

class ModifiedPassFail : public ModifiedScore
{
private:
    float minCustomPass, customTotScore;

public:
    ModifiedPassFail();
    void display();
};

#endif /* MODIFIEDSCORE_H */


