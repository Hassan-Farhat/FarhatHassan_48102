/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 10, 2016, 2:26 PM
 * Purpose: Random number game
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Random number seed
#include <ctime>      //Seed the random number    
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Seed the random number
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of Variables
    int x = rand()%40 + 11, //The random number for the user to find (1->50)
        num,                //The user input guesses
        i=0;                //The counter
    
    //Process values
    cout << "This is a random number game type in your first guess: ";
    cin >> num;
    while (num != x){
        i++;
        if (num < x){
            cout << "Too low, try again" << endl;
            cin >> num;
        }
        else{
            cout << "Too high, try again" << endl;
            cin >> num;
        }
    }
    //Display Output
    cout << "===============================" << endl;
    cout << "YOUR GUESS WAS CORRECT" << endl;
    cout << "Your last guess = " << num << endl;
    cout << "The random number = " << x << endl;
    cout << "It took you " << i << " guesses to get the right answer." << endl;
    
    //Exit Program
    return 0;
}
