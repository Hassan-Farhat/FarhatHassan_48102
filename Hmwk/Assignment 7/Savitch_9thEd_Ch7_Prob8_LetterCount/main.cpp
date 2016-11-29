/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 23, 2016, 5:21 PM
 * Purpose: List the amount of times a letter was used in the code.
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <string>
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void Letters(char[]);
int search(string, char);
void pntTbl(string, char[], int[]);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const int SIZE = 100;
    string text;
    char letters[SIZE],
         val;
    int occ[SIZE];
    
    //Input values
    cout << "Input a line of text:" << endl;
    getline(cin,text);
    
    //Fill with all 26 letters:
    Letters(letters);
    
    //Fill in the occurrences:
    for (int i=0; i<26; i++){
        occ[i]=0;
        val = letters[i];
        occ[i]=search(text, val);
    }
    
    //Display Output
    pntTbl(text,letters,occ); 
    
    //Exit Program
    return 0;
}

//Fill the array with the 26 letters:
void Letters(char l[]){
    for (int i=0; i<26; i++){
        l[i]=97+i;
    }
}

//Search and fill:
int search(string t, char val){
    int count = 0;
    bool period = false;
    for (int i=0; i<t.size() && period==false; i++){
        if(t[i] == val){
            count+=1;
        }
        else if(t[i]=='.') period=true;
    }
    return count;
}

void pntTbl(string t, char l[], int o[]){
    bool period = false;
    for (int i=0; i<t.size() && period == false; i++){
        if(t[i]=='.') period=true;
        else cout << t[i];
    }
    cout << endl;
    cout << "Letter   Occurrences" << endl;
    for (int i=0; i<26; i++){
        if (o[i] > 0) cout << setw(3) << l[i] << setw(11) << o[i] << endl;
    }
    cout << endl;
}