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
int nameSch(string[], int, string);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const int SIZE = 12;
    string names[SIZE]={"Hassan","Peter","Jesse","James","Mohammed","Osama",
                        "David","Phillip","Philip","Felix","Ali", "Sam"},
            name;           //Name to search for
    int n=12, loc;
    
    //Sort he array
    Select(names,n);
    
    //Enter the name to search for:
    cout<<"What name are you looking for?"<<endl;
    cin >> name;
    
    //Search for the name
    loc = nameSch(names, n, name);
    
    //Display Output:
    if (loc == -1){ 
        cout << "We were unable to find the name in the list." << endl;
        cout << "This is the list of names:" << endl;
        PntName(names);
    }
    else cout<<"We found the name: " << names[loc] << endl;
    
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

//Print the array
void PntName(string names[]){
    for (int i=0; i<12; i++){
        cout << names[i] << "  ";
        if ((i+1)%4==0) cout << endl;
    }
}

//Search for the name:
int nameSch(string a[], int n, string t){
    int first = 0,             // First array element       
        last = 11 - 1,         // Last array element       
        middle,                // Mid point of search       
        pos = -1;              // Position of search value
    do{ 
        middle = (first+last)/2;    //Calculate the middle point
        if (a[middle]==t){
            pos = middle;
            return pos;
        }
        else if (a[middle] > t) last = middle-1;
        else first = middle+1;
    }while (first <= last);
    return -1;
}