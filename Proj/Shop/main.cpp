/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 23, 2016, 1:41 PM
 * Purpose : Shop Testing
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int coins = 15;
    bool it1 = true, it2 = true, it3 = true, it4 = true, it5 = true, it6 = true,
         it7 = true;
    string item1="Shield", item2="Holy Spell", item3="Armor", item4="Sword",
           item5="Extra Life", item6="Rabbit's Foot", item7="Bow", 
           confirm;
    char select;
    cout << "Welcome to the store !" << endl;
    do{
        if (it1)cout << "A. Shield" << endl;
        else cout << "A. Purchased" << endl;
        if (it2)cout << "B. Holy Spell" << endl;
        else cout << "B. Purchased" << endl;
        if (it3)cout << "C. Armor" << endl;
        else cout << "C. Purchased" << endl;
        if (it4)cout << "D. Sword" << endl;
        else cout << "D. Purchased" << endl;
        if (it5)cout << "E. Extra Life" << endl;
        else cout << "E. Purchased" << endl;
        if (it6)cout << "F. Rabbit's Foot" << endl;
        else cout << "F. Purchased" << endl;
        if (it7)cout << "G. Bow" << endl; 
        else cout << "G. Purchased" << endl;
        cout << "What would you like to purchase?" << endl;
        cout << "Type in the letter before the item" << endl;
        cin >> select;
        switch (select){
            case 'A':
                it1 = false; 
                coins -=5; break;
            case 'B':
                it2 = false;
                coins -=5; break;
            case 'C':
                it3 = false;
                coins -=5; break;
            case 'D':
                it4 = false;
                coins -=5; break;
            case 'E':
                it5 = false;
                coins -=5; break;
            case 'F':
                it6 = false;
                coins -=5; break;
            case 'G':
                it7 = false; 
                coins -=5; break;
            default: cout << "You didn't input a selection" <<endl;
        }
    }while(!(coins < 5) && !(confirm == "Leave" || confirm == "leave"));
    /*cout << (it1)?"A. Shield":"A. Purchased" << endl;
    cout << (it2)?"B. Shield":"B. Purchased" << endl;
    cout << (it3)?"C. Shield":"C. Purchased" << endl;
    cout << (it4)?"D. Shield":"D. Purchased" << endl;
    cout << (it5)?"E. Shield":"E. Purchased" << endl;
    cout << (it6)?"F. Shield":"F. Purchased" << endl;
    cout << (it7)?"G. Shield":"G. Purchased" << endl;*/

    return 0;
}

