/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on February 1, 2024, 3:11 PM
 * Purpose: Project1_Blackjack_V8
 */

// system libraries // used to...
#include <iostream> // get user input and display outpurs
#include <iomanip>  // format dollar amount outputs
#include <fstream>  // handle session stats & store cards for current hand
#include <string>   // handle "continue" input & suit ascii
#include <cstdlib>  // randomize cards drawn
#include <ctime>    // set the random number seed
#include <cmath>    // calculate standard deviation stats

using namespace std;

// execution begins
int main(void) {

    srand(static_cast<unsigned int>(time(0)));  // set the random no. seed
    
    // named constants
    const unsigned char N_DECK = char(52);  // number of possible cards to draw
    const unsigned char N_DEAL = char(9);   // number of cards needed per hand
    
    // variable declarations    // used for storing...
    float           tempFlt,    // temporary float values
                    usrCash,    // money in user's wallet
                    sumCash,    // sum of all money won or lost 
                    avgDvia,    // radicand for sd of average money won/lost
                    betAmnt,    // various floats tied to user bets
                    sumBets,    // sum of all user bets
                    betDvia;    // radicand for sd of average user bet
    bool            validIn,    // whether user input is valid
                    crdUniq,    // whether generated card was already made
                    hndOver,    // whether hand will end after current loop
                    usrStnd,    // whether user is done drawing cards
                    dlrShow,    // whether to show dealer's hidden card
                    dlrSoft,    // whether dealer has a soft ace
                    usrSoft,    // whether user has a soft ace
                    usrWon;     // whether user won the current hand
    unsigned char   crdFace,    // ascii value of card's face value
                    crdsDlt,    // no. of total cards drawn in current hand
                    dlrCrds,    // no. of cards currently in dealer's hand
                    usrCrds,    // no. of cards currently in user's hand
                    usrInpt;    // one-character decision input from user
    unsigned short  randVal,    // random value generated for card id
                    readVal,    // reading card ids from crdVals.dat
                    dlrHand,    // total value of the dealer's cards
                    usrHand,    // total value of the user's cards
                    usrWins,    // total number of hands won by user
                    usrStrk,    // current user win-streak
                    bstStrk,    // best user win-streak from this session
                    roundNo;    // total no. of rounds played this session
    string          tempStr;    // any string (all strings are temporary)
    
    // file i/o objects         // used for...
    fstream         outVals,    // writing card ids to crdVals.dat
                    outStrs,    // writing card strings to crdStrs.dat
                    outCash,    // writing $ won/lost per hand to hndData.dat
                    outBets,    // writing $ user bet per hand to betData.dat
                    inVals,     // reading card ids from crdVals.dat
                    inStrs,     // reading card strings from crdStrs.dat
                    inCash,     // reading $ won/lost per hand from hndData.dat
                    inBets;     // reading $ user bet per hand from betData.dat

    // initialize session log fstream objects & starting variable values 
    outCash.open("hndData.dat", ios::out);  // outCash and outBets stay
    outBets.open("betData.dat", ios::out);  // open until program closes.
    usrStrk = bstStrk = avgDvia = avgDvia = betDvia = 0;
    usrWins = roundNo = sumCash = sumBets = 0;  // set accumulators to 0.
    usrCash = 1000.0f;  // user starts with $1000.00
    
    cout << fixed << setprecision(2) << showpoint;  // all floats printed
                                                    // are dollar amounts, so
    // gameplay loop starts here                    // show two decimal places.                            
    while (true) {

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
            betAmnt = 0;    // resets for every hand
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
        
        // display ending messages if user decides to walk away
        if (betAmnt == 0) {
            cout << "You walked away with $" << usrCash;
            // no need to celebrate if the user didn't win anything
            (usrCash > 1000.0f) ? (cout << "!") : (cout << ".");
            cout << endl;
            cout << "See session statistics? (y/n)" << endl;
            cout << "Enter decision: ";
            cin >> usrInpt;
            cout << endl;
            if (usrInpt == 'y' || usrInpt == 'Y') {
                
                // start reading final session data now that game is over
                inCash.open("hndData.dat", ios::in);
                inBets.open("betData.dat", ios::in);
                
                // standard deviation is evaluated as the square root of (e/n)
                // where n = the number of values in the data set and
                // where e = the sum of ((each value - mean of data set)^2)
                while (inCash >> tempFlt && inBets >> betAmnt) {
                    avgDvia += pow(abs(tempFlt - sumCash/roundNo), 2);
                    betDvia += pow(abs(betAmnt - sumBets/roundNo), 2);
                }
                
                // stop reading final session data
                inCash.close();
                inBets.close();
                
                cout << "Hands played...........";
                cout << roundNo << endl;
                cout << "Hands lost.............";
                cout << roundNo - usrWins << endl;
                cout << "Hands won.............."; 
                cout << usrWins << endl;
                cout << "Best win streak........";
                cout << bstStrk << endl;
                cout << "Average $ won.........$"; 
                cout << sumCash/roundNo << endl;
                cout << "Standard deviation....$";
                cout << sqrt(avgDvia / roundNo) << endl;
                cout << "Average $ bet.........$";
                cout << sumBets/roundNo << endl;
                cout << "Standard deviation....$";
                cout << sqrt(betDvia / roundNo) << endl;
            }
            //close remaining .dat files now that game is over
            outCash.close();
            outBets.close();
            
            // exit stage right
            return 0;
        }
        // start a new hand
        else usrCash -= betAmnt;    // put user bet into the pot
        roundNo++;                  // increment round counter
        
        // start writing card data to their respective files
        outVals.open("crdVals.dat", ios::out);
        outStrs.open("crdStrs.dat", ios::out);
        
        /* 
         * in (this version of) blackjack, the player automatically
         * wins the hand if they are dealt 5 cards without busting.
         * this is called a "five-card charlie" and is controversial.
         * http://tinyurl.com/y6pv4mjz
         * 
         * this program simulates the rules of blackjack according
         * to the blackjack minigame found in the 2006 playstation 2
         * game "GOD HAND", a game i have played a lot.
         * http://tinyurl.com/ds4nyvvk
         * 
         * these are not casino rules by any means - but i find them
         * to be more fun because the player is slightly more at an
         * advantage than in a true game of casino blackjack.
         * 
         * these rules mean that the maximum number of cards that
         * can be used in one hand is 9, which would occur if the
         * player stands on 4 cards before the dealer wins with
         * a five-card charlie.
         * 
         * this is why N_DEAL == 9, and the loop below generates
         * 9 unique cards to use during the current hand.
         * 
         * the player could cheat by reading crdStrs.dat as they
         * play, but if they're playing this game in an IDE like
         * my professor will, they could already cheat anyway.
        */
        
        // generate nine random cards to store their id & string
        for (char i = char(0); i < N_DEAL; i++) {
            do {
                inVals.open("crdVals.dat", ios::in);
                // generate random card id between 1 & 52
                // instead of 0-51 for my own sanity when calculating
                // hand totals later (A=1, 2=2, 3=3, 10=10, etc).
                randVal = rand() % N_DECK + 1;
                crdUniq = true;
                // make sure card id has not been generated yet
                while (inVals >> readVal && crdUniq == true) {     
                    if (randVal == readVal) crdUniq = false;                               
                }                               
                inVals.close();                 
            } while (crdUniq == false);
            // write current unique card id to crdVals.dat
            outVals << randVal << endl;
            
            // parse how to display a card's face value based on card id
            switch ((randVal-1) % 13)
            {
                case 0:     crdFace = 'A';   
                            break;
                case 1:     crdFace = '2';
                            break;
                case 2:     crdFace = '3';
                            break;
                case 3:     crdFace = '4';
                            break;
                case 4:     crdFace = '5';
                            break;
                case 5:     crdFace = '6';
                            break;
                case 6:     crdFace = '7';
                            break;
                case 7:     crdFace = '8';
                            break;
                case 8:     crdFace = '9';
                            break;
                case 9:     crdFace = 'T';
                            break;
                case 10:    crdFace = 'J';
                            break;
                case 11:    crdFace = 'Q';
                            break;
                default:    crdFace = 'K';
            }
            
            // parse how to display a card's suit based on card id
            switch ((randVal-1) / 13) 
            {
                case 0:     tempStr = "♤";
                            break;
                case 1:     tempStr = "♧";
                            break;
                case 2:     tempStr = "♡";
                            break;
                default:    tempStr = "♢";
            }
            // write current unique card's face & suit to crdStrs.dat
            outStrs << crdFace << tempStr << endl;
        }
        // stop writing card data to their respective files
        outVals.close();
        outStrs.close();

        // initialize starting values for current hand
        usrStnd = dlrShow = hndOver = false;
        usrCrds = dlrCrds = 2;    // start user & dealer with two cards

        do {
            // initialize values for current turn
            usrHand = dlrHand = 0;
            usrSoft = dlrSoft = usrWon = false;
            crdsDlt = usrCrds + dlrCrds;
            
            /*
             * in both crdVals.dat and crdStrs.dat, the dealer's cards
             * are stored at the beginning and end of the .dat files.
             * this is because a hand follows this order of turns:
             * 
             * 1. dealer + user both get two cards
             * 2. user has to stand/hit first
             * 3. dealer has to stand/hit last
             * 
             * because it is unknown how many cards both the user
             * & dealer will draw each hand, and there is no way of knowing
             * whether it could be the user or dealer who wins by a 
             * five-card charlie, it's easiest to simply dedicate the first
             * two lines of the .dat cards to the dealer's starting two cards
             * and then dedicate however many cards the user ends up with
             * after the dealer's first two cards.
             * 
             * this also accurately simulates drawing a card from the deck
             * whenever the user or dealer hits, because it means either
             * of them could have gotten that card.
             * 
             * this makes reading the .dat files slower, but i think
             * it's more fair to faithfully simulate drawing from the deck.
             */

            // calculate hand totals before cards are displayed
            // calculate totals separately to maintain my sanity
            // calculate dealer total first
            inVals.open("crdVals.dat", ios::in);
            for (char curCard = char(1); curCard <= crdsDlt; curCard++) { 
                // read next card in the file
                inVals >> readVal;
                
                // skip card if it belongs to the user
                if (curCard > 2 && curCard <= usrCrds+2) continue;

                readVal = (readVal-1)%13+1;     // parse the card face
                if (readVal > 10) readVal = 10; // set to 10 if J, Q, or K
                dlrHand += readVal;
                
                // if card is an ace, hand is hard, and soft ace won't bust
                if (readVal == 1 && dlrHand < 12 && !dlrSoft) {
                    dlrHand += 10;  // 11 (soft ace) - 1 (hard ace) = 10
                    dlrSoft = true; // flag to track soft ace for later loops
                }
                // check if earlier soft ace should be hard to prevent bust
                else if (dlrSoft && dlrHand > 21) {
                    dlrHand -= 10;  
                    dlrSoft = false;
                }
            }
            inVals.close();

            // calculate player total last
            inVals.open("crdVals.dat", ios::in);
            for (char curCard = char(1); curCard <= usrCrds+2; curCard++) {
                inVals >> readVal;
                
                // skip card if it's one of the dealer's starting cards
                if (curCard <= 2) continue;

                readVal = (readVal-1)%13+1;
                if (readVal > 10) readVal = 10;
                usrHand += readVal;
                
                if (readVal == 1 && usrHand < 12 && !usrSoft) {
                    usrHand += 10;
                    usrSoft = true;
                }
                else if (usrSoft && usrHand > 21) {
                    usrHand -= 10;
                    usrSoft = false;
                }
            }
            inVals.close();
            
            // current hand should be over if...
            // user has blackjack
            (usrCrds == 2 && usrHand == 21) ? hndOver = true : 
            // dealer has blackjack    
            (dlrCrds == 2 && dlrHand == 21) ? hndOver = true :
            // dealer beat the user
            (dlrShow && dlrHand > usrHand)  ? hndOver = true :
            // dealer got at least 17
            (dlrShow && dlrHand >= 17)      ? hndOver = true :
            // user busted
            (usrHand >= 22)                 ? hndOver = true :
            // dealer busted
            (dlrHand >= 22)                 ? hndOver = true :
            // user got five-card charlie
            (usrCrds == 5)                  ? hndOver = true :
            // dealer got five-card charlie
            (dlrCrds == 5)                  ? hndOver = true : hndOver = false;
            
            // however, dealer must hit again if they have a soft 17
            if (hndOver && dlrHand == 17 && dlrSoft == true) hndOver = false;
            
            // show dealer's hidden card if user can't draw more cards
            // check this after checking for hand-end conditions as to
            // allow the user a chance to hit continue again, or else
            // the messages could display a little too fast
            if (hndOver || usrStnd || usrHand>20) dlrShow = true;
            
            // allow user to keep going for five cards if they can
            if (usrCrds < 5 && usrHand == 21 && usrSoft) dlrShow = false;

            // display dealer cards & total first
            inStrs.open("crdStrs.dat", ios::in);
            for (char curCard = char(1); curCard <= crdsDlt; curCard++) {
                // read next card in the file
                inStrs >> tempStr;
                
                // display dealer's total only if hidden card is revealed
                if (curCard == 1) {
                    cout << "Dealer: ";
                    if (dlrShow) (cout << dlrHand);
                    cout << endl << tempStr << " ";
                }
                // hide dealer's hidden card if user can still hit
                else if (curCard == 2) {
                    cout << (dlrShow ? tempStr : "??") << " ";
                }
                // skip if card belongs to the user
                else if (curCard <= usrCrds+2) continue;
                // show any additional cards
                else {
                    cout << tempStr << " ";
                }
            }
            inStrs.close();
            cout << endl << endl;

            // display player cards & total last
            inStrs.open("crdStrs.dat", ios::in);
            for (char curCard = char(1); curCard <= usrCrds+2; curCard++) {
                inStrs >> tempStr;
                
                // skip if one of the dealer's starting cards
                if (curCard <= 2) continue;
                // display user's total and first card
                else if (curCard == 3) {
                    cout << "Player: " << usrHand << endl << tempStr << " ";
                }
                // display any additional cards
                else {
                    cout << tempStr << " ";
                }
            }
            inStrs.close();
            cout << endl << endl;
            
            // if user can still hit, let them choose if they want to
            if (!usrStnd && !dlrShow && !hndOver) {
                cout << "Pot total: $" << betAmnt << endl;
                cout << "You have: $" << usrCash << endl << endl;
                cout << "What would you like to do?" << endl;
                cout << "Type S to Stand" << endl;
                cout << "Type H to Hit" << endl;
                // don't display double-down option if user can't do it
                if (usrCash >= betAmnt && usrCrds == 2) {
                    cout << "Type D to Double Down" << endl;
                }
                
                // validate input
                do {
                    cout << "Enter decision: ";
                    cin >> usrInpt;
                    validIn = true;
                    
                    switch (usrInpt) 
                    {
                        case 's':   // indicate user is done drawing cards
                        case 'S':   usrStnd = true;
                                    break;
                        case 'h':   // give user another card
                        case 'H':   usrCrds++;
                                    break;
                        case 'd':   // if user can't double down but tries...
                        case 'D':   if (usrCash < betAmnt || usrCrds != 2) {
                                        validIn = false;
                                    }
                                    else {
                                        // user must stand after double down
                                        usrStnd = true;
                                        usrCrds++;
                                        //add double down to the pot
                                        usrCash -= betAmnt;
                                        betAmnt += betAmnt;
                                    }
                                    break;
                        default:    validIn = false;
                    }
                    
                    // display why input is invalid
                    if (validIn == false) {
                        if ((usrInpt=='d' || usrInpt=='D') && usrCrds != 2) {
                            cout << "You can only double down" << endl;
                            cout << "if you have two cards.";
                        }
                        else if (usrInpt=='d' || usrInpt=='D') {
                            cout << "You need to have at least" << endl;
                            cout << "$" << betAmnt << " to double down.";
                        }
                        else {
                            cout << "Invalid input.";
                        }
                        cout << endl << endl;
                    }
                    
                } while (validIn == false);
                cout << endl;
            }
            // allow user to view one dealer turn at a time
            else if (!hndOver) {
                cout << "Enter any text to continue." << endl;
                cin >> tempStr;
                cout << endl;
            }
            
            // if it's the dealer's turn...
            if (dlrShow && !hndOver) {
                // decide if dealer needs to hit 
                if (dlrHand < 17 || (dlrHand == 17 && dlrSoft)) {
                    cout << "DEALER HITS" << endl << endl;
                    dlrCrds++;
                }
            }
        } while (!hndOver);
        
        // hand is over, so log how much the user bet this hand
        // we do this after the hand instead of before because the user
        // can choose to double down during the hand, which is another bet
        sumBets += betAmnt;
        outBets << betAmnt << endl;
        
        // determine who won and how
        // now that we've logged how much the user bet, we can re-purpose
        // betAmnt to log how much money the user won/lost this hand
        if (usrHand > 21) {
            cout << "YOU BUST" << endl;
            cout << "DEALER WINS" << endl;
            betAmnt *= -1;  // make betAmnt negative to log a loss
        }
        else if (dlrHand > 21) {
            cout << "DEALER BUSTS" << endl;
            cout << "YOU WIN!" << endl;
            betAmnt *= 2;   // standard win pays 1 to 1
            usrWon = true;
        }
        else if (usrCrds == 5 || dlrCrds == 5) {
            cout << "FIVE CARDS" << endl;
            if (usrCrds == 5) {
                cout << "YOU WIN!" << endl;
                betAmnt *= 6;   // five cards pays 5 to 1
                usrWon = true;
            }
            else {
                cout << "DEALER WINS" << endl;
                betAmnt *= -1;
            }
        }
        else if ((usrCrds==2 && usrHand==21) || (dlrHand==21 && dlrCrds==2)) {
            cout << "BLACKJACK" << endl;
            if ((usrCrds==2 && usrHand==21) && (dlrHand==21 && dlrCrds==2)) {
                cout << "TIE" << endl;
                usrCash += betAmnt; // return pot to the user
                betAmnt = 0;    // set betAmnt to zero to log a tie
            }
            else if (usrHand == 21 && usrCrds == 2) {
                cout << "YOU WIN!" << endl;
                betAmnt *= 4;   // blackjack pays 3 to 1
                usrWon = true;
            }
            else {
                cout << "DEALER WINS" << endl;
                betAmnt *= -1;
            }
        }
        else if (usrHand == dlrHand) {
            cout << "DEALER STANDS" << endl;
            cout << "TIE" << endl;
            usrCash += betAmnt;
            betAmnt = 0;
        }
        else {
            cout << "DEALER STANDS" << endl;
            if (usrHand > dlrHand) {
                cout << "YOU WIN!" << endl;
                betAmnt *= 2;
                usrWon = true;
            }
            else {
                cout << "DEALER WINS" << endl;
                betAmnt *= -1;
            }
        }
        cout << endl;
        
        if (usrWon) {
            usrCash += betAmnt; // award player any money won
            usrWins++;          // increment user's total win count
            usrStrk++;          // increment user's current win streak count
            // if current streak is user's best, update bstStrk
            if (usrStrk > bstStrk) bstStrk = usrStrk;
        }
        else usrStrk = 0;
        
        // log the total amount of money won/lost this hand
        sumCash += betAmnt;
        outCash << betAmnt << endl;
        
        // if user cannot bet anymore, the game is over
        if (usrCash < 50) {
            if (usrCash == 0 ) {
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
            
            // still let user choose to see their stats on a game over
            cout << "See session statistics? (y/n)" << endl;
            cout << "Enter decision: ";
            cin >> usrInpt;
            cout << endl;
            
            // see line 127, code is identical
            if (usrInpt == 'y' || usrInpt == 'Y') {
                inCash.open("hndData.dat", ios::in);
                inBets.open("betData.dat", ios::in);
                while (inCash >> tempFlt && inBets >> betAmnt) {
                    avgDvia += pow(tempFlt - sumCash/roundNo, 2);
                    betDvia += pow(betAmnt - sumBets/roundNo, 2);
                }
                cout << "Hands played...........";
                cout << roundNo << endl;
                cout << "Hands lost.............";
                cout << roundNo - usrWins << endl;
                cout << "Hands won.............."; 
                cout << usrWins << endl;
                cout << "Best win streak........";
                cout << bstStrk << endl;
                cout << "Average $ won.........$"; 
                cout << sumCash/roundNo << endl;
                cout << "Standard deviation....$";
                cout << sqrt(avgDvia / roundNo) << endl;
                cout << "Average $ bet.........$";
                cout << sumBets/roundNo << endl;
                cout << "Standard deviation....$";
                cout << sqrt(betDvia / roundNo) << endl;
            }
            // close remaining .dat files now that game is over
            outCash.close();
            outBets.close();
            
            // exit stage left
            return 0;
        }
        cout << endl;
    }
}
