/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 12, 2016, 4:53 PM
 * Purpose : Display a bar graph representing sales
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
    int sales1,  //Sales of store 1
        sales2,  //Sales of store 2
        sales3,  //Sales of store 3
        sales4,  //Sales of store 4
        sales5,  //Sales of store 5
        sGraph1, //Number of *s in graph of store 1
        sGraph2, //Number of *s in graph of store 2
        sGraph3, //Number of *s in graph of store 3
        sGraph4, //Number of *s in graph of store 4
        sGraph5; //Number of *s in graph of store 5
    
    //Input values
    cout << "Sales of Store 1 :";
    cin >> sales1;
    cout << "Sales of Store 2 :";
    cin >> sales2;
    cout << "Sales of Store 3 :";
    cin >> sales3;
    cout << "Sales of Store 4 :";
    cin >> sales4;
    cout << "Sales of Store 5 :";
    cin >> sales5;
    
    //Process values, Loops and outputs
    sGraph1 = sales1/100;
    sGraph2 = sales2/100;
    sGraph3 = sales3/100;
    sGraph4 = sales4/100;
    sGraph5 = sales5/100;
    cout << "=============================" << endl;
    cout << "The sales of Store 1 :";
    for (int i = 1; i <= sGraph1; i++){
        cout << "*";
    }
    cout << endl << "The sales of Store 2 :";
    for (int i = 1; i <= sGraph2; i++){
        cout << "*";
    }
    cout << endl << "The sales of Store 3 :";
    for (int i = 1; i <= sGraph3; i++){
        cout << "*";
    }
    cout << endl << "The sales of Store 4 :";
    for (int i = 1; i <= sGraph4; i++){
        cout << "*";
    }
    cout << endl << "The sales of Store 5 :";
    for (int i = 1; i <= sGraph5; i++){
        cout << "*";
    }
    cout << endl;
    //Exit Program
    return 0;
}
