/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 1, 2016, 12:06 PM
 * Purpose : Convert numbers (1 through 10) to Roman numerals
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
    unsigned short num; // number to convert
    
    
    //Input values
    cout << "Please input a number between 1 and 10" << endl;
    cin >> num;
    
    //Process values + Output
    switch(num){
        case 10: 
            cout << "C" << endl; break;
        case 9:
            cout << "IX" << endl; break;
        case 8:
            cout << "VIII" << endl; break;
        case 7:
            cout << "VII" << endl; break;
        case 6:
            cout << "VI" << endl; break;
        case 5:
            cout << "V" << endl; break;
        case 4:
            cout << "IV" << endl; break;
        case 3:
            cout << "III" << endl; break;
        case 2:
            cout << "II" << endl; break;
        case 1:
            cout << "I" << endl; break;
        default: 
            cout << "Number was not between 1 and 10";
    }
   
   
    //Exit program
    return 0;
}
