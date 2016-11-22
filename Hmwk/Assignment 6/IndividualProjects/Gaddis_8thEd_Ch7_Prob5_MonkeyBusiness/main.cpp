/*
 * File:   main.cpp
 * Author: Hassan
 * Created on November 14, 2016, 7:48 PM
 * Purpose : Catalog how much the monkeys ate
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <string>     //Names
#include <cstdlib>    //Random
#include <ctime>      //Time
#include <iomanip>    //Format
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int NUMDAYS = 5;

//Function prototypes
void Eaten(int [][NUMDAYS], int, int &);
void Most(string [], int [][NUMDAYS]);
void Least(string [], int [][NUMDAYS]);
void DietRprt (string [], int [][NUMDAYS], int, float, int);

//Execution Begins Here!
int main(int argc, char** argv){
    //Set random number seed:
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of Variables
    const int ROWS = 3;         //The rows of the array
    int food[ROWS][NUMDAYS],    //The the food eaten by each gorilla (in lbs)
        totFood = 0,            //The total amount of food eaten (in lbs)
        used = ROWS;            //The number of rows used
    float avg;                  //The average amount of food eaten (in lbs)
    string names[] = {"Yesse  ", "Coco   ", "Harambe"};  //The names of the gorillas
    
    //Input values
    Eaten(food, used, totFood);
    
    //Display the report
    DietRprt (names, food, used, avg, totFood);
    
    //Process values -> Map inputs to Outputs
    Most(names, food);
    Least(names, food);
    
    
    //Exit Program
    return 0;
}

//Fill the array for the food eaten:
void Eaten(int food[][NUMDAYS], int n, int &total){
    for (int i = 0; i < n; i++){
        for (int k = 0; k < NUMDAYS; k++){
            food[i][k] = 36 + rand()%9;
            total += food[i][k];
        }
    }
}

//Display the report:
void DietRprt (string names[], int food[][NUMDAYS], int n, float avg, int total){
    avg = total/15.0;
    for (int i = 0; i < n; i++){
        cout << names[i] << ": ";
        for (int k = 0; k < NUMDAYS; k++){
            cout << setw(3) << food[i][k];
        }
        cout  << " in lbs of food." << endl;
    }
    cout << "The total amount of food eaten by the monkeys in that week = " 
         << total << endl;
    cout << "The average amount of food eaten by the monkeys in that week = "
         << avg << endl;
}

void Most(string name[], int food[][NUMDAYS]){
    const int SIZE = 3;
    int mtot[SIZE] = {};//Array that stores the number of food eaten by each monkey
    int max;            //Place holder maximum
    string mName;       //name of monkey in maximum position
    for (int i = 0; i < NUMDAYS; i++){
        mtot[0] += food[0][i];
    }
    for (int i = 0; i < NUMDAYS; i++){
        mtot[1] += food[1][i];
    }
    for (int i = 0; i < NUMDAYS; i++){
        mtot[2] += food[2][i];
    }
    max = mtot[0];
    mName = name[0];
    for (int i = 1; i < 3; i++){   
        if (mtot[i] > max){
            max = mtot[i];
            mName = name[i];
        }
    }
    cout << "The monkey that ate the most that week was " << mName << " with " << max << " lbs eaten" << endl;
}

void Least(string name[], int food[][NUMDAYS]){
    const int SIZE = 3;
    int ltot[SIZE]= {};  //Array that stores the number of food eaten by each monkey
    int min;        //Place holder maximum
    string mName;   //name of monkey in maximum position
    for (int i = 0; i < NUMDAYS; i++){
        ltot[0] += food[0][i];
    }
    for (int i = 0; i < NUMDAYS; i++){
        ltot[1] += food[1][i];
    }
    for (int i = 0; i < NUMDAYS; i++){
        ltot[2] += food[2][i];
    }
    min = ltot[0];
    mName = name[0];
    for (int i = 1; i < 3; i++){   
        if (ltot[i] < min){
            min = ltot[i];
            mName = name[i];
        }
    }
    cout << "The monkey that ate the least that week was " << mName << " with " << min << " lbs eaten" << endl;
}
