/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 9, 2016, 6:10 PM
 * Purpose : Calculate and display the prices of a purchase.
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const unsigned char PERCENT = 100;
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float item1 = 15.95f, // Price of item 1
          item2 = 24.95f, // Price of item 2
          item3 = 6.95f,  // Price of item 3
          item4 = 12.95f, // Price of item 4
          item5 = 3.95f,  // Price of item 5
          sTotal,         // Subtotal
          tax,            // Cost of tax
          total;          // Total Price
    unsigned char pTax = 7;    // Tax percent
     
    //Process values -> Map inputs to Outputs
    sTotal = item1 + item2 + item3 + item4 + item5;
    tax = (sTotal * pTax) / PERCENT;
    total = tax + sTotal;
    
    //Display Output
    cout << "Price of item 1 = $" << item1 << endl;
    cout << "Price of item 2 = $" << item2 << endl;
    cout << "Price of item 3 = $" << item3 << endl;
    cout << "Price of item 4 = $" << item4 << endl;
    cout << "Price of item 5 = $" << item5 << endl;
    cout << "Sub-total = $" << sTotal << endl;
    cout << "Tax = $" << tax << endl;
    cout << "Total = $" << total << endl;
    //Exit Program
    return 0;
}

