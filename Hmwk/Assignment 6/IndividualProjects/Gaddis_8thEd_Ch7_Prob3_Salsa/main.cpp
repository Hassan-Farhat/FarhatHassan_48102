/*
 * File:   main.cpp
 * Author: Hassan
 * Created on November 14, 2016, 6:03 PM
 * Purpose : Determine salsa sales and the best and worse sale.
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <string>
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void Sales(int [], string [], int, int &);
void Best(int [], string [], int);
void Worst(int [], string [], int);
void Report(int [], string [], int, int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const int SIZE = 5;     //Size of the Array
    int utilize = SIZE,     //How much of the array is utilized
        totSales = 0;       //The total number of jars sold
    string types[] = {" Medium", "Mild", "Sweet", "Hot", "Zesty"};   //The types of salsa there are
    int sales[utilize];     //The sales of each type of salsa
    
    //Input values
    Sales (sales, types, utilize, totSales);  
    
    ////Display the table and the total sales
    Report(sales, types, utilize, totSales);
    
    //Find and display the best and worst sellers
    Best(sales, types, utilize);
    Worst(sales, types, utilize);
    
    //Exit Program
    return 0;
}

//Fill in the sales numbers with information:
void Sales(int sales[], string types[], int n, int &totSales){
    cout << "This program will let you catalog your salsa sales." << endl;
    cout << "Once you are done you will be presented a report" << endl << endl;
    for (int i = 0; i < n; i++){
        do{
            cout << "Input the number of " << types[i] << " jars sold: ";
            cin >> sales[i];
            totSales += sales[i];
        } while (sales[i] < 0);
    }
}

//Display the sales report:
void Report(int sales[], string types[], int n, int totSales){
    for (int i = 0; i < n; i++){
        cout << types[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << setw(5) << sales[i];
    }
    cout << endl;
}


//Sort for the best sales:
void Best(int sales[], string types[], int n){
    int max;
    string best;
    max = sales[0];
    best = types[0];
    for (int i = 1; i < n; i++){
        if (sales[i] > max){
            max = sales[i];
            best = types[i];
        }
    }
    cout << "The salsa with the best sales was " << best << " it sold " << max << " jars" << endl;
}

//Sort for the worst sales:
void Worst(int sales[], string types[],int n){
    int min;
    string worst;
    min = sales[0];
    worst = types[0];
    for (int i = 1; i < n; i++){
        if (sales[i] < min){
            min = sales[i];
            worst = types[i];
        }
    }
    cout << "The salsa with the worst sales was " << worst << " it sold " << min << " jars" << endl;
}