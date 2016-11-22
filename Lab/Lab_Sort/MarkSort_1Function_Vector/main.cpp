/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 17, 2016, 11:08 AM
 * Purpose: Combine the 3 functions.
 */

//System Libraries Here
#include <iostream>  //I/O
#include <cstdlib>   //Random
#include <ctime>     //Time
#include <vector>    //Vector
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void fillVtr(vector<int> &,int);
void prntVtr(vector<int> &,int);
void markSrt(vector<int> &,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int const SIZE=100;
    vector<int> array(SIZE);
    int utilize;
    
    //Input or initialize values Here
    do{
        cout<<"How much of the array to utilize?"<<endl;
        cout<<"Choose a number between 2 and 100"<<endl;
        cin>>utilize;
    }while(utilize<2||utilize>100);
    
    //Fill the array
    fillVtr(array,utilize);
    
    //Output Located Here
    prntVtr(array,utilize);
    
    //Test out minPos
    markSrt(array,utilize);
    
    //Output Located Here
    prntVtr(array,utilize);

    //Exit
    return 0;
}

void markSrt(vector<int> &a,int size){
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

void prntVtr(vector<int> &a,int n){
    //Output Located Here
    cout<<"The Vector"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==9)cout<<endl;
    }
    cout<<endl;
}

void fillVtr(vector<int> &a,int n){
    //Fill the array
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//Random 2 digit number
    }
}

