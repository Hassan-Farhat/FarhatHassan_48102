/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 6, 2016, 8:29 PM
 * Purpose : Calculate the annual pay.
 */
// Include system level libraries
#include <iostream>  //Input/Output Libraries
using namespace std; //Libraries compiled under standard namespace

// User Libraries
// Global Libraries
//Functional Prototypes

//Program execution begins here!
int main(int argc, char** argv) {
     // Declare Variables
    float pAmount = 2200.0f; // Pay amount per period in $'s
    short pPeriod = 26;      // Pay Periods in weeks
    // Calculations:
    int annPay = pAmount * pPeriod; //Annual Pay
    //Output:
    cout << "Pay amount per pay period = $" << pAmount << endl;
    cout << "Number of pay periods = " << pPeriod << endl;
    cout<<"The annual pay is = $"<<annPay<<endl;
    
    return 0;
}

