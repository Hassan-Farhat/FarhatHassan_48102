/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 9, 2016, 5:21 PM
 * Purpose : Calculate how far an object would fall
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
    float acc = 32.174f; // acceleration in feet per second (Gravity)

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float time, // How many seconds the object is in free fall
          dist; // Distance
    
    //Input values
    cout << "Input how long the object should fall :" << endl;
    cin >> time;
    
    //Calculate the distance the object fell:
    dist = (acc *(time * time)) / 2;
    
    //Display Output:
    cout << "The object fell for " << time << "s" << endl;
    cout << "The acceleration due gravity = " << static_cast<int>(acc) << "ft/s" << endl;
    cout << "The the distance the object fell = " << dist << " feet" << endl;
    
    //Exit Program
    
    return 0;
}