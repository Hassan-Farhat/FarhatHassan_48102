/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 28, 2016, 5:56 PM
 * Purpose: Sort a array of strings
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <string>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void Select(string[], int);
void PntName(string[]);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const int SIZE = 12;
    string names[SIZE]={"Hassan","Peter","Jesse","James","Mohammed","Osama",
                        "David","Phillip","Philip","Felix","Ali", "Sam"};
    int n=12;
    
    //Display unsorted array
    PntName(names);
    
    //Sort he array
    Select(names,n);
    
    //Display Sorted Array:
    cout << endl;
    PntName(names);
    cout << endl;
    //Exit Program
    return 0;
}

//Select sort:
void Select(string b[], int n){
    string minV;     //Minimum Index, Minimum Value
    int minI;
    for(int s = 0; s < n-1; s++){
        minI = s;
        minV = b[s];
        for(int i = s+1; i<n; i++){
            if (b[i]<minV){
                minV = b[i];
                minI = i;
            }
        }
        b[minI] = b[s];
        b[s] = minV;
    }
}

void PntName(string names[]){
    for (int i=0; i<12; i++){
        cout << names[i] << " ";
        if ((i+1)%4==0) cout << endl;
    }
}