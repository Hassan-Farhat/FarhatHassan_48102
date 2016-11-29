/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 20, 2016, 5:39 PM
 * Purpose : Find the users account
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const int SIZE = 100;
    int acc[SIZE] = {0 ,5658845, 4520125, 7895122, 8777541, 8451277, 1302850,      //The account numbers
                     8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                     1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    int input;          //The user input 
    bool found = false;  //Used to break out of the loop
    
    //Input values
    cout << "Please type in the account number:"<< endl;
    cin >> input;
    
    //Linear search
    for (int i = 1; i<18 && found == false; i++){
        if(input == acc[i]) found = true;
    }
    
    //Display Output
    if (found == true) cout << endl << "We found your account" << endl;
    else { //If item could not be found.
        cout << endl << "We could not find your account sorry." << endl;
        cout << "Our current accounts are:" << endl;
        for (int i = 1; i < 18; i++){
            cout << acc[i] << "   ";
            if (i%4 == 0) cout << endl;
        }
        cout << endl;
    }
    //Exit Program
    return 0;
}