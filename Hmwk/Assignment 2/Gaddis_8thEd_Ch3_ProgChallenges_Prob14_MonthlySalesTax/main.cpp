/*
 * File:   main.cpp
 * Author: Hassan
 * Created on September 17, 2016, 2:59 PM
 * Purpose : Calculate the monthly sales tax
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int SIZE = 100;   //The total amount of character inputs
    char month[SIZE], //The input month
         year[SIZE];  //The input year
    float sTax = 0.04f, //The sales tax 
          cTax = 0.02f,//The country sales tax 
          totAmntC,   //The Total amount Collected
          sales,      //The Sales
          cSTax,      //The Country Sales Tax in Dollars
          sSTax,      //The State Sales Tax in Dollars
          tSTax;      //The Total Sales Tax in Dollars
    
    //Input values
    cout << "Input month and year:"<< endl;
    cin >> month >> year;
    cout << "Enter total amount collected:" << endl;
    cin >> totAmntC;
    
    //Calculate sales, country sales tax, state sales tax, total sales tax:
    sales = totAmntC / 1.06f;
    sSTax = sales * sTax;
    cSTax = sales * cTax;
    tSTax = sSTax + cSTax;
    
    //Display Output
    cout << setprecision(2) << fixed;
    cout << "--------------------------"<< endl;
    cout << "Year : " << year << endl; 
    cout << "Month :" << month << endl;
    cout << "--------------------------" << endl;
    cout << "Total Collected:  " << setw(5) << "$ " << setw(8) << totAmntC << endl; 
    cout << "Sales:            " << setw(5) << "$ " << setw(8) << sales << endl;  
    cout << "Country Sales Tax:" << setw(5) << "$ " << setw(8) << cSTax << endl;  
    cout << "State Sales Tax:  " << setw(5) << "$ " << setw(8) << sSTax << endl;
    cout << "Total Sales Tax:  " << setw(5) << "$ " << setw(8) << tSTax << endl;  
    //Exit Program
    return 0;
}

