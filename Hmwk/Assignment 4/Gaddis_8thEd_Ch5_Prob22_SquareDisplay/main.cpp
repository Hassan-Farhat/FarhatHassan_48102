/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 10, 2016, 2:48 PM
 * Purpose: Display a square based on user input
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
    char ch = 'X';          //The X character to fill the square with
    unsigned short dmnsion; //The dimensions of the square
    
    //Input values
    cout << "Please input the dimensions of the square: " << endl;
    cin >> dmnsion;
    
    //Process values and display
    for (int i=1;i<=dmnsion;i++){
        for (int k = 1; k<=dmnsion;k++){
            cout << ch;
        }
        cout << endl;
    }

    //Exit Program
    return 0;
}

