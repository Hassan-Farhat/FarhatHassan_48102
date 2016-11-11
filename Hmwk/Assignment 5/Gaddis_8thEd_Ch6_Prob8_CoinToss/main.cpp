/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 6, 2016, 10:24 AM
 * Purpose : Coin flip program
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>
#include <ctime>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void Output(int, int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast <unsigned int> (time(0)));
    
    //Declaration of Variables
    int flips, face; //Number of coin flips, and the face of the coin
    //Input values
    do{
        cout << "Input number of coin flips:" << endl;
        cin >> flips;
    }while (flips <= 0);
    
    //Loop number of flips and output the display
    for (int i = 1; i<=flips; i++){
        face = rand()%2 + 1;
        Output(face, i);
    }

    //Exit Program
    return 0;
}

//The Determine if its heads or tails and output the face
void Output(int face, int i){
    cout << "Flip " << i << " : "; 
    if(face == 1) cout << "Heads" << endl;
    else cout << "Tails" << endl;
}