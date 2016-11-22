/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 20, 2016, 9:08 PM
 * Purpose: Test which searching algorithm is uses less tries
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Random number
#include <ctime>      //Time
#include <iomanip>    //Formate output
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void FilList (int[], int);
void SrtList (int[], int);
void LinTest (int[], int, int);
void BinTest (int[], int, int);
void PrtList (int[], int, int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 100;
    int numList[SIZE];      //The list of random numbers
    int utilize = 20,       //The utilized portion of the array
        tValue;             //Test value
    
    //Input values
    FilList (numList, utilize);
    tValue = numList[rand()%19 + 1];
    
    //Sort
    SrtList (numList, utilize);
    
    //Linear test
    LinTest (numList, utilize, tValue);
    
    //Binary test
    BinTest (numList, utilize, tValue);
    
    //Print the array and the test value
    PrtList (numList, utilize, tValue);

    //Exit Program
    return 0;
}

//Fill the array with random numbers
void FilList(int a[], int n){
    //Fill the array with 4 digit random numbers
    for (int i=0; i<n; i++){
        a[i] = rand()%999+1;
    }
}

//Sort the array
void SrtList(int a[],int size){
    for(int i=0;i<size-1;i++){
        for(int k=i+1;k<size;k++){
            if(a[i]>a[k]){
                a[i]=a[i]^a[k];
                a[k]=a[i]^a[k];
                a[i]=a[i]^a[k];
            }
        }
    }
}

//Linear test
void LinTest(int a[], int n, int t){
    bool found = false;
    int counter = 0;
    for (int i=0; i<n, !found; i++){
        if (t == a[i]) found = true;
        counter = i+1;
    }
    cout << "The linear search took " << counter << " attempts." << endl;
}

//Binary Search
void BinTest(int a[], int n, int t){
    int counter = 0,           // Counter for the number of attempts
        first = 0,             // First array element       
        last = 11 - 1,         // Last array element       
        middle,                // Mid point of search       
        pos = -1;              // Position of search value
    bool found = false;
    do{ 
        middle = (first+last)/2;    //Calculate the middle point
        if (a[middle]==t){
            found = true;
            pos = middle;
        }
        else if (a[middle] > t) last = middle-1;
        else first = middle+1;
        counter += 1;
    }while (found == false && first <= last);
    cout << "The binary search took " << counter << " attempts." << endl;
}

//Print the number list and its test value:
void PrtList(int a[], int n, int t){
    for (int i=0; i<n; i++){
        cout << setw(4) << a[i];
        if ((i+1)%4 == 0) cout << endl;
    }
    cout << endl << "The number being searched for is " << t << endl;
}
