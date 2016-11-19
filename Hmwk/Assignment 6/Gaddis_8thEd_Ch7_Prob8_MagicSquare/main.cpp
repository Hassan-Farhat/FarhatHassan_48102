/*
 File:   main.cpp
 Author: Hassan Farhat
 Created on November 15, 2016, 7:27 PM
 Purpose : Create and determine if the randomly generated square is a Lo Shu Square
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Random
#include <ctime>      //Time
#include <iomanip>    //Format
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int COLS = 3;

//Function prototypes
void FillSqr (int [][COLS], int);
int Check (int [][COLS], int);
void DplySqr (int [][COLS], int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 3;     //Size of the array
    int square[SIZE][COLS]; //The Magic square two dimensional array
    int check,              //The check to determine if the array is a magic square
        used = 3;
    
    //Input values
    FillSqr(square, used);
    
    //Display the square:
    DplySqr (square, used);
    
    //Process values 
    check = Check(square, used);
    
    //Display Output
    if (check = 0) cout << "This is a Lu Shu magic square!" << endl;
    else cout << "This is not a Lu Shu magic square." << endl;

    //Exit Program
    return 0;
}

//Fill the Square with random variables:
void FillSqr (int square[][COLS], int used){
    for (int i=0; i<used; i++){
        for (int k=0; k<COLS; k++){
            square[i][k]=rand()%9 + 1;
        }
    }
}

//Check the if it is a Lo Shu Square:
int Check (int square[][COLS], int used){
    int d1,d2,      //The sum of each diagonals of the square.
        v1,v2,v3,   //The sum of each verticals (col) of the square.
        h1,h2,h3;   //The sum of each horizonals (rows) of the square.
    h1 = square[0][0] + square[0][1] + square[0][2];
    h2 = square[1][0] + square[1][1] + square[1][2];
    h3 = square[2][0] + square[2][1] + square[2][2];
    v1 = square[0][0] + square[1][0] + square[2][0];
    v2 = square[0][1] + square[1][1] + square[2][1];
    v3 = square[0][2] + square[1][2] + square[2][2];
    d1 = square[2][0] + square[1][1] + square[0][2];
    d2 = square[0][0] + square[1][1] + square[2][2];
    cout << "Diagonal 1 = " << d1 << endl << "Diagonal 2 = " << d2 << endl
         << "Column 1 = " << v1 << endl << "Column 2 = " << v2 << endl 
         << "Column 3 = " << v3 << endl << "Row 1 = " << h1 << endl 
         << "Row 2 = " << h2 << endl << "Row 3 = " << h3 << endl;    
    if ((d1==d2)&&(d1==v1)&&(d1==v2)&&(d1==v3)&&(d1==h1)&&(d1==h2)&&(d1==h3)) return 1;
    else return 0;
}

//Display the square
void DplySqr (int square[][COLS], int used){
    for (int i=0; i<used; i++){
        for (int k=0; k<COLS; k++){
            cout << setw(2) << square[i][k];
        }
        cout << endl;
    }
}