/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on February 8, 2024, 3:28 PM
 * Purpose: Project2_Blackjack_V1
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

// named constants
const unsigned char     N_DECK = char(52);  // number of possible cards to draw
const unsigned char     N_DEAL = char(9);   // number of cards needed per hand
const short             M_RNDS = 200;

float takeBet(float);
void endGame(float [], float [], short);

// execution begins
int main(void) {

    srand(static_cast<unsigned int>(time(0)));  // set the random no. seed
    
    // variable declarations    // used for storing...
    float           usrCash,    // money in user's wallet
                    betAmnt,    // various floats tied to user bets
                    allCash[M_RNDS],
                    allBets[M_RNDS];
    short           roundNo;
    
    

    // initialize session log fstream objects & starting variable values 
    roundNo = 0;  // set accumulators to 0.
    usrCash = 1000.0f;  // user starts with $1000.00
    
    cout << fixed << setprecision(2) << showpoint;  // all floats printed
                                                    // are dollar amounts, so
    // gameplay loop starts here                    // show two decimal places.                            
    while (true) {

        betAmnt = takeBet(usrCash);
        
        if (betAmnt == 0) {
            //close remaining .dat files now that game is over
            endGame(allCash, allBets, roundNo);
        }
        
        // start a new hand
        else usrCash -= betAmnt;    // put user bet into the pot
        roundNo++;                  // increment round counter
    }
}

float takeBet(float usrCash) {
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
    outData << sumCash/rnds << endl;
    outData << "Standard deviation....$";
    outData << sqrt(devCash / rnds) << endl;
    outData << "Average $ bet.........$";
    outData << sumBets/rnds << endl;
    outData << "Standard deviation....$";
    outData << sqrt(devBets / rnds) << endl;
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
        cout << sumCash/rnds << endl;
        cout << "Standard deviation....$";
        cout << sqrt(devCash / rnds) << endl;
        cout << "Average $ bet.........$";
        cout << sumBets/rnds << endl;
        cout << "Standard deviation....$";
        cout << sqrt(devBets / rnds) << endl;
    }
    
    exit(0);
}