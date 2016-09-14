/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 6, 2016, 7:18 PM
 * Purpose : Calculate and display the total cost of a restaurant meal.
 */
// Include system level libraries
#include <iostream>  //Input/Output Libraries
using namespace std; //Libraries compiled under standard namespace

// User Libraries
// Global Libraries
const unsigned char PERCENT = 100;
//Functional Prototypes

//Program execution begins here!
int main(int argc, char** argv) {
    // Declare and initialize variables 
    float mealChg = 8.867e1f,           //Meal charge in $
          tax = 6.75f;                  //Tax Percentage
    unsigned short tip = 20;            //Tip Percentage
    float amntTax, mealwT, amntTip, totBill; //Tax amount, Price of Meal with Tax, Tip amount,Total bill
    
    //Calculations:
    amntTax = mealChg * tax / PERCENT;
    mealwT = amntTax + mealChg;
    amntTip = mealwT * tip / PERCENT;
    totBill = amntTip + mealwT;
    
    //Display the output
    cout<<"The meal charge = $" << mealChg << endl;
    cout<<"The tax amount  = $"<< amntTax<< endl;
    cout<<"The tip amount  = $"<< amntTip<< endl;
    cout<<"The total bill  = $"<< totBill<< endl;
            
    return 0;
}

