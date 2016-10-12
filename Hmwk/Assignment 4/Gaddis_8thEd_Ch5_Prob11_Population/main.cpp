/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 9, 2016, 12:50 PM
 * Purpose : Calculate the population
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float popinc, pPopinc;      //Daily population increase and Daily population increase in percent
    unsigned short numDays,     //Number of days to test
                   pop,         //Population
                   inPop;       //the increase of population of that day
                   

    //Input values
    cout << "Input the percentage growth per day (no negatives) :" << endl;
    cin >> pPopinc;
    while (pPopinc < 0){
        cout << "Input the growth again :" << endl;
        cin >> pPopinc;
    }
    popinc = pPopinc / 100;
    
    cout << "Input the starting population (greater than or equal two):" << endl;
    cin >> pop;
    while (pop < 2){
        cout << "Starting population to small re-input the population (>=2):" << endl;
        cin >> pop;
    }
    
    cout << "Input the the number of dates to test (>=1):" << endl;
    cin >> numDays;
    while (numDays < 1){
        cout << "Input a number that is equal to or greater than or equal to one:" << endl;
        cin >> pPopinc;
    }
            
    //Process values and Display Output
    cout << "The population of day 1 is " << pop << " Organisms" << endl;
    
    for (int i=2; i<=numDays; i++){
        inPop = pop * popinc;
        pop = inPop + pop;
        cout << "The population of day " << i << " is " << pop << " Organisms"  << endl;
    }

    //Exit Program
    return 0;
}

