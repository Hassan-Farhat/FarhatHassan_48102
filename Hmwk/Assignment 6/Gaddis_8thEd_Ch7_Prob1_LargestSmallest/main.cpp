/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 14, 2016, 5:08 PM
 * Purpose : Find the Largest/Smallest Array Value
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void FillAry(int [], int);
void Largest(int [], int);
void Smallest(int [], int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const int SIZE = 10;
    int num[SIZE];
    int utilize = SIZE;
    
    //Input values
    FillAry(num, utilize);
    
    //Process values and display
    Largest(num, utilize);
    Smallest (num, utilize);

    //Exit Program
    return 0;
}

//Fill the Array with user input:
void FillAry(int num[], int utilize){
    for(int i = 0; i < utilize; i++){
        cout << "Input an integer: ";
        cin >> num[i];
    }
}

//Sort out the largest value entered by the user:
void Largest(int num[], int utilize){
    int max;
    max = num[0];
    for(int i = 1; i < utilize; i++){
        if (num[i] > max) max = num[i];
    }
    cout << "==================================" << endl;
    cout << "The largest number that you entered was: " << max << endl;
}

//Sort out the smallest value entered by the user:
void Smallest(int num[], int utilize){
    int min;
    min = num[0];
    for(int i = 1; i < utilize; i++){
        if (num[i] < min) min = num[i];
    }
    cout << "The smallest number that you entered was: " << min << endl;
}