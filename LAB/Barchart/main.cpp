/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on January 17, 2024, 4:52 PM
 * Purpose: Barchart
 */

#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {

    const unsigned char  STORES_NUM = 5;
    unsigned short       sales[STORES_NUM];

    for (short i = 0; i < STORES_NUM; i++) {
        cout << "Enter today's sales for store " << i + 1 << ": ";
        cin >> sales[i];
    }    

    cout << "SALES BAR CHART (Each * = $100)" << endl;
    for (short i = 0; i < STORES_NUM; i++)
    {
        unsigned short barsNum = sales[i] / 100;
        cout << "Store " << i + 1 << ": ";
        for ( ; barsNum > 0; barsNum--) {
            cout << "*";
        }
        if (i + 1 != STORES_NUM) {
            cout << endl;
        }
    }

    return 0;
}