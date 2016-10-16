/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 8, 2016, 6:26 PM
 * Purpose : Calculate the income salary after incremental peny pay
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
    float dollars;          //Number of dollars
    unsigned int cents=1;   //Number of cents in the first day
    unsigned short numDays; //Number of payment days
    
    //Input values
    cout << "Input the number of days you will get paid (please not more than 31 days):" << endl;
    cin >> numDays;
    
    while (numDays > 31){
        cout << "You input a number greater than thirty please input again: " << endl;
        cin >> numDays;
    }
    //Process values
    for (int i=2; i<=numDays; i++){
        cents = cents * 2;
    }
    
    dollars = cents/100.0; //Converting cents to dollars
    
    //Display output
    cout << "The total number of cents : " << cents << endl;
    cout << "The total dollar amount will be : " << dollars << "$"<< endl;

    //Exit Program
    return 0;
}

