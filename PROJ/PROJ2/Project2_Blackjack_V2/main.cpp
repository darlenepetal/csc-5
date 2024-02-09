/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on February 8, 2024, 10:41 PM
 * Purpose: Project2_Blackjack_V2
 */

// system libraries // used to...
#include <iostream> // get user input and display outputs
#include <iomanip>  // format dollar amount outputs
#include <fstream>  // handle session stats & store cards for current hand
#include <string>   // handle "continue" input & suit ascii
#include <cstdlib>  // randomize cards drawn
#include <ctime>    // set the random number seed
#include <cmath>    // calculate standard deviation stats

using namespace std;

// global constants
const unsigned char     N_DECK  = char(52);  // no. of possible cards to draw
const unsigned char     N_DEAL  = char(9);   // no. of cards needed per hand
const short             MAXRNDS = 200;       // maximum no. of rounds
const short             MAXCOLS = 5;

float   takeBet(float, short);
void    endGame(float [], float [], short);
void    shuffle(short [], char [][MAXCOLS]);

// execution begins
int main(void) {

    srand(static_cast<unsigned int>(time(0)));  // set the random no. seed
    
    // local constants
    const short     MAXROWS = 9;
    
    // variable declarations    // used for storing...
    float           usrCash,    // money in user's wallet
                    betAmnt,    // various floats tied to user bets
                    allCash[MAXRNDS],
                    allBets[MAXRNDS];
    short           roundNo,
                    valCard[MAXROWS];
    char            strCard[MAXROWS][MAXCOLS];

    // initialize session log fstream objects & starting variable values 
    roundNo = 0;  // set accumulators to 0.
    usrCash = 1000.0f;  // user starts with $1000.00
    
    cout << fixed << setprecision(2) << showpoint;  // all floats printed
                                                    // are dollar amounts, so
    // gameplay loop starts here                    // show two decimal places.                            
    while (true) {

        betAmnt = takeBet(usrCash, roundNo);
        if (betAmnt == 0) endGame(allCash, allBets, roundNo);
        
        // start a new hand
        else usrCash -= betAmnt;    // put user bet into the pot
        roundNo++;                  // increment round counter
        
        shuffle(valCard, strCard);
        
        for (int i = 0; i < N_DEAL; i++) {
            cout << strCard[i] << " " << valCard[i] << endl;
        }
    }
}

float takeBet(float usrCash, short rnds) {
    bool    validIn;
    float   betAmnt;
    
    if (usrCash < 50) {
        if (usrCash == 0) {
            cout << "You ran out of money and were" << endl;
            cout << "kicked out of the casino." << endl;
        }
        else {
            cout << "You did not have enough money" << endl;
            cout << "to continue playing and walked" << endl;
            cout << "home in shame." << endl;
        }
        cout << endl;
        cout << "GAME OVER" << endl << endl;
        return 0;
    }
    
    if (rnds == MAXRNDS) {
        cout << "You played until the casino closed" << endl;
        cout << "and they kicked you out." << endl << endl;
        betAmnt = 0;
    }
    else {
        cout << "O-----------BLACKJACK----------O" << endl;
        cout << "|    DEALER MUST HIT SOFT 17   |" << endl;
        cout << "|     BLACKJACK PAYS 3 TO 1    |" << endl;
        cout << "|     FIVE CARD PAYS 5 TO 1    |" << endl;
        cout << "O-----------*˖°.+.°˖*----------O" << endl;

        cout << endl << "You have: $" << usrCash << endl;
        cout << "How much would you like to bet?" << endl << endl;
        cout << "Minimum bet is 50." << endl;
        cout << "Input a bet of 0 to walk away" << endl; 
        cout << "with your current cash." << endl << endl;

        // let user decide to bet or walk away
        do {
            cout << "Enter bet: ";
            cin >> betAmnt;
            cout << endl;

            // validate user input
            if (betAmnt < 50.0f && betAmnt > 0) {
                validIn = false;
                cout << "Bet must be at least 50." << endl;
            }
            else if (betAmnt > usrCash) {
                validIn = false;
                cout << "You can't bet more than you have, wise guy." << endl;
            }
            else if (betAmnt < 0.0f) {
                validIn = false;
                cout << "You can't bet a negative amount. Nice try." << endl;
            }
            else validIn = true;
        } while (validIn == false);
    }
    
    if (betAmnt == 0) {
        cout << "You walked away with $" << usrCash;
        // no need to celebrate if the user didn't win anything
        (usrCash > 1000.0f) ? (cout << "!") : (cout << ".");
        cout << endl;
    }
    return betAmnt;
}

void endGame(float cash[], float bets[], short rnds) {
    fstream outData;
    char    usrInpt;
    short   usrWins,
            usrStrk,
            cntStrk;
    float   sumCash,
            sumBets,
            devCash,
            devBets;
    
    outData.open("usrData.txt", ios::app);
    sumCash = sumBets = usrWins = usrStrk = cntStrk = devCash = devBets = 0;
    
    for (short i = 0; i < rnds; i++) {
        sumCash += cash[i];
        sumBets += bets[i];
        if (cash[i] > 0) {
            usrWins++;
            usrStrk = (++cntStrk > usrStrk) ? cntStrk : usrStrk;
        }
        else cntStrk = 0;
    }
    for (short i = 0; i < rnds; i++) {
        devCash += pow(abs(cash[i] - sumCash/rnds), 2);
        devBets += pow(abs(bets[i] - sumBets/rnds), 2);
    }
    
    outData << "--------------------------------------------" << endl;
    outData << "Hands played...........";
    outData << rnds << endl;
    outData << "Hands lost.............";
    outData << rnds - usrWins << endl;
    outData << "Hands won.............."; 
    outData << usrWins << endl;
    outData << "Best win streak........";
    outData << usrStrk << endl;
    outData << "Average $ won.........$"; 
    outData << ((rnds > 0) ? sumCash/rnds : 0) << endl;
    outData << "Standard deviation....$";
    outData << ((rnds > 0) ? sqrt(devCash / rnds) : 0) << endl;
    outData << "Average $ bet.........$";
    outData << ((rnds > 0) ? sumBets/rnds : 0) << endl;
    outData << "Standard deviation....$";
    outData << ((rnds > 0) ? sqrt(devBets / rnds) : 0) << endl;
    outData << "--------------------------------------------" << endl;
    
    cout << "See session statistics? (y/n)" << endl;
    cout << "Enter decision: ";
    cin >> usrInpt;
    cout << endl;
    
    if (usrInpt == 'y' || usrInpt == 'Y') {
        
        cout << "Hands played...........";
        cout << rnds << endl;
        cout << "Hands lost.............";
        cout << rnds - usrWins << endl;
        cout << "Hands won.............."; 
        cout << usrWins << endl;
        cout << "Best win streak........";
        cout << usrStrk << endl;
        cout << "Average $ won.........$"; 
        cout << ((rnds > 0) ? sumCash/rnds : 0) << endl;
        cout << "Standard deviation....$";
        cout << ((rnds > 0) ? sqrt(devCash / rnds) : 0) << endl;
        cout << "Average $ bet.........$";
        cout << ((rnds > 0) ? sumBets/rnds : 0) << endl;
        cout << "Standard deviation....$";
        cout << ((rnds > 0) ? sqrt(devBets / rnds) : 0) << endl;
    }

    exit(0);
}

void shuffle(short vals[], char strs[][MAXCOLS]) {
    bool    crdUniq;
    short   randVal;
    
    for (char i = char(0); i < N_DEAL; i++) {
        do {
            randVal = rand() % N_DECK + 1;
            crdUniq = true;
            // make sure card id has not been generated yet
            for (char j = char(0); j < i; j++) {
                if (randVal == vals[j]) crdUniq = false;
            }                                        
        } while (crdUniq == false);
        
        vals[i] = randVal;

        // parse how to display a card's face value based on card id
        switch ((randVal-1) % 13)
        {
            case 0:     strs[i][0] = 'A';   
                        break;
            case 1:     strs[i][0] = '2';
                        break;
            case 2:     strs[i][0] = '3';
                        break;
            case 3:     strs[i][0] = '4';
                        break;
            case 4:     strs[i][0] = '5';
                        break;
            case 5:     strs[i][0] = '6';
                        break;
            case 6:     strs[i][0] = '7';
                        break;
            case 7:     strs[i][0] = '8';
                        break;
            case 8:     strs[i][0] = '9';
                        break;
            case 9:     strs[i][0] = 'T';
                        break;
            case 10:    strs[i][0] = 'J';
                        break;
            case 11:    strs[i][0] = 'Q';
                        break;
            default:    strs[i][0] = 'K';
        }

        // parse how to display a card's suit based on card id
        switch ((randVal-1) / 13) 
        {
            case 0:     strs[i][1] = '\xe2';
                        strs[i][2] = '\x99';
                        strs[i][3] = '\xa4';
                        break;
            case 1:     strs[i][1] = '\xe2';
                        strs[i][2] = '\x99';
                        strs[i][3] = '\xa7';
                        break;
            case 2:     strs[i][1] = '\xe2';
                        strs[i][2] = '\x99';
                        strs[i][3] = '\xa1';
                        break;
            default:    strs[i][1] = '\xe2';
                        strs[i][2] = '\x99';
                        strs[i][3] = '\xa2';
        }
        strs[i][4] = '\0';
    }
    return;
}