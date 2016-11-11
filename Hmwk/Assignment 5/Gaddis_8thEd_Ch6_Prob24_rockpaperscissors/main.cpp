/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 6, 2016, 8:39 PM
 * Purpose : Play a game of rock paper scissors
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>
#include <ctime>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototype:
int Comp();
int Player();
void Game(int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
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
    //Exit Program
    return 0;
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