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
    int input,                 //The user input 
        first = 0,             // First array element       
        last = 11 - 1,         // Last array element       
        middle,                // Mid point of search       
        pos = -1;              // Position of search value
    bool found = false;        //Used to break out of the loop
    
    //Input values
    cout << "Input your lottery 5 digit number:"<< endl;
    cin >> input;
    
    //Binary search
    do{ 
        middle = (first+last)/2;    //Calculate the middle point
        if (lot[middle]==input){
            found = true;
            pos = middle;
            cout << "Your lottery numbers were correct !" << endl;
            cout << "Your numbers = " << input << endl;
            cout << "The lottery numbers = " << lot[middle] << endl;
        }
        else if (lot[middle] > input) last = middle-1;
        else first = middle+1;
    }while (found == false && first <= last);
    
    if (found == false){//Display if the numbers could not be found
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

