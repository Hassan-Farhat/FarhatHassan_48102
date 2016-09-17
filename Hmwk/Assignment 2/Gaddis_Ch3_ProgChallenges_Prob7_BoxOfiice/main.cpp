/*
 * File:   main.cpp
 * Author: Hassan
 * Created on September 17, 2016, 12:52 PM
 * Purpose : 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>
#include <string>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const int SIZE = 100;
    char movie[SIZE]; //Movie name
    float aTicket = 10.0f, cTicket = 6.0f, pProfit = 0.2f; //Price of an adult and child ticket.
    int aTcktS, cTcktS;                                    //Number Adult tickets sold and Child tickets sold
    float gBOPrft, nBOPrft, amntPDt;                       //Gross Box Office Profit, Net Box Office Profit, Amount Paid to distributer 
    //Input values
    cout << "Name of movie:" << endl;
    cin.getline(movie,SIZE);
    cout << "How many adult tickets were sold:" << endl;
    cin >> aTcktS;
    cout << "How many child tickets were sold" << endl;
    cin >> cTcktS;
    
    //Calculations
    gBOPrft = (aTicket * aTcktS) + (cTicket * cTcktS);
    nBOPrft = gBOPrft * pProfit;
    amntPDt = gBOPrft - nBOPrft;
    
    //Display Output
    cout << "Movie Name:" << setw(40) << movie << endl;
    cout << setprecision(2) << fixed;
    cout << "Adult Tickets Sold:" << setw(28) << aTcktS << endl;
    cout << "Child Tickets Sold:" << setw(28) << cTcktS << endl;
    cout << "Gross Box Office Profit:" << setw(26) << gBOPrft << endl;
    cout << "Net Box Office Profit:" << setw(28) << nBOPrft << endl;
    cout << "Amount Paid to Distributer:" << setw(23) << amntPDt << endl;

    //Exit Program
    return 0;
}

