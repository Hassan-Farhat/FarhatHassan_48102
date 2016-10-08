/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 7, 2016, 1:46 PM
 * Purpose : Calculate the average rain fall over some years
 */

#include <cstdlib>

using namespace std;

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    unsigned short numYr, i, k;              //Number of years to test, (i) counter for outer loop, (k) counter for inner loop
    float rainfall=0, avRfall, rfall;  //(rainfall) user input, average rainfall over all years, (rfall) is a storage value 
    
    //Input values and the nested loops
    cout << "Input number of years you want to test :" <<endl;
    cin >> numYr;
    for (i = 1; i <= numYr; i++){
        for (k = 1; k <= 12; k++){
            cout << "Input floating point values for the rain fall of each month" << endl;
            if (k == 1){
                cout << "Rainfall of the " << k << " st month" <<endl;
                cin >> rfall;
                rainfall = rainfall + rfall;
            }
            else if (k == 2){
                cout << "Rainfall of the " << k << " nd month" <<endl;
                cin >> rfall;
                rainfall = rainfall + rfall;
            }
            else if (k == 3){
                cout << "Rainfall of the " << k << " rd month" <<endl;
                cin >> rfall;
                rainfall = rainfall + rfall;
            }
            else {
                cout << "Rainfall of the " << k << " th month" <<endl;
                cin >> rfall;
                rainfall = rainfall + rfall;
            }
        }
    }
    avRfall = rainfall/(numYr*12);
    cout << "=======================================================" << endl;
    cout << setprecision(2) << fixed;
    cout << "The average rain fall of this interval was: " << avRfall << endl;
    //Exit Program
    return 0;
}