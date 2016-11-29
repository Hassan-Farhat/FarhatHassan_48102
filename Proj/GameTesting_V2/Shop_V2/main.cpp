/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 25, 2016, 1:00PM.
 * Purpose : Shop Testing
 */

#include <iostream>
#include <string>

using namespace std;

void Shop (bool[],string[],int,int,int);

int main(int argc, char** argv) {
    int coins = 15;
    const int SIZE=100;
    bool it[]={true,true,true,true,true,true,true};
    string items[]={"Shield", "Holy Spell", "Armor", "Sword", "Human Effigy",
                     "Rabbit's Foot", "Bow"};
    int used = 7, select;
    cout<<"Welcome to the store !"<<endl;
    Shop(it,items,used,coins,select);
    return 0;
}

void Shop(bool it[],string items[],int n,int coins,int select){
    do{
        for(int i=0; i<n; i++){
            if (it[i])cout<<i+1<<". "<<items[i]<<endl;
            else cout<<i+1<<". "<<"Purchased"<<endl; 
        }
        cout<<"You currently have "<<coins<<" coins."<<endl; 
        cout<<"Type in the number before the item to buy it."<<endl;
        cout<<"Each item costs 5 coins."<<endl;
        cout<<"You can leave by typing in 10"<<endl;
        cin>>select;
        cout<<endl;
        switch (select){
            case 1: 
                coins = (it[0])? coins-=5 : coins = coins; 
                it[0] = false;break;
            case 2:
                coins = (it[1])? coins-=5 : coins = coins;
                it[1] = false;break;
            case 3:
                coins = (it[2])? coins-=5 : coins = coins;
                it[2]= false;break;
            case 4:
                coins = (it[3])? coins-=5 : coins = coins;
                it[3] = false;break;
            case 5:
                coins = (it[4])? coins-=5 : coins = coins;
                it[4] = false;break;
            case 6:
                coins = (it[5])? coins-=5 : coins = coins;
                it[5] = false;break;
            case 7:
                coins = (it[6])? coins-=5 : coins = coins;
                it[6] = false;break;
            case 10:
                cout<<"Thank you come again."<<endl;break;
            default: cout<<"You didn't input a selection"<<endl<<endl;
        }
    }while(!(coins < 5) && !(select==10));
}
