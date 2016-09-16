/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 7, 2016, 7:31 PM
 * Purpose : Calculate the amount of profit of circuit board sales
 */
// Include system level libraries
#include <iostream>  //Input/Output Libraries
using namespace std; //Libraries compiled under standard namespace

// User Libraries
// Global Libraries
const unsigned char  PERCENT = 100;
//Functional Prototypes

// Program execution begins here!
int main(int argc, char** argv) {
    // Declare and initialize variables
    float crCost = 14.95f;        // Cost of Circuit Board production
    unsigned char pProfit = 35;  // Percent profit
    float sPrice, pAmnt;         // Selling price, Profit amount
    
    // Calculate the Profit amount and sales price:
    pAmnt = crCost * pProfit / 100;
    sPrice = pAmnt + crCost;
    
    // Output:
    cout << "Cost of producing a circuit board = $" << crCost << endl;
    cout << "Percent profit = " << static_cast<int> (pProfit) << "%" << endl;
    cout << "Circuit board selling price = $" << sPrice << endl;
    
    // Exit Program
    
    return 0; 
}

