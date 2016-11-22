/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 14, 2016, 7:10 PM
 * Purpose : Find numbers larger than n
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Random
#include <ctime>      //Time
#include <iomanip>    //Format
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void Large(int [], int, int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 100;   //Size of the Array.
    int num[100],           //Array to store the test numbers.
        n,                  //The number to compare against.
        utilize;            //The amount of the array being utilized
    
    //Input values
    cout << "This program will compare an array of numbers against a user input number" << endl << endl;
    cout << "Input the number you would like to compare against (1-8):" << endl;
    cin >> n;
    do{
        cout << "Input how many number you would like to test: (between 2 and 99)" << endl;
        cin >> utilize;
    }while (utilize < 0);
    //Fill the array
    for (int i = 0; i < utilize; i++){
        num[i] = rand()%9 + 1;
    }
    
    //Display Output
    Large(num, n, utilize);

    //Exit Program
    return 0;
}

void Large(int num[], int n, int utilize){
    cout << "The numbers greater than n in this array are:" << endl;
    for (int i = 0; i < utilize; i++){
        if (num[i] > n){
            cout << num[i] << setw(2);
        }
    }
    cout << endl;
}