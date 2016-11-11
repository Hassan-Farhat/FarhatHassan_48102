/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 6, 2016, 11:23 AM
 * Purpose: Calculate average score
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void getScore(float &,float &,float &,float &,float &);
float avgScore(float, float, float, float, float);
float Lowest(float, float, float, float, float);
float Hghest(float, float, float, float, float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float s1,s2,s3,s4,s5,       //Score 1,2,3,4
          avg;                  //Average
    
    //Input values
    getScore(s1,s2,s3,s4,s5);
    
    //Precess Values (remove the lowest and highest scores)
    avg = avgScore(s1,s2,s3,s4,s5);
    
    //Display Output
    cout << endl << "The Average score will be " << avg << endl;
    
    //Exit Program
    return 0;
}

//Get the judges scores with user input
void getScore(float &s1,float &s2,float &s3,float &s4,float &s5){
    for (int i = 1; i <= 5; i++){
        float x;         //Holder variable
        do{
            cout << "Judge " << i <<"'s score: " << endl;
            cin >> x;
        } while (x < 0);
        if (i == 1) s1 = x;
        else if (i == 2) s2 = x;
        else if (i == 3) s3 = x;
        else if (i == 4) s4 = x;
        else if (i == 5) s5 = x;
    }
}

//Find the lowest score:
float Lowest(float s1,float s2,float s3,float s4,float s5){
    float min;
    min = s1;
    if(s2 < min) min = s2;
    if(s3 < min) min = s3;
    if(s4 < min) min = s4;
    if(s5 < min) min = s5;
    return min;
}

//Find the highest score:
float Hghest(float s1,float s2,float s3,float s4,float s5){
    float max;
    max = s1;
    if(s2 > max) max = s2;
    if(s3 > max) max = s3;
    if(s4 > max) max = s4;
    if(s5 > max) max = s5;
    return max;
}

//Calculate the Average score:
float avgScore(float s1,float s2,float s3,float s4,float s5){
    return (s1+s2+s3+s4+s5 - Lowest(s1,s2,s3,s4,s5) - Hghest(s1,s2,s3,s4,s5))/3;
}
