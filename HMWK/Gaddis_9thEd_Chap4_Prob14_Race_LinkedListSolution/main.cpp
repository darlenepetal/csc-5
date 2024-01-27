/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 13, 2024, 1:47 PM
 * Purpose: Gaddis_9thEd_Chap4_Prob14_Race_LinkedListSolution
 *          I am aware this program is far beyond the scope of Chapter 4...
 *          I already knew how to use arrays to solve this problem, so
 *          I felt it might be better to re-familiarize myself with
 *          something a little bit more difficult, such as sorted
 *          linked lists, in order to try and catch up with
 *          the members of ACM as quickly as I can
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const char NUM_RUNNERS = 5;
const char OUT_WIDTH = 3;

//Function Prototypes
struct Runner {
    string rnrName;
    short rnrTime;
    struct Runner *next;
};

Runner* makeRnr(string name, short time) {
    Runner* newRnr = new Runner();
    newRnr->rnrName = name;
    newRnr->rnrTime = time;
    return newRnr;
}

void addRnr(Runner** headRef, Runner* newRnr) {
    if ((*headRef) == NULL || (*headRef)->rnrTime >= newRnr->rnrTime) {
        newRnr->next = *headRef;
        *headRef = newRnr;
        return;
    }
    
    struct Runner* cursor = *headRef;
    while (cursor->next != NULL && cursor->next->rnrTime < newRnr->rnrTime) {
        cursor = cursor->next;
    }
    newRnr->next = cursor->next;
    cursor->next = newRnr;
}

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    Runner* head = NULL;
    //Initialize or input i.e. set variable values
    cout << "Race Ranking Program" << endl;
    cout << "Input 3 Runners" << endl;
    cout << "Their names, then their times" << endl;
    
    for (char i = 0; i < NUM_RUNNERS; i++) {
        string curName;
        short curTime;
        cin >> curName >> curTime;
        while (curTime < 0) {
            cout << "Runner time must be a positive number." << endl;
            cin >> curTime;
        }
        Runner* newRnr = makeRnr(curName, curTime);
        addRnr(&head, newRnr);
    }
    //Map inputs -> outputs

    //Display the outputs
    Runner* reader = head;
    for (char i = 0; i < NUM_RUNNERS; i++) {
        cout << reader->rnrName << "\t" << setw(OUT_WIDTH) << reader->rnrTime;
        reader = reader->next;
        if (i + 1 != NUM_RUNNERS) {
            cout << endl;
        }
    }

    //Exit stage right or left!
    return 0;
}