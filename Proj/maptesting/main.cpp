/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 15, 2016, 12:07 PM
 * Purpose : Testing map mechanics
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <fstream>    //File I/O
#include <string>     //String Library
#include <cstdlib>    //Random number
#include <ctime>      //Used to set random number seed
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed:
    srand(static_cast <unsigned int> (time(0)));
    
    //Declaration of Variables
    ifstream in;
    ofstream out;
    int rows,cols,prow=8, pcol=5, spawn;
    string line, move;
    
    //Input values
    in.open("map.dat");
    in>>rows>>cols;
    cout<<"rows = "<<rows<<" cols = "<<cols<<endl;
    
    //Display Output / what is in the file to the output screen
    //In addition add in row numbers and column numbers for the user
    getline(in,line);
    for(int row=1;row<=rows;row++){
        getline(in,line);
        cout<<row<<" "<<line<<endl;
    }
    cout<<"  ";
    for(int col=1;col<=cols;col++){
        cout<<col;
    }
    cout<<endl;
    
    //Where do you want to place the player
    for (int i = 0; i < 10; i++){
    cout<<"Input the direction of your turn"<<endl;
    cin>>move;
    if (move == "up" || move == "Up") prow -= 1;
    else if (move == "down" || move == "Down") prow += 1;
    else if (move == "right" || move == "Right") pcol += 1;
    else if (move == "left" || move == "Left") pcol -= 1;
    cout<<"Player position in Y = "<<prow<<" Player position in X = "<<pcol<<endl;
    
    //Read back in the file
    in.close();
    in.clear();
    
    //Input values
    in.open("map.dat");
    in>>rows>>cols;
    cout<<"rows = "<<rows<<" cols = "<<cols<<endl;
    
    //Display Output and write to the player file
    out.open("player.dat");
    getline(in,line);
    for(int row = 1;row <= rows;row++){
        getline(in,line);
        if(row == prow && line[pcol] == '0'){
            line[pcol]='P';
        }
        if (row == prow && line[pcol] == '_'){
            if (move == "up" || move == "Up") prow += 1;
            else if (move == "down" || move == "Down") prow -= 1;
            else if (move == "right" || move == "Right") {
                pcol -= 1;
                line[pcol]='P';
            }
            else if (move == "left" || move == "Left"){
                pcol += 1;
                line[pcol]='P';
            }
        }
        cout<<line<<endl;
        out<<line;
    }
    cout<<endl;
    //Spawn chance:
    spawn = rand()%9 + 1;
    if (spawn%2==0){
        cout << "MONSTER HAS SPAWNED PREPARE" << endl;
    }
    else{
        cout << "YOU ARE CLEAR KEEP MOVING" << endl;
    }
    
    //Close the file
    in.close();
    out.close();
    }
    //Exit Program
    return 0;
}

