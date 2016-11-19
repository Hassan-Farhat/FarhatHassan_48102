/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 13, 2016, 5:06 PM
 * Purpose : Menu with all the Assignment 5 answers.
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //For output manipulation
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const unsigned char PERCENT = 100;
const float GRAVITY = 9.81;

//Function prototypes
float RetailP(float, float);
void getDmsn(float &, float &);
float Area(float, float);
void Display(float, float, float);
float getSales (int);
void HstSale (float, float, float, float);
void getAcdnt(int &, int &, int &, int &, int &);
void Low(int, int, int, int, int);
float Distance(float);
void Output(int, int);
void getScore(float &,float &,float &,float &,float &);
float avgScore(float, float, float, float, float);
float Lowest(float, float, float, float, float);
float Hghest(float, float, float, float, float);
int NumEply();
int NumDays(int);
float AvgDays(int, int);
void GetData(int &, float &, float &, float &);
void GetData(float &, float &);
float Charge(float, float);
float Charge(int, float, float, float);
int Comp();
int Player();
void Game(int,int);
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
        cout<<"1.  Type 1  for Gaddis 8thEd Ch6 Prob1 Markup"<<endl;
        cout<<"2.  Type 2  for Gaddis 8thEd Ch6 Prob2 Rectangle"<<endl;
        cout<<"3.  Type 3  for Gaddis 8thEd Ch6 Prob3 Division Sale"<<endl;
        cout<<"4.  Type 4  for Gaddis 8thEd Ch6 Prob4 SafestArea"<<endl;
        cout<<"5.  Type 5  for Gaddis 8thEd Ch6 Prob5 FallingDist"<<endl;
        cout<<"6.  Type 6  for Gaddis 8thEd Ch6 Prob8 CoinToss"<<endl;
        cout<<"7.  Type 7  for Gaddis 8thEd Ch6 Prob12 StarSearch"<<endl;
        cout<<"8.  Type 8  for Gaddis 8thEd CH6 Prob13 DaysOut"<<endl;
        cout<<"9.  Type 9  for Gaddis 8thEd Ch6 Prob15 Hospital"<<endl;
        cout<<"10. Type 10 for Gaddis 8thEd Ch6 Prob24 rockpaperscissors"<<endl;
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
//****************** Gaddis 8thEd Ch6 Prob1 Markup *****************************
//Purpose:  Calculate the mark up price
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem1(){
    cout<<"Inside Gaddis 8thEd Ch6 Prob1 Markup"<<endl;
    //Declaration of Variables
    float wCost, markup, retailP; //Whole sale cost, mark up, and retail price.
    
    //Input values
    do{
        cout << "Input the whole sale cost of the item:" << endl;
        cin >> wCost;
    }while (wCost < 0);
    
    do{
        cout << "Input the percent mark up of the item:" << endl;
        cin >> markup;
    }while (markup < 0);
    
    //Process values -> Map inputs to Outputs
    retailP = RetailP(wCost, markup);
    
    //Display Output
    cout << setprecision(2) << fixed << showpoint;
    cout << endl << "The retail price will be " << retailP << "$" <<endl<<endl;
    //Exit Program
}

//Retail price calculation:
float RetailP(float cost, float Mp){
    return ((cost * Mp)/PERCENT) + cost;
}
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch6 Prob2 Rectangle *************************
//Purpose:  Find the area of a rectangle
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************

void problem2(){
    cout<<"Inside Gaddis 8thEd Ch6 Prob2 Rectangle"<<endl;
        //Declaration of Variables
    float length, width, area;  //The length, width, and area of the rectangle
    
    //Input values
    getDmsn(length, width);
    
    //Process values -> Map inputs to Outputs
    area = Area(length, width);
    
    //Display Output
    Display(length, width, area);
    //Exit Program
}

//Function for the user to input the data:
void getDmsn(float &length, float &width){
    do{
        cout << "Input the length of the rectangle." << endl;
        cin >> length;
    }while (length <= 0);
    do{
        cout << "Input the width of the rectangle." << endl;
        cin >> width;
    }while (width <= 0);
    cout << endl;
}

//Calculate the area of the square:
float Area(float length, float width){
    return length * width;
}

//Display the output
void Display(float length, float width, float area){
    cout << setprecision(2) << fixed << showpoint;
    cout << endl;
    cout << "The dimensions of the rectangle:" << endl;
    cout << "Length = " << length << " units" << endl;
    cout << "Width = " << width << " units" << endl;
    cout << endl;
    cout << "The area = " << area << " unit^2" << endl; 
    cout << endl;
}
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch6 Prob3 Division Sales *************************
//Purpose:  Determine which devision has the greatest sales
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem3(){
    cout<<"Inside Gaddis 8thEd Ch6 Prob3 Division Sales"<<endl;
      //Declaration of Variables
    float d1,d2,d3,d4;          //Sales of devision 1,2,3,4 in $
    
    //Process values -> Map inputs to Outputs
    for (int i=1; i<=4; i++){
        if (i==1) d1 = getSales(i);
        else if (i==2) d2 = getSales(i);
        else if (i==3) d3 = getSales(i);
        else d4 = getSales(i);
    }
    
    //Sort and display values:
    HstSale (d1,d2,d3,d4);
    cout << endl;
    //Exit Program
}

//Asks users to input the sales figures
float getSales (int n){
    string name;                //Name of the devision
    if (n==1) name = "North West";
    else if (n==2) name = "South West";
    else if (n==3) name = "North East";
    else name = "South East";
    float sales;
    do{
        cout << "Input the sales of " << name << " in thousands ($)"<< endl;
        cin >> sales;
    }while (sales < 0);
    return sales;
}

//Determine which sales figure is the highest
void HstSale (float d1, float d2,float d3,float d4){
    //Sort for the maximum value
    float max, min;
    max = d1;
    if (d2 > max) max = d2;
    if (d3 > max) max = d3;
    if (d4 > max) max = d4;
    
    //Display the winner
    cout << setprecision(2) << fixed << showpoint;
    if (max == d1){
        cout << "The North West sector won!" << endl;
        cout << "Its Quarterly Sales figure is: " << d1<< "$ thousands" << endl;
    }
    if (max == d2){
        cout << "The South West sector won!" << endl;
        cout << "Its Quarterly Sales figure is: " << d2<< "$ thousands" << endl;
    }
    if (max == d3){
        cout << "The North East sector won!" << endl;
        cout << "Its Quarterly Sales figure is: " << d3<< "$ thousands" << endl;
    }
    if (max == d4){
        cout << "The South East sector won!" << endl;
        cout << "Its Quarterly Sales figure is: " << d4<< "$ thousands" << endl;
    }
}

//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch6 Prob4 SafestArea *************************
//Purpose:  The Safest and Worst area for car accidents
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem4(){
    cout<<"Inside Gaddis 8thEd Ch6 Prob4 SafestArea"<<endl;
     //Declaration of Variables
    int north, south, east, west, cent; //the number of car accidents
    
    //Input values
    getAcdnt(north,south,east,west,cent);
    
    //Sort and Display Output:
    Low(north,south,east,west,cent);
    //Exit Program
}

//Input the number of accidents:
void getAcdnt(int &north, int &south, int &east, int &west, int &cent){
    int x;
    for (int i=1; i<=5; i++){
        string name;
        if (i == 1) name = "North";
        else if (i == 2) name = "South";
        else if (i == 3) name = "East";
        else if (i == 4) name = "West";
        else if (i == 5) name = "Center";
        do{
            cout << "Input the number of accidents in the " << name << endl;
            cin >> x;
        }while (x < 0);
        if (i == 1) north = x;
        else if (i == 2) south = x;
        else if (i == 3) east = x;
        else if (i == 4) west = x;
        else if (i == 5) cent = x;
    }
}

//Sort and display the output
void Low(int north,int south,int east,int west,int cent){
    //Sort the 5 regions of a city
    int min;
    min = north;
    if (south < min) min = south;
    if (east < min)  min = east;
    if (west < min)  min = west;
    if (cent < min)  min = cent;
    //Display the safest and the most dangerous
    cout << endl;
    if (min == north){
        cout << "The safest place is the North with " << north << endl;
    }
    if (min == south){
        cout << "The safest place is the South with " << south << endl;
    }
    if (min == east){
        cout << "The safest place is the East with " << east << endl;
    }
    if (min == west){
        cout << "The safest place is the West with " << west << endl;
    }
    if (min == cent){
        cout << "The safest place is the Center with " << cent << endl;   
    }
}
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch6 Prob5 FallingDist ***********************
//Purpose:  Calculate the distance that the object fell
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem5(){
    cout<<"Inside Gaddis 8thEd Ch6 Prob5 FallingDist"<<endl;
     //Declaration of Variables
    float time;             //(time) how long the object fell for in seconds
    
    //Input values
    do{
        cout << "How many seconds did the object fall for ?" << endl;
        cin >> time;
    }while (time < 0);
    
    //Display Output
    cout << "The object fell for " << Distance(time) << " m" << endl << endl;
    //Exit Program
}

//Calculate the Distance
float Distance(float time){
    return (time*time*GRAVITY)/2;
}
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch6 Prob8 CoinToss **************************
//Purpose:  This is a coin toss game
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem6(){
    cout<<"Inside Gaddis 8thEd Ch6 Prob8 CoinToss"<<endl;
     //Set random number seed
    srand(static_cast <unsigned int> (time(0)));
    
    //Declaration of Variables
    int flips, face; //Number of coin flips, and the face of the coin
    //Input values
    do{
        cout << "Input number of coin flips:" << endl;
        cin >> flips;
    }while (flips <= 0);
    
    //Loop number of flips and output the display
    for (int i = 1; i<=flips; i++){
        face = rand()%2 + 1;
        Output(face, i);
    }
    //Exit Program
}

//The Determine if its heads or tails and output the face
void Output(int face, int i){
    cout << "Flip " << i << " : "; 
    if(face == 1) cout << "Heads" << endl << endl;
    else cout << "Tails" << endl << endl;
}
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch6 Prob12 StarSearch *************************
//Purpose:  Calculate average score
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem7(){
    cout<<"Inside Gaddis 8thEd Ch6 Prob12 StarSearch"<<endl;
   //Declaration of Variables
    float s1,s2,s3,s4,s5,       //Score 1,2,3,4
          avg;                  //Average
    
    //Input values
    getScore(s1,s2,s3,s4,s5);
    
    //Precess Values (remove the lowest and highest scores)
    avg = avgScore(s1,s2,s3,s4,s5);
    
    //Display Output
    cout << endl << "The Average score will be " << avg << endl << endl;
    //Exit Program
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
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd CH6 Prob13 DaysOut **************************
//Purpose:  Calculate the average number of absent days
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem8(){
    cout<<"Inside Gaddis 8thEd CH6 Prob13 DaysOut"<<endl;
    //Declaration of Variables
    int numEply,      //Number of Employees
        numDays;      //Number of days absent
    float avgDays;    //Average number of days absent
    
    //Input values
    numEply = NumEply();
    numDays = NumDays(numEply);
    
    //Calculate the average number of days the employees were absent
    avgDays = AvgDays(numEply, numDays);
    
    //Display Output
    cout << setprecision(2) << showpoint << fixed;
    cout << endl << "The total number of employees : " << numEply << endl;
    cout << "The average number of days absent for the employees : "
         << avgDays << " days" << endl << endl;
    //Exit Program
}

//Input the number of employees
int NumEply(){
    int x;
    do{
        cout << "Enter how many employees in the company : "; 
        cin >> x;
    }while (x <= 0);
    return x;
}

//Input number of absent days per employee
int NumDays(int numEply){
    int totDays = 0;    //Total number of absent days
    int nDays;          //Number of days each employee was absent
    for (int i=1; i<=numEply; i++){
        do{
            cout<< "Input the number of days employee " <<i<< " was absent : ";
            cin >> nDays;
        }while (nDays < 0);
        totDays += nDays;
    }
    return totDays;
} 

//Calculate the average number of days the employees were absent
float AvgDays(int numEply, int numDays){
    return static_cast <float> (numDays) / numEply;
}
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch6 Prob15 Hospital *************************
//Purpose:  Calculate the Hospital Charge
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem9(){
    cout<<"Inside Gaddis 8thEd Ch6 Prob15 Hospital"<<endl;
    //Declaration of Variables
    int days;       //Number of days spent in the hospital
    float hCharge,  //Hospital services charges
          mCharge,  //Medication charges
          dRate,    //Daily Rate
          cost;     //Total cost
    string type;    //Type of patient
    
    //Input values, calculate hospital charge, and display the cost
    cout << "Is this an in-patient or an out-patient?" << endl;
    do{
        cout << "Type in for in-patient or out for out-patient" << endl;
        cin >> type;
    }while(!(type == "in") && !(type == "out"));
    cout << setprecision(2) << fixed  << showpoint;
    if(type == "in"){
        GetData(days, hCharge, mCharge, dRate);
        cost = Charge(days, hCharge, mCharge, dRate);
        cout << endl << "The total cost of service = " << cost << " $" << endl;
    }
    else{
        GetData(hCharge, mCharge);
        cost = Charge(hCharge, mCharge);
        cout << endl << "The total cost of service = " << cost << " $" << endl;
    }
    cout << endl;
    //Exit Program
}

//Input the data for the in patient:
void GetData(int &days, float &hCharge, float &mCharge, float &dRate){
    do{
        cout << endl << "Days spent in hospital: ";
        cin >> days;
    }while (days < 0);
    do{
        cout << "Cost per day: ";
        cin >> dRate;
    }while (dRate < 0);
    do{
        cout << "Hospital service charge: ";
        cin >> hCharge;
    }while (hCharge < 0);
    do{
        cout << "Hospital Medication charge: ";
        cin >> mCharge;
    }while (mCharge < 0);
}

//Input the date for th out patient:
void GetData(float &hCharge, float &mCharge){
    do{
        cout << endl << "Hospital service charge: ";
        cin >> hCharge;
    }while (hCharge < 0);
    do{
        cout << "Hospital Medication charge: ";
        cin >> mCharge;
    }while (mCharge < 0);
}

//Calculate the cost for the In patient:
float Charge(int days, float hCharge, float mCharge, float dRate){
    return (days * dRate) + hCharge + mCharge;
}

//Calculate the cost for the Out patient:
float Charge(float hCharge, float mCharge){
    return hCharge + mCharge;
}
//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************** Gaddis 8thEd Ch6 Prob24 rockpaperscissors ********************
//Purpose:  Play a game of rock paper scissors
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem10(){
    cout<<"Inside Gaddis 8thEd Ch6 Prob24 rockpaperscissors"<<endl;
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    int pMove, cMove;   //Player move, Computer move
    do{
        //Computer move and player move
        cout << "This is rock paper scissors input your choice :" << endl;
        pMove = Player(),           //Player move
        cMove = rand()%3 + 1;       //Computer move

        //Determine the winner and display output
        cout << "The computer played: ";
        if (cMove == 1) cout << "Rock" << endl;
        if (cMove == 2) cout << "Scissors" << endl;
        if (cMove == 3) cout << "Paper" << endl;
        cout << "You played: ";
        if (pMove == 1) cout << "Rock" << endl;
        if (pMove == 2) cout << "Scissors" << endl;
        if (pMove == 3) cout << "Paper" << endl;
        Game(cMove, pMove);
    } while (cMove == pMove);
    cout << endl;
    //Exit Program
}

//Player move
int Player(){
    int x; //Player choice
    cout << "Type in 1 for Rock" << endl;
    cout << "Type in 2 for Scissors" << endl;
    cout << "Type in 3 for Paper" << endl;
    do {
        cin >> x;
    }while (x < 0 || x > 3);
    return x;
}

//Determine the winner
void Game(int cMove,int pMove){
    if (pMove == 1 && cMove == 2) cout << "YOU WIN !!" << endl;
    else if (pMove == 2 && cMove == 3) cout << "YOU WIN !!" << endl;
    else if (pMove == 3 && cMove == 1) cout << "YOU WIN !!" << endl;
    else if (cMove == 1 && pMove == 2) cout << "YOU LOST !!" << endl;
    else if (cMove == 2 && pMove == 3) cout << "YOU LOST !!" << endl;
    else if (cMove == 3 && pMove == 1) cout << "YOU LOST !!" << endl;
    else cout << "DRAW" << endl;
}
//*****************************END OF PROBLEM***********************************

