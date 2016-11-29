/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 24, 2016, 11:46 AM
 * Purpose: Determine the number of times a number appears in an array
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void fill(int [], int);
void filvctr(vector<int> &);
void sort(int [], int);
int srch(int [], int, int, int &);
void prnt(int [], int);
void disTbl(vector<int>, vector<int>);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed:
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE=100;
    int n=50,           //Amount of spaces used.
        numList[SIZE],  //The Number list to search.
        i=0,            //counter and used to break out of the loop
        c=0,            //The counter
        val;            //The Value to search for.
    vector<int> dups(SIZE),     //The duplicates 
                list(SIZE);     //The number of times the duplicates appear   
        
    
    //Input values
    fill(numList, n);

    
    //Sort the array
    sort(numList, n);
    
    //Display Sorted Array
    prnt(numList, n);
    
    //Fill in the two vectors
    do{
        val = numList[i];
        dups[c] = val;
        list[c] = srch(numList,n,val,i); 
        c+=1;
    }while (i<50);
    
    //Display Table 
    disTbl(dups, list);
    
    //Exit Program
    return 0;
}

//Fill the list with random numbers:
void fill(int numList[], int n){
    for (int i=0; i<n; i++){
        numList[i] = rand()%90+10;
    }
}

//Sort the list:
void sort(int a[], int size){
        for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]>a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

//Print the array:
void prnt(int a[],int n){
    cout<<"The Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==9)cout<<endl;
    }
    cout<<endl;
}

//Search for duplicates
int srch(int a[], int n, int v, int &i){
    int j = 0;
    for (int k=i; k<50; k++){
        if(v == a[k]) j+=1;
        else{
            return j;
        }
        i++;
    } 
    return j;
}

//Display table of data
void disTbl(vector<int> a, vector<int> b){
    cout << "N    Count" << endl;
    for (int k=0; k<a.size(); k++){
        if (b[k] != 0) cout << a[k] << setw(5) << b[k] << endl;
        
    }
}

