/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 21, 2016, 8:03 PM
 * Purpose : Simple addition math tutor
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>
#include <ctime>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
     srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of Variables
     unsigned short x, //First random number
                    y, //Second random number
                    sum,
                    answer;
     
    //Process values -> Map inputs to Outputs
    x = rand()%900 + 100;
    y = rand()%900 + 100;
    sum = x+y;
            
    //Display question
    cout << "    " << x << endl;
    cout << "  + " << y << endl;
    cout << "  -------" << endl;
    
    //Input values:
    cout << "Enter answer:" << endl;
    cin >> answer;
    
    //Display output
    cout << "You answer was " << (answer == sum?"Correct":"Incorrect") << endl;
    cout << "The answer is " << sum << endl;
            
    //Exit Program
    return 0;
}
