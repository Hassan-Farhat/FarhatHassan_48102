/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 8, 2016, 3:26 PM
 * Purpose : Determine distance taveled
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
    float dist, speed;    //Distance, speed of the train 
    int i, numhr;         //Loop counter and number of hours traveled
    
    //Input values
    cout << "What was the speed of the train?" << endl;
    cin >> speed;
    cout << "How hour many hours did the train tavel?" << endl;
    cin >> numhr;
    
    //Process values and display output
     cout << "--------------------" << endl;
    for(i=1;i<=numhr;i++){
        dist = speed * i;
        cout << i << "             " << dist << endl;
    }

    //Exit Program
    return 0;
}

