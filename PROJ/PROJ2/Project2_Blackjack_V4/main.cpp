/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on February 9, 2024, 6:02 PM
 * Purpose: Project2_Blackjack_V4
 */

// system libraries // used to...
#include <iostream> // get user input and display outputs
#include <iomanip>  // format dollar amount outputs
#include <fstream>  // handle session stats & store cards for current hand
#include <string>   // handle "continue" input & suit ascii
#include <cstring>  
#include <cstdlib>  // randomize cards drawn
#include <ctime>    // set the random number seed
#include <cmath>    // calculate standard deviation stats
#include <vector>

using namespace std;

// global constants
const char  N_DECK  = char(52);  // no. of cards in one deck
const char  N_DEAL  = char(9);   // no. of cards needed per hand
const short MAXRNDS = 200;       // maximum no. of rounds
const short MAXCOLS = 5;

bool    askMore(bool &);
float   takeBet(float, float [], float []);
void    endGame(float [], float [], short);
void    dckInit(short [], char [][MAXCOLS], short decks = 1);
void    shuffle(short [], char [][MAXCOLS], short);
void    shuffle(short [], char [][MAXCOLS]);
void    dealCrd(vector<short> &, vector<string> &, short, char[]);
short   calcHnd(vector<short>, bool &);
void    shwStrs(vector<string>, short);
void    shwStrs(vector<string>, short, bool);

// execution begins
int main(void) {

    // set random no. seed
    srand(static_cast<unsigned int>(time(0)));
    
    // local constants
    const short     MAXROWS = 9;
    
    // variable declarations            // used for storing...
    bool            moreDck,
                    usrSoft,
                    usrStnd,
                    dlrSoft,
                    dlrShow,
                    hndOver;
    float           usrCash,            // money in user's wallet
                    betAmnt,            // various floats tied to user bets
                    allCash[MAXRNDS],
                    allBets[MAXRNDS];
    short           decksNo,
                    roundNo,
                    dlrTotl,
                    usrTotl;
    vector<short>   usrVals,
                    dlrVals;
    char            crdsDlt,
                    usrInpt;
    vector<string>  usrStrs,
                    dlrStrs;

    roundNo = 0;
    decksNo = 1;
    usrCash = 1000.0f;  // user starts with $1000.00
    
    //configure output to show two decimal places on dollar amounts
    cout << fixed << setprecision(2) << showpoint;  
    
    if (askMore(moreDck)) {
        cout << "Enter number of decks to use." << endl;
        do {
            cout << "Input number: ";
            cin >> decksNo;
            if (decksNo < 1) {
                cout << "Minimum number of decks is 0.";
                cout << endl << endl;
            }
            else if (decksNo > 8) {
                cout << "Maximum number of decks is 8.";
                cout << endl << endl;
            }
        } while (decksNo < 1 || decksNo > 8);
    }
    
    short   valDeck[N_DECK*decksNo];
    char    strDeck[N_DECK*decksNo][MAXCOLS];
    
    (moreDck) ? dckInit(valDeck, strDeck, decksNo) :
                dckInit(valDeck, strDeck);
                                                    
    // gameplay loop starts 
    while (true) {
        betAmnt = takeBet(usrCash, allCash, allBets);
        
        // start a new hand
        usrCash -= betAmnt;    // put user bet into the pot
        roundNo++;
        
        (moreDck) ? shuffle(valDeck, strDeck, decksNo) :
                    shuffle(valDeck, strDeck);
        
        for (int i = 0; i < N_DECK*decksNo; i++) {
            cout << strDeck[i] << " " << valDeck[i] << endl;
        }
        
        crdsDlt = 0;
        usrSoft = dlrSoft = usrStnd = false;
        while (crdsDlt < 4) {
            dealCrd(usrVals, usrStrs, valDeck[crdsDlt], strDeck[crdsDlt]);
            crdsDlt++;
            dealCrd(dlrVals, dlrStrs, valDeck[crdsDlt], strDeck[crdsDlt]);
            crdsDlt++;
        }
        
        cout << endl;
        for (short i = 0 ; i < 2; i++) {
            cout << usrStrs[i] << " " << usrVals[i] << endl;
            cout << dlrStrs[i] << " " << dlrVals[i] << endl;
        }
        
        do {
            usrTotl = calcHnd(usrVals, usrSoft);
            dlrTotl = calcHnd(dlrVals, dlrSoft);
            
            // current hand should be over if...
            // user has blackjack
            hndOver = 
            (usrStrs.size()==2 && usrTotl==21)  ? true : 
            // dealer has blackjack    
            (dlrStrs.size()==2 && dlrTotl==21)  ? true :
            // dealer beat the user
            (dlrShow && dlrTotl > usrTotl)      ? true :
            // dealer got at least 17
            (dlrShow && dlrTotl>=17)            ? true :
            // user busted
            (usrTotl>=22)                       ? true :
            // dealer busted
            (dlrTotl>=22)                       ? true :
            // user got five-card charlie
            (usrStrs.size()==5)                 ? true :
            // dealer got five-card charlie
            (dlrStrs.size()==5)                 ? true : false;
            
            if (hndOver && dlrTotl==17 && dlrSoft == true) hndOver = false;
            
            if (hndOver || usrStnd || usrTotl > 20) dlrShow = true;
            
            if (usrStrs.size()<5 && usrTotl == 21 && usrSoft) dlrShow = false;
            
            shwStrs(dlrStrs, dlrTotl, dlrShow);
            shwStrs(usrStrs, usrTotl);
            
//            if (!usrStnd && !dlrShow && !hndOver)
            
        } while (false);
    }
}

bool askMore(bool &moreDck) {
    char usrInpt;
    
    cout << "Would you like to choose how many" << endl;
    cout << "decks are used in this session? (y/n)" << endl;
    cin >> usrInpt;
    
    if (usrInpt == 'y' || usrInpt == 'Y') {
        moreDck = true;
        return moreDck;
    }
    
    moreDck = false;
    return moreDck;
}

float takeBet(float usrCash, float cash[], float bets[]) {
    bool            validIn;
    float           betAmnt;
    static short    roundNo = 0;
    
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
        endGame(cash, bets, roundNo);
    }
    
    if (roundNo == MAXRNDS) {
        cout << "You played until the casino closed" << endl;
        cout << "and they kicked you out." << endl << endl;
        endGame(cash, bets, roundNo);
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
        endGame(cash, bets, roundNo);
    }
    
    roundNo++;
    
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
        cout << endl;
    }
    
    cout << "Thank you for playing!" << endl;

    exit(0);
}

void dckInit(short vals[], char strs[][MAXCOLS], short decks) {
    
    for (short i = 0; i < N_DECK*decks; i++) {
        
        vals[i] = i+1;

        // parse how to display a card's face value based on card id
        switch (i % 13)
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
        switch (i / 13) 
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

void shuffle(short vals[], char strs[][MAXCOLS], short decks) {
    for (short card = 0; card < N_DECK*decks; card++) {
        char    tempStr[MAXCOLS];
        short   tempVal;
        
        short swap = card + rand()%(N_DECK*decks - card);
        
        strcpy(tempStr, strs[card]);
        strcpy(strs[card], strs[swap]);
        strcpy(strs[swap], tempStr);
        
        tempVal = vals[card];
        vals[card] = vals[swap];
        vals[swap] = tempVal;
    }
    return;
}

void shuffle(short vals[], char strs[][MAXCOLS]) {
    for (short card = 0; card < N_DECK; card++) {
        char    tempStr[MAXCOLS];
        short   tempVal;
        
        short swap = card + rand()%(N_DECK - card);
        
        strcpy(tempStr, strs[card]);
        strcpy(strs[card], strs[swap]);
        strcpy(strs[swap], tempStr);
        
        tempVal = vals[card];
        vals[card] = vals[swap];
        vals[swap] = tempVal;
    }
    return;
}

void dealCrd(vector<short> &vals, vector<string> &strs, short v, char s[]) {
    vals.push_back(v);
    strs.push_back(s);
    return;
}

short calcHnd(vector<short> vals, bool &soft) {
    short val;
    short total = 0;
    for (char curCard = char(0); curCard < vals.size(); curCard++) {
        val = (vals[curCard]-1)%13+1;
        if (val > 10) val = 10;
        total += val;
        
        if (val == 1 && total < 12 && !soft) {
            total += 10;
            soft = true;
        }
        else if (soft && total > 21) {
            total -= 10;
            soft = false;
        }
    }
    return total;
}

void shwStrs(vector<string> strs, short total, bool show) {
    cout << "Dealer: ";
    if (show) cout << total;
    cout << endl;
    
    for (char curCard = char(0); curCard < strs.size(); curCard++) {
        if (!show && curCard == 1) cout << "??";
        else cout << strs[curCard];
        cout << " ";
    }
    cout << endl << endl;
}

void shwStrs(vector<string> strs, short total) {
    cout << "Player: " << total << endl;
    
    for (char curCard = char(0); curCard < strs.size(); curCard++) {
        cout << strs[curCard] << " ";
    }
    cout << endl << endl;
}

