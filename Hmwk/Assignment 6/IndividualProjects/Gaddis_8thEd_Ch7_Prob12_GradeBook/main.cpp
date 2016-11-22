/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 18, 2016, 4:17 PM
 * Purpose : Grade Book program
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <string>     //String array
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int GRADES = 4;

//Function prototypes
void FillGrd (int [][GRADES], int [], char [], int);
void DplyGrd (int [][GRADES], int [], char [], string [], int);
void FillNms (string [], int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed:
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 100;       //Size of the array
    int utilize = 5;            //Number of utilized positions in the array
    int grades [SIZE][GRADES];  //Grades of the students
    int fGrade [SIZE];          //Final grade of the students
    char letter [SIZE];         //Letter grade of the students
    string names [SIZE];        //Names of the students
    
    //Input values
    FillNms (names, utilize);
    FillGrd(grades, fGrade, letter, utilize);
    
    //Display Output
    DplyGrd(grades, fGrade, letter, names, utilize);
    
    //Exit Program
    return 0;
}

//Fill array:
void FillGrd(int grades[][GRADES], int fGrade[], char letter[], int utilize){
    int total = 0;      //Total score of each student
    for (int i = 0; i < utilize; i++){  //Fill the grades
        for (int k = 0; k < GRADES; k++){
            grades[i][k] = rand()%99 + 1;
        }
    }
    for (int i = 0; i < utilize; i++){  //Calculate the final store
        total = 0;
        for (int k = 0; k < GRADES; k++){ 
            total += grades[i][k];
        }
        fGrade[i] = total/4;
    }
    for (int i = 0; i < utilize; i++){  //Letter grade
        if (fGrade[i] >= 90) letter[i] = 'A';
        else if (fGrade[i] >= 80 && fGrade[i] <= 89) letter[i] = 'B';
        else if (fGrade[i] >= 70 && fGrade[i] <= 79) letter[i] = 'C';
        else if (fGrade[i] >= 60 && fGrade[i] <= 69) letter[i] = 'D';
        else if (fGrade[i] <= 59) letter[i] = 'F';
    }
}

//Fill in the names:
void FillNms(string name[], int utilize){
    for (int i = 0; i < utilize; i++){
        cout << "Input the name of each student first name only" << endl;
        cin >> name[i];
    }
}

void DplyGrd (int grades[][GRADES], int fGrade[], char letter[], string name[], int utilize){
    for (int i = 0; i < utilize; i++){
        cout << name[i] << ":" <<endl<< "Test scores: ";
        for (int k = 0; k < GRADES; k++){
            cout << grades[i][k] << setw(3);
        }
        cout << "    Final score: " << setw(3) << fGrade[i];
        cout << "   " << letter[i] << endl;
    }
}