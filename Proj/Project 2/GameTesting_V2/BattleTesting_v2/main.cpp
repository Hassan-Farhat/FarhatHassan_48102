/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 30, 2016, 8:44 AM
 * Purpose: test out how the battle system of the game will function.
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;
void roll(int[], int, int[], int, int[], int, int[], int);
void sort(int[], int);
void pntroll(int[], int[], int[], int[], int = 2, int = 3);
void whowins(int, int, int &, int &, char, char, float, float);
int  fight(int[], int[], int &, int = 3);
int  sfight(int[],int[],int &, int = 2);
int  dmg(int, char, char, float);
int  mdmg(int, char, char, float);

int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declare variables
    const int SIZE = 100;
    int spDice[SIZE], pDice[SIZE], scDice[SIZE], cDice[SIZE];
    int sn=3,n=3,sm=2,m=3, health = 25, mhealth = 15;
    int cWins,pWins,scWins,spWins;
    char pClass, cClass;
    float pAttck=3.5, mAttck=1.5; 
    
    cin >> cClass >> pClass;
    //Roll the dice:
    
    roll(spDice,sn,pDice,n,scDice,sm,cDice,m);
    sort(spDice,sn);
    sort(pDice,n);
    sort(scDice,sm);
    sort(cDice,m);
    pWins = fight(pDice,cDice,cWins);
    spWins = sfight(spDice,scDice,scWins);
    pntroll(spDice,pDice,scDice,cDice);
    cout<<pWins<<setw(2)<<cWins<<endl;
    whowins(pWins,cWins,health,mhealth,pClass,cClass,pAttck,mAttck);
    cout<<spWins<<setw(2)<<scWins<<endl;
    cout << mhealth << " " << health << endl;
    return 0;
}

int  fight(int pD[],int cD[],int &cWins,int m){
    int pWins=0;
    cWins=0;
    for (int i=0; i<m; i++){
        if (pD[i]>cD[i]) pWins+=1;
        else if (pD[i]<cD[i]) cWins+=1;
        else{
            pWins+=1;
            cWins+=1;
        }
    }
    return pWins;
}

int  sfight(int spD[],int scD[],int &scWins, int m){
    int spWins=0;
    scWins=0;
    for (int i=0; i<m; i++){
        if (spD[i]>scD[i]) spWins+=1;
        else if (spD[i]<scD[i]) scWins+=1;
        else{
            spWins+=1;
            scWins+=1;
        }
    }
    return spWins;
}

void roll(int spD[],int sn,int pD[],int n,int scD[],int sm,int cD[],int m){
    for (int i=0; i<sn; i++)spD[i]=rand()%12+1;
    for (int i=0; i<n; i++)pD[i]=rand()%12+1;
    for (int i=0; i<sm; i++)scD[i]=rand()%12+1;
    for (int i=0; i<m; i++)cD[i]=rand()%12+1;
}

void sort(int a[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]<a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

void pntroll(int spD[], int pD[],int scD[],int cD[],int n, int m){
    cout <<"NORMAL DICE   SPECIAL DICE" << endl;
    for (int i=0; i<m; i++)cout<<setw(3)<<pD[i];
    cout << "        ";
    for (int i=0; i<n; i++)cout<<setw(3)<<spD[i];
    cout << endl;
    for (int i=0; i<m; i++)cout<<setw(3)<<cD[i];
    cout << "        ";
    for (int i=0; i<n; i++)cout<<setw(3)<<scD[i];
    cout<<endl;
}

int  dmg(int wins, char pClass, char cClass, float pAttck){
    int damage = wins * pAttck;  
    if (pClass=='D' && cClass=='*') return damage/2;
    else if (pClass=='D' && cClass=='=') return damage+3;
    else if (pClass=='H' && cClass=='#') return damage+3;
    else if (pClass=='H' && cClass=='=') return damage/2;
    else if (pClass=='G' && cClass=='#') return damage/2;
    else if (pClass=='G' && cClass=='*') return damage+3;
    else return damage;
}

int  mdmg(int wins, char pClass, char cClass, float mAttck){
    int damage = (wins * mAttck + 0.5);  
    if (cClass=='#' && pClass=='H') return damage/2;
    else if (cClass=='#' && pClass=='G') return damage+3;
    else if (cClass=='*' && pClass=='D') return damage+3;
    else if (cClass=='*' && pClass=='G') return damage/2;
    else if (cClass=='=' && pClass=='D') return damage/2;
    else if (cClass=='=' && pClass=='H') return damage+3;
    else return damage;
}

void whowins(int pWins,int cWins,int &health, int &mhealth,char pClass,char cClass,float pAttck,float mAttck){
    if (pWins>cWins){
        cout<<"You attack"<<endl;
        mhealth = mhealth - dmg(pWins, pClass, cClass, pAttck);
    }else if (pWins<cWins){
        cout<<"The monster successfully attacks"<<endl;
        health = health - mdmg(cWins, pClass, cClass, mAttck);
    }else{
        cout<<"You both hit each other"<<endl;
        mhealth = mhealth - dmg(pWins, pClass, cClass, pAttck);
        health = health - mdmg(cWins, pClass, cClass, mAttck);
    }
}