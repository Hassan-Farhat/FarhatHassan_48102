/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 1, 2016, 2:22 PM
 * Purpose : Determine the number of day in each month
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
    unsigned short month, // month (1-12)
                   year; // year
    
    //Input values
    cout << "Enter a month in number form (1-12): ";
    cin >> month;
    cout << "Enter a year (1500 - 3000): ";
    cin >> year;
    
    //Process values -> Map inputs to Outputs
    if ((1500 > year || year > 3000) || (1 < month || month > 12)){
        cout << "Bad year please input a year between 1500 to 3000 or you entered a Bad month" << endl; 
    }
    if (((year % 100 == 0) && (year % 400 == 0)) && (month == 2)){
        cout << "29 days" << endl;
    }
    else if (((year % 100 != 0) && (year % 4 == 0)) && (month == 2)){
        cout << "29 days" << endl;
    }
    else if (month == 2){
        cout << "28 days" << endl;
    }
    else if ( 1 <= month && month <= 7){
        if (month % 2 == 0){
            cout << "30 days" << endl;
        }
        else {
            cout << "31 days" << endl;
        }
    }
    else if (month > 7 && month <= 12){
        if (month % 2 == 0){
            cout << "31 days" << endl;
        }
        else {
            cout << "30 days" << endl;
        }
    }
    else {
        cout << "You entered a number greater or less than 12" << endl;
    }
    
    //Display Output

    //Exit Program
    return 0;
}
