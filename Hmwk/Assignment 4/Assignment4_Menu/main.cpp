/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 15, 2016, 11:00 AM
 * Purpose : A menu for all programs
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>
#include <string>     //Student names
#include <cstdlib>    //Random number seed
#include <ctime>      //Seed the random number
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int menuItm;    //Choice from menu
    
    //Loop until users exits
    do{
    
        //Prompt for problem for user input
        cout<<"1.  Type 1  for Problem Gaddis_8thEd_Ch5_Prob2_ASCII"<<endl;
        cout<<"2.  Type 2  for Problem Gaddis_8thEd_Ch5_Prob6_DistanceTraveled"<<endl;
        cout<<"3.  Type 3  for Problem Gaddis_8thEd_Ch5_Prob7_PennyPay"<<endl;
        cout<<"4.  Type 4  for Problem Gaddis_8thEd_Ch5_Prob9_HotelOccupancy"<<endl;
        cout<<"5.  Type 5  for Problem Gaddis_8thEd_Ch5_Prob10_AverageRainfall"<<endl;
        cout<<"6.  Type 6  for Problem Gaddis_8thEd_Ch5_Prob11_Population"<<endl;
        cout<<"7.  Type 7  for Problem Gaddis_8thEd_Ch5_Prob14_StudentLineUp"<<endl;
        cout<<"8.  Type 8  for Problem Gaddis_8thEd_Ch5_Prob17_SalesBar"<<endl;
        cout<<"9.  Type 9  for Problem Gaddis_8thEd_Ch5_Prob20_RandNumGame"<<endl;
        cout<<"10. Type 10 for Problem Gaddis_8thEd_Ch5_Prob22_SquareDisplay"<<endl;
        cin>>menuItm;

        //Go to the Problem
        switch(menuItm){
            case 1:{
                cout<<"Inside Problem Gaddis_8thEd_Ch5_Prob2_ASCII"<<endl;
                //Declaration of Variables
                char ch; //(ch) will be used to display the characters

                //Process values and display output (Loop will literate 128 time to display all ascii characters)
                for (int i=0;i<=127;i++){
                    ch = i;
                    if (i%16 == 0){
                        cout << endl << ch << " ";
                    }
                    else {
                        cout << ch << " ";
                    }
                }
                cout << endl;
                cout << endl;
                break;
            }
            case 2:{
                cout<<"Inside Problem Gaddis_8thEd_Ch5_Prob6_DistanceTraveled"<<endl;
                //Declaration of Variables
                float dist, speed;    //Distance, speed of the train (in miles and mpr respectively)
                int numhr;            //Number of hours traveled

                //Input values: speed and number of hours
                cout << "What was the speed of the train?" << endl;
                cin >> speed;
                cout << "How hour many hours did the train tavel?" << endl;
                cin >> numhr;

                //Process values and display output
                 cout << "-----------------------------" << endl;
                for(int i=1;i<=numhr;i++){
                    dist = speed * i;
                    cout << "Hour : " << i << setw(10) << dist << " mi" << endl;
                }
                cout << endl;
                break;
            }
            case 3:{
                cout<<"Inside Problem Gaddis_8thEd_Ch5_Prob7_PennyPay"<<endl;
                //Declaration of Variables
                float dollars;          //Number of dollars at the end of the sequence
                unsigned int cents=1;   //Number of cents
                unsigned short numDays; //Number of daily payment periods  

                //Input values
                cout << "Input the number of days you will get paid (please not more than 31 days):" << endl;
                cin >> numDays;

                while (numDays > 31){
                    cout << "Please don't input a number greater than 31: " << endl;
                    cin >> numDays;
                }
                //Process values
                for (int i=2; i<=numDays; i++){
                    cents = cents * 2;
                }

                dollars = cents/100.0; //Convert cents to dollars

                //Display output
                cout << setprecision(2) << fixed;
                cout << "The total number of cents : " << cents << endl;
                cout << "The total dollar amount will be : " << dollars << "$"<< endl;
                cout << endl;
                break;
            }
            case 4:{
                cout<<"Inside Problem Gaddis_8thEd_Ch5_Prob9_HotelOccupancy"<<endl;
                //Declaration of Variables
                unsigned short numFlrs,   //Number of floors 
                               numRoom,   //Number of rooms on each floor
                               numOcc,    //Number of occupied rooms
                               totRoom=0, //Total number of rooms
                               totOcc=0;  //Total number of occupied rooms
                float perOcc;             //Number of rooms occupied

                //Input number of rooms:
                cout << "Please input the number of floors are in the hotel:" << endl;
                cin >> numFlrs;

                //Processing values: Loop, calculations:
                for (int i = 1; i <= numFlrs; i++){
                    if (i==13) {
                        i++;
                    }
                    cout << "Floor " << i << endl;
                    cout << "Input number of rooms:" << endl;
                    cin >> numRoom;
                    cout << "Input number of rooms occupied" << endl;
                    cin >> numOcc;
                    while (numOcc > numRoom){
                        cout << "Impossible entry please re-input number of occupied rooms :" << endl;
                        cin >> numOcc;
                    }
                    totRoom+=numRoom;
                    totOcc+=numOcc;
                }
                perOcc = static_cast<float> (totOcc)/totRoom * 100;

                //Display output:
                cout << "Total number of floors         : " << numFlrs << endl;
                cout << "Total number of rooms          : " << totRoom << endl;
                cout << "Total number of occupied rooms : " << totOcc  << endl;
                cout << setprecision(2) << fixed;
                cout << "The percentage of rooms occupied : "<< perOcc << "%" << endl << endl;
                //Exit Program
                break;
            }
            case 5:{
                cout<<"Inside Problem Gaddis_8thEd_Ch5_Prob10_AverageRainfall"<<endl;
                //Declaration of Variables
                unsigned short numYr, i, k;        //Number of years to test, (i) counter for outer loop, (k) counter for inner loop
                float rainfall=0, avRfall, rfall;  //(rainfall) user input in inches, average rainfall over all years, (rfall) is a storage value 

                //Input values and the nested loops
                cout << "Input number of years you want to test :" <<endl;
                cin >> numYr;
                for (i = 1; i <= numYr; i++){
                    for (k = 1; k <= 12; k++){
                        cout << "Rainfall of month " << k << " in inches is : " <<endl;
                        cin >> rfall;
                        rainfall = rainfall + rfall;
                    }
                }
                avRfall = rainfall/(numYr*12);
                cout << "=======================================================" << endl;
                cout << setprecision(2) << fixed;
                cout << "The average rain fall of this interval was: " << avRfall << " in" << endl << endl;
                break;
            }
            case 6:{
                cout<<"Inside Problem Gaddis_8thEd_Ch5_Prob11_Population"<<endl;
                //Declaration of Variables
                float popinc, pPopinc;      //Daily population increase and Daily population increase in percent
                int numDays,                //Number of days to test
                    pop,                    //Population
                    inPop;                  //the increase of population of that day


                //Input values
                cout << "Input the percentage growth per day (no negatives) :" << endl;
                cin >> pPopinc;
                while (pPopinc < 0){
                    cout << "Input the growth again :" << endl;
                    cin >> pPopinc;
                }
                popinc = pPopinc / 100;

                cout << "Input the starting population (greater than or equal two):" << endl;
                cin >> pop;
                while (pop < 2){
                    cout << "Starting population to small re-input the population (>=2):" << endl;
                    cin >> pop;
                }

                cout << "Input the the number of dates to test (>=1):" << endl;
                cin >> numDays;
                while (numDays < 1){
                    cout << "Input a number that is equal to or greater than or equal to one:" << endl;
                    cin >> pPopinc;
                }

                //Process values and Display Output
                cout << "The population of day 1 is " << pop << " Organisms" << endl;

                for (int i=2; i<=numDays; i++){
                    inPop = pop * popinc;
                    pop = inPop + pop;
                    cout << "The population of day " << i << " is " << pop << " Organisms"  << endl;
                }
                cout << endl;
                break;
            }
            case 7:{
                cout<<"Inside Problem Gaddis_8thEd_Ch5_Prob14_StudentLineUp"<<endl;
                //Declaration of Variables
                string name,  //Student names
                       fName, //Name of First student
                       lName; //Name of Last student
                unsigned short nStudnt;

                //Input values
                do{
                    cout << "Please input the number of students in the class (1 to 25):" << endl;
                    cin >> nStudnt;
                }while ((1>nStudnt) || (nStudnt>25));

                //Process variables (loops) and Display output
                cout << "Please enter the first names of your students (one at a time)" << endl;
                cin >> name;
                fName = name;
                lName = name;

                for (int i=2; i<=nStudnt; i++){
                    cout << "Please enter the first names of your students (one at a time)" << endl;
                    cin >> name;
                    if ((name < fName)){
                        fName = name;
                    }
                    else if (name > lName){
                        lName = name;
                    }
                }
                cout << "The First student will be : " << fName << endl;
                cout << "The Last student will be : " << lName << endl << endl;
    
                break;
            }
            case 8:{
                cout<<"Inside Problem Gaddis_8thEd_Ch5_Prob17_SalesBar"<<endl;
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
                cout << endl << endl;
                break;
            }
            case 9:{
                cout<<"Inside Problem Gaddis_8thEd_Ch5_Prob20_RandNumGame"<<endl;
                //Seed the random number
                srand(static_cast<unsigned int>(time(0)));

                //Declaration of Variables
                int x = rand()%50 + 1, //The random number for the user to find (1->50)
                    num,                //The user input guesses
                    i=0;                //The counter

                //Process values
                cout << "This is a random number game type in your first guess: ";
                cin >> num;
                while (num != x){
                    i++;
                    if (num < x){
                        cout << "Too low, try again" << endl;
                        cin >> num;
                    }
                    else{
                        cout << "Too high, try again" << endl;
                        cin >> num;
                    }
                }
                //Display Output
                cout << "===============================" << endl;
                cout << "YOUR GUESS WAS CORRECT" << endl;
                cout << "Your last guess = " << num << endl;
                cout << "The random number = " << x << endl;
                cout << "It took you " << i << " guesses to get the right answer." << endl << endl;
                break;
            }
            case 10:{
                cout<<"Inside Problem Gaddis_8thEd_Ch5_Prob22_SquareDisplay"<<endl;
                //Declaration of Variables
                char ch = 'X';          //The X character to fill the square with
                unsigned short dmnsion; //The dimensions of the square

                //Input values
                cout << "Please input the dimensions of the square: " << endl;
                cin >> dmnsion;

                //Process values and display
                for (int i=1;i<=dmnsion;i++){
                    for (int k = 1; k<=dmnsion;k++){
                        cout << ch;
                    }
                    cout << endl;
                }

                break;
            }//End Case
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<=10);//Ends the Do-While Loop

    //Exit Program
    return 0;
}

