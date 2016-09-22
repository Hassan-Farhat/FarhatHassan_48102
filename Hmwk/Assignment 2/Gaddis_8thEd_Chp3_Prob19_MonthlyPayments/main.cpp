/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 22, 2016, 11:33 AM
 * Purpose : Calculate the monthly payment
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cmath>
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const unsigned int PERCENT = 100;

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float loan, annInt,      // Loan amount , annual interest
          monInt, payment,   // Monthly interest, and payment.
          totPaid, intPaid,  // Total paid and total interest paid.
          pInt;              // Interest in percent
    
    int mMonths; // Number of payment months.
    
    //Input values
    cout << "Input the loan amount, and annual interest rates:"<<endl;
    cin >> loan >> annInt ;
    cout << "Input an integer for number of payment months"<<endl;
    cin >> mMonths;
    
    //Calculations:
    monInt = (annInt / 12) / PERCENT;
    payment = (monInt * pow((1+monInt),mMonths) * loan)/(pow((1+monInt),mMonths) - 1);
    totPaid = payment * mMonths;
    intPaid = totPaid - loan ;
    pInt = PERCENT * monInt;
    
    //Display Output
    cout << setprecision(2) << fixed << showpoint;
    cout << "Loan amount           = $" << setw(10) << loan << endl;
    cout << "Monthly Interest rate = " << setw(10) << pInt << "%" << endl;
    cout << "Number of Payments    = $" << setw(10) << mMonths << endl;
    cout << "Monthly Payments      = $" << setw(10) << payment << endl;
    cout << "Total amount paid     = $" << setw(10) << totPaid << endl;
    cout << "Total interest paid   = $" << setw(10) << intPaid << endl;
            
    //Exit Program
    return 0;
}

