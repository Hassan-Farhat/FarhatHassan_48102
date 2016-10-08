/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 6, 2016, 12:27 PM
 * Purpose : Rock Paper Scissors
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Ramdom number generator
#include <ctime>      //Time
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    char computr;  //Computer choice
    char rPlay;    //Player choice
    
    //Input computer values
    computr=rand()%4+80;
    while(computr == 'Q'){
        computr = rand()%4+80;
    }
    
    //Input Player values
    cout << "Input your choice: " << endl;
    cin >> rPlay;
    switch(rPlay){
        case 'r':
        case 'R': rPlay='R'; break;
        case 's':
        case 'S': rPlay='S'; break;
        default : rPlay='P'; break;
    }
    
    //Display output:
    cout << "The computer plays " << computr << endl;
    cout << "The player plays " << rPlay << endl;
    
    //Determine the winner
    if(computr == rPlay){
        cout << "ITS A TIE" << endl;
    }
    else if(computr == 'P'){
        if(rPlay=='S')cout << "THE PLAYER WINS" << endl;
        else cout << "THE COMPUTER WINS" << endl;
    }
    else if(computr == 'S'){
        if(rPlay=='R')cout << "THE PLAYER WINS" << endl;
        else cout << "THE COMPUTER WINS" << endl;
    }
    else if(computr == 'R'){
        if(rPlay=='P')cout << "THE PLAYER WINS" << endl;
        else cout << "THE COMPUTER WINS" << endl;
    }
    

    //Exit Program
    return 0;
}
