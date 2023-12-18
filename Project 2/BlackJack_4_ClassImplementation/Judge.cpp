/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Judge.cpp
 * Author: User
 * 
 * Created on December 12, 2023, 7:15 PM
 */

#include "Judge.h"
#include "Dealer.h"             //for function it sent as a friend "checks"
#include <iomanip>              // formatting

Judge::Judge() {
    sums=nullptr; 
    gameEnd=false; 
    gameResult=3;              //0 is lose, 1 is win, -1 is tie 
}

Judge::Judge(const Judge& orig) {
}

int Judge::checks(Dealer & cards,Players &player) {
    sums=cards.getSums();
 if(gameEnd==false) { 
        
        if(sums[0]==21 && sums[1]==21 && gameEnd==false) {
            cout<<"You and the dealer have tied for blackjack."<<endl;
            gameEnd=true; 
            gameResult=-1;
            }
        else if(sums[0]==21 && gameEnd==false) {
            cout<<"The dealer has won with a blackjack."<<endl;
            player.setLoss(player.getBet()); 
            cout<<"You lost $"<<player.getLoss()<<endl; 
            gameEnd=true;
            gameResult=0; 
             
            }
        else if(sums[1]==21 && gameEnd==false) {
            cout<<"You have won with a blackjack. Congratulations!"<<endl;
            player.setWin(2*player.getBet());
            cout<<"You won $"<<player.getWin()<<endl; 
            gameEnd=true;
            gameResult=1; 
            
        }

        //next: did they bust? 
        for(int players=0; players<2; players++) {
            if(sums[0]>21 && sums[1]>21 && gameEnd==false) {
                cout<<"Both of you went over 21! It's a tie!"<<endl; 
                gameEnd=true;
                gameResult=-1;
            }
            if(sums[players]>21 && gameEnd==false) {
                if(players==0 && gameEnd==false) {
                    player.setWin(2*player.getBet()); 
                    cout<<setprecision(2)<<fixed; 
                    cout<<"The dealer has busted. You won $"<<player.getWin()<<endl;  
                    gameEnd=true; 
                    gameResult=1; 
                    
                }
                else if(players==1 && gameEnd==false) {
                    player.setLoss(player.getBet()); 
                    cout<<setprecision(2)<<fixed; 
                    cout<<"You have busted. You lost $"<<player.getLoss()<<endl; 
                    gameEnd=true;
                    gameResult=0; 
                     
                }
            }
        } 
        //next: if they didn't bust, who's closer to 21? 
        int diffPlayer=0;         // differences from 21: player
        int diffDealer=0;         // differences from 21: dealer
        if(player.getHit()==0 && cards.getHit()==0 && gameEnd==false) {
            diffDealer=21-(sums[0]); 
            diffPlayer=21-(sums[1]); 
            if(diffPlayer<diffDealer) {            // player was closer to 21
                player.setWin(2*player.getBet()); 
                cout<<setprecision(2)<<fixed; 
                cout<<"Congrats! You won $"<<player.getWin()<<endl;
                gameEnd=true; 
                gameResult=1; 
                
            }
            else if(diffPlayer>diffDealer) {       // dealer was closer to 21 
                player.setLoss(player.getBet());
                cout<<setprecision(2)<<fixed; 
                cout<<"Aw, you lost $"<<player.getLoss()<<endl; 
                gameEnd=true;
                gameResult=0; 
                 
            }
            else if(diffPlayer==diffDealer) {      // player and dealer tied
                cout<<"Dealer and Player tied with same sum of "<<sums[0]<<" and "<<sums[1]<<endl; 
                gameEnd=true; 
                gameResult=-1;
            }
        }
    }
    else if(gameEnd==true) {                                         // validation if something goes wrong
        player.setNet();            //automatically subtracts losses from wins 
    }
    return gameResult;  
}




