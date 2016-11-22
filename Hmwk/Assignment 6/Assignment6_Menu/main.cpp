/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 13, 2016, 5:06 PM
 * Purpose : Menu with all the Assignment 6 answers.
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //For output manipulation
#include <string>
#include <cstdlib>    //Random number  
#include <ctime>      //Time
#include <fstream>    //I/O
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int NUMDAYS = 5;
const int COLS = 3;
const int GRADES = 4;

//Function prototypes
void FillAry(int [], int);
void Largest(int [], int);
void Smallest(int [], int);
void FillRain (int[], int);
void HRain (int[], int);
void LRain (int[], int);
void DplyRain (int [], int);
void Sales(int [], string [], int, int &);
void Best(int [], string [], int);
void Worst(int [], string [], int);
void Report(int [], string [], int, int);
void Large(int [], int, int);
void Eaten(int [][NUMDAYS], int, int &);
void Most(string [], int [][NUMDAYS]);
void Least(string [], int [][NUMDAYS]);
void DietRprt (string [], int [][NUMDAYS], int, float, int);
void Fillfile(char[], int[], int &);
int LNum(int[], int);
int SNum(int[], int);
float Average(int[], int);
void FillSqr (int [][COLS], int);
int Check (int [][COLS], int);
void DplySqr (int [][COLS], int);
void InHrsPR (int [], int[], float [], char);
void Wages (float [], float [], int [], char);
void EReport (float [], float [], int [], int [], char);
void Lottery(int [], int);
void UserNum(int [], int);
void Test(int [], int [], int);
void FillGrd (int [][GRADES], int [], char [], int);
void DplyGrd (int [][GRADES], int [], char [], string [], int);
void FillNms (string [], int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int menuItm;    //Choice from menu
    
    //Loop until users exits
    do{
    
        //Prompt for problem for user input
        cout<<"1.  Type 1  for Gaddis 8thEd Ch7 Prob1 LargestSmallest"<<endl;
        cout<<"2.  Type 2  for Gaddis 8thEd Ch7 Prob2 Rainfall"<<endl;
        cout<<"3.  Type 3  for Gaddis 8thEd Ch7 Prob3 Salsa"<<endl;
        cout<<"4.  Type 4  for Gaddis 8thEd Ch7 Prob4 LargerThanN"<<endl;
        cout<<"5.  Type 5  for Gaddis 8thEd Ch7 Prob5 MonkeyBusiness"<<endl;
        cout<<"6.  Type 6  for Gaddis 8thEd Ch7 Prob7 AnalysisPrograme"<<endl;
        cout<<"7.  Type 7  for Gaddis 8thEd Ch7 Prob8 MagicSquare"<<endl;
        cout<<"8.  Type 8  for Gaddis 8thEd Ch7 Prob9 Payroll"<<endl;
        cout<<"9.  Type 9  for Gaddis 8thEd Ch7 Prob14 LotteryApp"<<endl;
        cout<<"10. Type 10 for Gaddis 8thEd Ch7 Prob12 GradeBook"<<endl;
        cin>>menuItm;

        //Go to the Problem
        switch(menuItm){
            case 1:problem1();break;
            case 2:problem2();break;
            case 3:problem3();break;
            case 4:problem4();break;
            case 5:problem5();break;
            case 6:problem6();break;
            case 7:problem7();break;
            case 8:problem8();break;
            case 9:problem9();break;
            case 10:problem10();
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<=10);//Ends the Do-While Loop

    //Exit Program
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************** Gaddis 8thEd Ch7 Prob1 LargestSmallest ********************
//Purpose:  Find the Largest/Smallest Array Value
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem1(){
    //Declaration of Variables
    const int SIZE = 10;
    int num[SIZE];
    int utilize = SIZE;
    
    //Input values
    FillAry(num, utilize);
    
    //Process values and display
    Largest(num, utilize);
    Smallest (num, utilize);
    cout << endl;
    //Exit Program
}

//Fill the Array with user input:
void FillAry(int num[], int utilize){
    cout << endl;
    for(int i = 0; i < utilize; i++){
        cout << "Input an integer: ";
        cin >> num[i];
    }
}

//Sort out the largest value entered by the user:
void Largest(int num[], int utilize){
    int max;
    max = num[0];
    for(int i = 1; i < utilize; i++){
        if (num[i] > max) max = num[i];
    }
    cout << "==================================" << endl;
    cout << "The largest number that you entered was: " << max << endl;
}

//Sort out the smallest value entered by the user:
void Smallest(int num[], int utilize){
    int min;
    min = num[0];
    for(int i = 1; i < utilize; i++){
        if (num[i] < min) min = num[i];
    }
    cout << "The smallest number that you entered was: " << min << endl;
}

//Retail price calculation:

//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch7 Prob2 Rainfall **************************
//Purpose:  RainFall Statistics
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************

void problem2(){
    //Set random number seed:
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 100;   //Size of the array
    int rain[SIZE];         //Amount of rain in inch
    int months = 12;        //Number of months
        
    //Input values, calculate, and display the average and total amount of rain fall 
    cout << endl;
    FillRain (rain, months);
    
    
    //Determine what is the highest and lowest
    HRain (rain, months);
    LRain (rain, months);
    
    //Display the array
    DplyRain (rain, months);
    
    //Exit Program
}

//Fill in the amount of rain each month and display the average and total.
void FillRain (int rain[], int months){
    int total=0;      //Total amount of rainfall
    float avg;        //Average amount of rainfall
    for (int i=0; i<months; i++){
        rain[i]=rand()%49 + 1;
        total += rain[i];
    }
    avg = total / months;
    cout << setprecision(2) << fixed << showpoint;
    cout << "The total was " << total << " inches of rain in the " << months << " month period." << endl;
    cout << "The average was " << avg << " inches of rain the " << months << " month period." << endl; 
}

//Find the highest and lowest.
void HRain (int rain[], int months){
    int max = rain[0],      //The maximum amount of rain per month.
        month = 1;          //The month with the maximum amount.
    for (int i=1; i<months; i++){
        if (rain[i] > max){
            max = rain[i];
            month = i+1;
        }
    }
    cout << "Highest month: " << month 
            << " it had " << max << " inches of rainfall." << endl;
}

void LRain (int rain[], int months){
    int min = rain[0],      //The minimum amount of rain per month.
        month = 1;          //The month with the minimum amount.
    for (int i=1; i<months; i++){
        if (rain[i] < min){
            min = rain[i];
            month = i+1;
        }
    }
    cout << "Lowest month: " << month 
            << " it had " << min << " inches of rainfall." << endl;
}

//Display the array:
void DplyRain (int rain[], int months){
    for (int i=0; i<months; i++){
        cout << "Month " << i+1 << ": " << rain[i] << " inches" << endl;
    }
    cout << endl;
}

//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//********************* Gaddis 8thEd Ch7 Prob3 Salsas **************************
//Purpose:  Determine salsa sales and the best and worse sale.
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem3(){
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
}
//Fill in the sales numbers with information:
void Sales(int sales[], string types[], int n, int &totSales){
    cout << endl << "This program will let you catalog your salsa sales." << endl;
    cout << "Once you are done you will be presented a report" << endl << endl;
    for (int i = 0; i < n; i++){
        do{
            cout << "Input the number of " << types[i] << " jars sold: ";
            cin >> sales[i];
            totSales += sales[i];
        } while (sales[i] < 0);
    }
    cout << endl;
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

//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch7 Prob4 LargerThanN *************************
//Purpose:  Check how many numbers are greater then n in the array
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem4(){
    //Set random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 100;   //Size of the Array.
    int num[100],           //Array to store the test numbers.
        n,                  //The number to compare against.
        utilize;            //The amount of the array being utilized
    
    //Input values
    cout << endl << "This program will compare an array of numbers against a user input number" << endl << endl;
    cout << "Input the number you would like to compare against (1-8):" << endl;
    cin >> n;
    do{
        cout << "Input how many number you would like to test: (between 2 and 99)" << endl;
        cin >> utilize;
    }while (utilize < 0);
    //Fill the array
    for (int i = 0; i < utilize; i++){
        num[i] = rand()%9 + 1;
    }
    
    //Display Output
    Large(num, n, utilize);
    cout << endl;
    //Exit Program
}

//Test to see if larger than n
void Large(int num[], int n, int utilize){
    int total = 0;
    cout << "The numbers greater than n in this array are:" << endl;
    for (int i = 0; i < utilize; i++){
        if (num[i] > n){
            cout << num[i] << setw(2);
            total += 1;
        }
    }
    if (total == 0) cout << "There are not none." << endl;
    cout << endl;
}
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch7 Prob5 MonkeyBusiness ***********************
//Purpose:  Catalog how much the monkeys ate
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem5(){
    cout << endl;
    //Set random number seed:
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of Variables
    const int ROWS = 3;         //The rows of the array
    int food[ROWS][NUMDAYS],    //The the food eaten by each gorilla (in lbs)
        totFood = 0,            //The total amount of food eaten (in lbs)
        used = ROWS;            //The number of rows used
    float avg;                  //The average amount of food eaten (in lbs)
    string names[] = {"Yesse  ", "Coco   ", "Harambe"};  //The names of the gorillas
    
    //Input values
    Eaten(food, used, totFood);
    
    //Display the report
    DietRprt (names, food, used, avg, totFood);
    
    //Process values -> Map inputs to Outputs
    Most(names, food);
    Least(names, food);
    cout << endl;
    //Exit Program
}

//Fill the array for the food eaten:
void Eaten(int food[][NUMDAYS], int n, int &total){
    for (int i = 0; i < n; i++){
        for (int k = 0; k < NUMDAYS; k++){
            food[i][k] = 36 + rand()%9;
            total += food[i][k];
        }
    }
}

//Display the report:
void DietRprt (string names[], int food[][NUMDAYS], int n, float avg, int total){
    avg = total/15.0;
    for (int i = 0; i < n; i++){
        cout << names[i] << ": ";
        for (int k = 0; k < NUMDAYS; k++){
            cout << setw(3) << food[i][k];
        }
        cout  << " in lbs of food." << endl;
    }
    cout << "The total amount of food eaten by the monkeys in that week = " 
         << total << endl;
    cout << "The average amount of food eaten by the monkeys in that week = "
         << avg << endl;
}

void Most(string name[], int food[][NUMDAYS]){
    const int SIZE = 3;
    int mtot[SIZE] = {};//Array that stores the number of food eaten by each monkey
    int max;            //Place holder maximum
    string mName;       //name of monkey in maximum position
    for (int i = 0; i < NUMDAYS; i++){
        mtot[0] += food[0][i];
    }
    for (int i = 0; i < NUMDAYS; i++){
        mtot[1] += food[1][i];
    }
    for (int i = 0; i < NUMDAYS; i++){
        mtot[2] += food[2][i];
    }
    max = mtot[0];
    mName = name[0];
    for (int i = 1; i < 3; i++){   
        if (mtot[i] > max){
            max = mtot[i];
            mName = name[i];
        }
    }
    cout << "The monkey that ate the most that week was " << mName << " with " << max << " lbs eaten" << endl;
}

void Least(string name[], int food[][NUMDAYS]){
    const int SIZE = 3;
    int ltot[SIZE]= {};  //Array that stores the number of food eaten by each monkey
    int min;        //Place holder maximum
    string mName;   //name of monkey in maximum position
    for (int i = 0; i < NUMDAYS; i++){
        ltot[0] += food[0][i];
    }
    for (int i = 0; i < NUMDAYS; i++){
        ltot[1] += food[1][i];
    }
    for (int i = 0; i < NUMDAYS; i++){
        ltot[2] += food[2][i];
    }
    min = ltot[0];
    mName = name[0];
    for (int i = 1; i < 3; i++){   
        if (ltot[i] < min){
            min = ltot[i];
            mName = name[i];
        }
    }
    cout << "The monkey that ate the least that week was " << mName << " with " << min << " lbs eaten" << endl;
}
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch6 Prob7 AnalysisPrograme **************************
//Purpose:  Number analysis program
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem6(){
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
    cout << endl << "The largest value in the list is " << max << endl;
    cout << "The smallest value in the list is " << min << endl;
    cout << "The average of the all the values is " << avg << endl;
    cout << "There are a total of " << utilize << " numbers in the file." 
         << endl << endl;
    //Exit
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
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch7 Prob8 MagicSquare *************************
//Purpose:  Calculate average score
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem7(){
    //Set random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 3;     //Size of the array
    int square[SIZE][COLS]; //The Magic square two dimensional array
    int check,              //The check to determine if the array is a magic square
        used = 3;
    
    //Input values
    FillSqr(square, used);
    
    //Display the square:
    DplySqr (square, used);
    
    //Process values 
    check = Check(square, used);
    
    //Display Output
    if (check = 0) cout << "This is a Lu Shu magic square!" << endl;
    else cout << "This is not a Lu Shu magic square." << endl;
    cout << endl;
    //Exit Program
}
//Fill the Square with random variables:
void FillSqr (int square[][COLS], int used){
    for (int i=0; i<used; i++){
        for (int k=0; k<COLS; k++){
            square[i][k]=rand()%9 + 1;
        }
    }
}

//Check the if it is a Lo Shu Square:
int Check (int square[][COLS], int used){
    int d1,d2,      //The sum of each diagonals of the square.
        v1,v2,v3,   //The sum of each verticals (col) of the square.
        h1,h2,h3;   //The sum of each horizonals (rows) of the square.
    h1 = square[0][0] + square[0][1] + square[0][2];
    h2 = square[1][0] + square[1][1] + square[1][2];
    h3 = square[2][0] + square[2][1] + square[2][2];
    v1 = square[0][0] + square[1][0] + square[2][0];
    v2 = square[0][1] + square[1][1] + square[2][1];
    v3 = square[0][2] + square[1][2] + square[2][2];
    d1 = square[2][0] + square[1][1] + square[0][2];
    d2 = square[0][0] + square[1][1] + square[2][2];
    cout << "Diagonal 1 = " << d1 << endl << "Diagonal 2 = " << d2 << endl
         << "Column 1 = " << v1 << endl << "Column 2 = " << v2 << endl 
         << "Column 3 = " << v3 << endl << "Row 1 = " << h1 << endl 
         << "Row 2 = " << h2 << endl << "Row 3 = " << h3 << endl;    
    if ((d1==d2)&&(d1==v1)&&(d1==v2)&&(d1==v3)&&(d1==h1)&&(d1==h2)&&(d1==h3)) return 1;
    else return 0;
}

//Display the square
void DplySqr (int square[][COLS], int used){
    for (int i=0; i<used; i++){
        for (int k=0; k<COLS; k++){
            cout << setw(2) << square[i][k];
        }
        cout << endl;
    }
}
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch7 Prob9 Payroll ***************************
//Purpose:  Calculate the payroll of each employee
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem8(){
    cout << endl;
     //Declaration of Variables
    const int SIZE = 9;
    char used = 7;
    int empID[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489}; // The employee ID numbers
    int hours[SIZE];        //The hours worked by each employee
    float payRate[SIZE];    //The payrate of each employee
    float wages[SIZE];      //The wages of each employee
    
    //Input values
    InHrsPR (empID,hours,payRate, used);
    
    //Calculation of wages
    Wages (payRate, wages, hours, used);
    
    //Display Output
    EReport (payRate, wages, empID, hours, used);
    cout << endl;
    //Exit Program
}

//Fill in the the hours:
void InHrsPR (int empID[] , int hours[], float payRate[], char used){
    cout << "Input the number of hours,(not less that 0)," << endl;
    cout << "and pay rate of each employee,(not less that 15$/hr)" << endl;
    for (int i=0; i<used; i++){
        do{
            cout << "Employee " << empID[i] << " worked : ";
            cin >> hours[i];
        } while (hours[i] < 0);
        do{
            cout << "Employee " << empID[i] << " pay rate is : ";
            cin >> payRate[i];
        } while (payRate[i] < 15); 
        cout << endl;
    }
}

//Calculate the wage of each employee
void Wages (float payRate[], float wages[], int hours[], char used){
    for (int i=0; i<used; i++){
        wages[i] = payRate[i] * hours[i]; 
    }
}

//Display the employee report:
void EReport (float payRate[], float wages[], int empID[], int hours[], char used){
    for (int i=0; i<used; i++){
        cout << "Employee:   " << empID[i] << endl;
        cout << "Hours work: " << hours[i] << endl;
        cout << "Payrate:    " << payRate[i] << " $/hr" << endl;
        cout << "Wage:       " << wages[i] << " $" << endl;
        cout << "===========================================" << endl;
    }
}
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch7 Prob14 LotteryApp *************************
//Purpose:  Lottery simulator
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem9(){
    //Set random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 100;            //Size of Array
    int used = 5;                    //Positions used
    int lottery[SIZE], player[SIZE]; //Lottery numbers and player numbers 
    
    //Fill in the lottery numbers:
    Lottery(lottery, used);
    UserNum(player, used);
    
    //Determine of the player wins
    Test(player, lottery, used);

    //Exit Program
}

//Fill in the lottery numbers:
void Lottery(int lottery[], int used){
    for (int i=0; i<used; i++){
        lottery[i]=rand()%9+1;
    }
}

//Fill in the player lottery numbers:
void UserNum(int player[], int used){
    for (int i=0; i<used; i++){
        cout << "Input 5 positive numbers" << endl;
        cin >> player[i];
    }
}

//Check if the player wins:
void Test(int player[], int lottery[], int used){
    short same=0;               //The total number similar numbers.
    cout << "The lottery numbers: ";
    for (int i=0; i<used; i++){
        cout << setw(3) << lottery[i];
        if (player[i] == lottery[i]) same += 1;
    }
    cout << endl << "The Player numbers : ";
    for (int i=0; i<used; i++){
        cout << setw(3) << player[i];
    }
    cout << endl;
    if (same == 5)cout << "YOU WIN !!";
    else{
        cout << "YOU LOST !!" << endl;
        cout << same << " numbers matched" << endl;
    }
}
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************** Gaddis 8thEd Ch7 Prob12 GradeBook ********************
//Purpose:  Grade Book program
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem10(){
     //Set random number seed:
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 100;       //Size of the array
    int utilize = 5;            //Number of utilized positions in the array
    int grades [SIZE][GRADES];  //Grades of the students
    int fGrade [SIZE];          //Final grade of the students
    char letter [SIZE];         //Letter grade of the students
    string names [SIZE];        //Names of the students
    
    //Input values
    FillNms (names, utilize);
    FillGrd(grades, fGrade, letter, utilize);
    
    //Display Output
    DplyGrd(grades, fGrade, letter, names, utilize);
    
    //Exit Program
}

//Fill array:
void FillGrd(int grades[][GRADES], int fGrade[], char letter[], int utilize){
    int total = 0;      //Total score of each student
    for (int i = 0; i < utilize; i++){  //Fill the grades
        for (int k = 0; k < GRADES; k++){
            grades[i][k] = rand()%99 + 1;
        }
    }
    for (int i = 0; i < utilize; i++){  //Calculate the final store
        total = 0;
        for (int k = 0; k < GRADES; k++){ 
            total += grades[i][k];
        }
        fGrade[i] = total/4;
    }
    for (int i = 0; i < utilize; i++){  //Letter grade
        if (fGrade[i] >= 90) letter[i] = 'A';
        else if (fGrade[i] >= 80 && fGrade[i] <= 89) letter[i] = 'B';
        else if (fGrade[i] >= 70 && fGrade[i] <= 79) letter[i] = 'C';
        else if (fGrade[i] >= 60 && fGrade[i] <= 69) letter[i] = 'D';
        else if (fGrade[i] <= 59) letter[i] = 'F';
    }
}

//Fill in the names:
void FillNms(string name[], int utilize){
    for (int i = 0; i < utilize; i++){
        cout << "Input the name of each student first name only" << endl;
        cin >> name[i];
    }
}

void DplyGrd (int grades[][GRADES], int fGrade[], char letter[], string name[], int utilize){
    for (int i = 0; i < utilize; i++){
        cout << name[i] << ":" <<endl<< "Test scores: ";
        for (int k = 0; k < GRADES; k++){
            cout << grades[i][k] << setw(3);
        }
        cout << "    Final score: " << setw(3) << fGrade[i];
        cout << "   " << letter[i] << endl;
    }
}
//*****************************END OF PROBLEM***********************************

