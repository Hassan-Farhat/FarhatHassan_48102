/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 20, 2016, 6:36 PM
 * Purpose: Lottery simulator 
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
     const int SIZE = 100;
    int lot[SIZE] = {0, 13579, 26791, 26792, 33445, 55555,  //The lottery numbers
                     62483, 77777, 79422, 85647, 93121};
    int input;           //The user input 
    bool found = false;  //Used to break out of the loop
    
    //Input values
    cout << "Input your lottery 5 digit number:"<< endl;
    cin >> input;
    
    //Linear search
    for (int i = 1; i<11 && found == false; i++){
        if(input == lot[i]){
            found = true;
            cout << endl << "Your numbers were correct" << endl;
            cout << "Your numbers: " << input << endl;
            cout << "The lottery numbers: " << lot[i] << endl;
        }
    }
    if (found == false){
        cout << "Your numbers where incorrect" << endl;
        cout << "This weeks numbers are:" << endl;
        for (int k = 1; k < 11; k++){
            cout << lot[k] << "   ";
            if (k%4 == 0) cout << endl;
        }
        cout << endl;
    }
    //Exit Program
    return 0;
}

