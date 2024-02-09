/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on February 4, 2024, 1:17 PM
 * Purpose: Scantron
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>   //File I/O
#include <string>    //String Library
using namespace std;

void print(const string&, short);
void read(const char [], string&, short&);
int  compare(const string&, const string&, string &);

int main(int argc, char** argv) {
    
    //Declare Variables
    float   pRight;
    short   keyLen;
    char    fileKey[] = "key.dat", 
            fileAns[] = "answer.dat";
    string  key,
            answers,
            score;
    
    //Initialize or input i.e. set variable values
    keyLen = 0;
    read(fileKey, key, keyLen);
    read(fileAns, answers, keyLen);
    
    //Score the exam
    pRight = compare(key, answers, score);
    
    //Display the outputs
    cout << "C/W     ";
    print(score, keyLen);
    cout << "Percentage Correct = ";
    cout << pRight/keyLen * 100 << "%" << endl;

    return 0;
}

void print(const string& curStr, short len) {
    for (short i = 0; i < len; i++) cout << curStr[i] << " ";
    cout << endl;
    return;
}

void read(const char file[], string& readStr, short& len) {
    string  next;
    fstream outFile;
    outFile.open(file);
    cin >> next;
    // check if entering key, which comes first
    if (next[1]) {
        cin >> next;
        while (!next[1]) {
            readStr += next;
            len++;
            cin >> next;
        }
    }
    // check if entering student answers
    else for (short i = 0; i < len; i++) {
        readStr += next;
        cin >> next;
    }
    outFile.close();
    return;
}

int compare(const string& key, const string& answers, string& score) {
    short correct = 0;
    for (short i = 0; i < key.size(); i++) {
        if (answers[i] == key[i]) {
            score[i] = 'C';
            correct++;
        }
        else score[i] = 'W';
    }
    return correct;
}