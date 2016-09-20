/*
 * File:   main.cpp
 * Author: rcc
 * Created on September 20, 2016, 11:29 AM
 * Purpose : Iteration to find the square root
 */
//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const float MAXRAND = pow(2,31)-1; // Max signed positive value for int

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    float n,guess,r;
    float scale=90,shift=10;
    unsigned short counter = 0;
    
    //Input values - float random number (10,100) vs.
    //               integer random rand()%scale + shift [10,100]
    n=rand()/MAXRAND*scale+shift;
    guess = n/2;
    
    //Process values -> Map inputs to Outputs
    cout << "The number to find the square root of = " << n << endl;
    cout << "The initial guess = " << guess << endl;
    
    //First Pass
    r=n/guess;
    guess = (guess+r)/2;
    counter += 1;
    
    //Display Output
    cout << fixed << showpoint << setprecision(4);
    cout <<"Pass " << counter << " [r,guess]=["<< setw(7) << r << "," << guess << "]" << endl;
    
     //Next Pass
    r=n/guess;
    guess = (guess+r)/2;
    counter += 1;
    
    //Display Output
    cout << fixed << showpoint << setprecision(4);
    cout <<"Pass " << counter << " [r,guess]=["<< setw(7) << r << "," << guess << "]" << endl;
    
    //Next Pass
    r=n/guess;
    guess = (guess+r)/2;
    counter += 1;
    
    //Display Output
    cout << fixed << showpoint << setprecision(4);
    cout <<"Pass " << counter << " [r,guess]=["<< setw(7) << r << "," << guess << "]" << endl;
    
    //Next Pass
    r=n/guess;
    guess = (guess+r)/2;
    counter += 1;
    
    //Display Output
    cout << fixed << showpoint << setprecision(4);
    cout <<"Pass " << counter << " [r,guess]=["<< setw(7) << r << "," << guess << "]" << endl;
     
    //Next Pass
    r=n/guess;
    guess = (guess+r)/2;
    counter += 1;
    
    //Display Output
    cout << fixed << showpoint << setprecision(4);
    cout <<"Pass " << counter << " [r,guess]=["<< setw(7) << r << "," << guess << "]" << endl;
     
    //Next Pass
    r=n/guess;
    guess = (guess+r)/2;
    counter += 1;
    
    //Display Output
    cout << fixed << showpoint << setprecision(4);
    cout <<"Pass " << counter << " [r,guess]=["<< setw(7) << r << "," << guess << "]" << endl;
     
    //Next Pass
    r=n/guess;
    guess = (guess+r)/2;
    counter += 1;
    
    //Display Output
    cout << fixed << showpoint << setprecision(4);
    cout <<"Pass " << counter << " [r,guess]=["<< setw(7) << r << "," << guess << "]" << endl;
    
    //The answer or solution is:
    cout << "The sqrt("<<n<<")="<<sqrt(n)<<endl;


    //Exit Program
    return 0;
}
