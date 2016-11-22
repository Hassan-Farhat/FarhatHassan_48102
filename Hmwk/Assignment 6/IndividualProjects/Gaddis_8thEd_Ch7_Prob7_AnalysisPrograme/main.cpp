/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 16, 2016, 7:57 PM
 * Purpose : Number analysis program
 */

//System Libraries Here
#include <iostream>  //I/O
#include <fstream>  //I/O
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void Fillfile(char[], int[], int &);
int LNum(int[], int);
int SNum(int[], int);
float Average(int[], int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int const SIZE=100;     //The size of the array.
    int file[SIZE];         //Array to fill with the files numbers.
    int utilize;            //Utilized portion of the array. 
    int max, min;           //The largest and smallest number in the array.
    float avg;              //The average of the numbers in the files.
    //Fill the array
    char fnfile[SIZE] = "numbers.dat";
    Fillfile(fnfile, file, utilize);
    
    //Sort through the array to find the greatest and least numbers
    max = LNum(file, utilize);
    min = SNum(file, utilize);
    avg = Average(file, utilize);
    
    //Display Output:
    cout << "The largest value in the list is " << max << endl;
    cout << "The smallest value in the list is " << min << endl;
    cout << "The average of the all the values is " << avg << endl;
    cout << "There are a total of " << utilize << " numbers in the file." 
         << endl;
    //Exit
    return 0;
}

//Sort for the largest number:
int LNum (int file[], int n){
    int max;                    //The maximum value. 
    max = file[0];
    for (int i=1; i<n; i++){
        if(file[i] > max) max = file[i];
    }
    return max;
}

//Sort for the smallest number:
int SNum (int file[], int n){
    int min;                    //The minimum value. 
    min = file[0];
    for (int i=1; i<n; i++){
        if(file[i] < min) min = file[i];
    }
    return min;
}

//The average of the file:
float Average(int file[], int n){
    int total = 0;
    for (int i=1; i<n; i++){
        total += file[i];
    }
    return static_cast<float> (total)/n;
}

//Fill the array with the numbers off of the files
void Fillfile(char fnfile[],int file[],int &n){
    //Declare variables and open the file
    ifstream in;
    n=0;
    
    //Open the stream
    in.open(fnfile);
    
    //Read in data
    while(in>>file[n++]);
    n--;
    
    //Close the file
    in.close();
}

