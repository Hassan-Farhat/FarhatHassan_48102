/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 21, 2016, 9:04 PM
 * Purpose: Benchmark test for the different search types
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
void FillAry(int[], int[], int[], int);
void Bubble(int[], int, int &);
void Select(int[], int, int &);
void MrkSort(int[], int, int &);
void PntArys(int[], int[], int[], int, int, int, int);
void PntArys(int[], int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed:
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 100;       //Size of the array.
    int bTest[SIZE],            //Bubble sort test array.
        sTest[SIZE],            //Select sort test array.
        mTest[SIZE];            //Mark sort test array.
    int utilize = 20,           //Utilized portion of array.
        c1,
        c2,
        c3;
    
    //Input values
    FillAry(bTest, sTest, mTest, utilize);
    
    //Print unsorted array:
    PntArys(bTest, utilize);
    
    //Bubble sort test
    Bubble(bTest, utilize, c1);
    
    //Select sort test
    Select(sTest, utilize, c2);
    
    //Mark sort test
    MrkSort(mTest, utilize, c3);
    
    //Display the sorted arrays
    PntArys(bTest, sTest, mTest, utilize, c1, c2, c3);
    
    //Exit Program
    return 0;
}

//Fill the three arrays with 20 random 2 digit numbers:
void FillAry(int a[], int b[], int c[], int n){
    for (int i=0; i<n; i++){
        a[i] = rand()%99+1;
        b[i] = a[i];
        c[i] = b[i];
    } 
}

//Bubble sort:
void Bubble(int a[], int n, int & counter){
    bool swap;
    int temp;
    counter=0;
    do{
        swap = false;
        for(int i=0; i<(n-1); i++){
            if (a[i]>a[i+1]){
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                swap = true;
                counter += 1;
            }
        }
    }while(swap);
    cout << "Bubble sort made " << counter << " switches" << endl;
}

//Select sort:
void Select(int b[], int n, int & counter){
    int minI, minV;     //Minimum Index, Minimum Value
    counter = 0;
    for(int s = 0; s < n-1; s++){
        minI = s;
        minV = b[s];
        for(int i = s+1; i<n; i++){
            if (b[i]<minV){
                minV = b[i];
                minI = i;
                counter += 1;
            }
        }
        b[minI] = b[s];
        b[s] = minV;
    }
    cout << "Select sort made " << counter << " switches" << endl;
}

//Mark sort:
void MrkSort(int c[], int n, int & counter){
    counter = 0;
    for(int i=0;i<n-1;i++){
        for(int k=i+1;k<n;k++){
            if(c[i]>c[k]){
                c[i]=c[i]^c[k];
                c[k]=c[i]^c[k];
                c[i]=c[i]^c[k];
                counter += 1;
            }
        }
    }
    cout << "Mark sort made " << counter << " switches" << endl;
}

//Print the unsorted arrays:
void PntArys(int a[], int n){
    cout << "The array the sorting algorithms must sort :" << endl;
    for (int i = 0; i < n; i++){
        cout << setw(3) << a[i];
        if ((i+1)%4 == 0) cout << endl;
    }
    cout << endl;
}

//Print the arrays:
void PntArys(int a[], int b[], int c[], int n, int c1, int c2, int c3){
    cout << endl << "Bubble sort :" << c1 << " switches" << endl;
    for (int i = 0; i < n; i++){
        cout << setw(3) << a[i];
        if ((i+1)%4 == 0) cout << endl;
    }
    cout << endl;
    
    cout << "Select sort :" << c2 << " switches" << endl;
    for (int i = 0; i < n; i++){
        cout << setw(3) << b[i];
        if ((i+1)%4 == 0) cout << endl;
    }
    cout << endl;
    
    cout << "Bubble sort :" << c3 << " switches" << endl;
    for (int i = 0; i < n; i++){
        cout << setw(3) << c[i];
        if ((i+1)%4 == 0) cout << endl;
    }
    cout << endl;
}


