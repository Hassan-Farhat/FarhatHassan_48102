/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 18, 2016, 5:19 PM
 * Purpose: Lottery simulator
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Random number
#include <ctime>
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void Lottery(int [], int);
void UserNum(int [], int);
void Test(int [], int [], int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 100;            //Size of Array
    int used = 5;                    //Positions used
    int lottery[SIZE], player[SIZE]; //Lottery numbers and player numbers 
    
    //Fill in the lottery numbers:
    Lottery(lottery, used);
    UserNum(player, used);
    
    //Determine of the player wins
    Test(player, lottery, used);

    //Exit Program
    return 0;
}

//Fill in the lottery numbers:
void Lottery(int lottery[], int used){
    for (int i=0; i<used; i++){
        lottery[i]=rand()%9+1;
    }
}

//Fill in the player lottery numbers:
void UserNum(int player[], int used){
    for (int i=0; i<used; i++){
        cout << "Input 5 positive numbers" << endl;
        cin >> player[i];
    }
}

//Check if the player wins:
void Test(int player[], int lottery[], int used){
    short same=0;               //The total number similar numbers.
    cout << "The lottery numbers: ";
    for (int i=0; i<used; i++){
        cout << setw(3) << lottery[i];
        if (player[i] == lottery[i]) same += 1;
    }
    cout << endl << "The Player numbers : ";
    for (int i=0; i<used; i++){
        cout << setw(3) << player[i];
    }
    cout << endl;
    if (same == 5)cout << "YOU WIN !!";
    else{
        cout << "YOU LOST !!" << endl;
        cout << same << " numbers matched" << endl;
    }
}