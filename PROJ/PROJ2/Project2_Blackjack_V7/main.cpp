/* 
 * File:    main.cpp
 * Author:  Noah Garthwaite
 * Created on February 10, 2024, 4:03 PM
 * Purpose: Project2_Blackjack_V7
 */

// system libraries // used to...
#include <iostream> // get user input and display outputs
#include <iomanip>  // format dollar amount outputs
#include <fstream>  // handle session stats & store cards for current hand
#include <string>   // handle "continue" input & suit ascii
#include <cstring>  // shuffle str values via strcpy
#include <cstdlib>  // randomize cards drawn
#include <ctime>    // set the random number seed
#include <cmath>    // calculate standard deviation stats
#include <vector>   // dynamically add cards to hands

using namespace std;

// global constants
const char  N_DECK  = char(52); // no. of cards in one deck
const short MAXRNDS = 200;      // maximum no. of rounds
const short MAXCOLS = 5;        // size of 

// function prototypes
bool    askMore(bool &);
float   takeBet(float, float [], float []);
void    endGame(float [], float [], short);
void    dckInit(short [], char [][MAXCOLS], short decks = 1);
void    shuffle(short [], char [][MAXCOLS], short);
short   calcHnd(vector<short>, bool &);
void    shwStrs(vector<string>, short);
void    shwStrs(vector<string>, short, bool);
void    selSrt(float [], short);
void    bublSrt(float [], short);
bool    binSrch(float [], short, float);  

// execution begins
int main(void) {

    // set random no. seed
    srand(static_cast<unsigned int>(time(0)));
    
    // variable declarations            // used for storing...
    bool            moreDck,            // if more than one deck is used
                    usrSoft,            // if user has a soft ace
                    usrStnd,            // if user can draw more cards
                    dlrSoft,            // if dealer has a soft ace
                    dlrShow,            // if dealer's cards are shown
                    hndOver,            // if hand should end
                    validIn;            // if user input is valid
    char            crdsDlt,            // total cards dealt this hand
                    usrCrds,            // total cards user has
                    dlrCrds,            // total cards dealer has
                    usrInpt;            // one-character user input
    float           usrCash,            // money in user's wallet
                    betAmnt,            // floats tied to user bets
                    allCash[MAXRNDS],   // money won/lost each hand
                    allBets[MAXRNDS];   // money bet each hand
    short           decksNo,            // number of decks to use
                    roundNo,            // total rounds played
                    dlrTotl,            // total value of dealer's cards
                    usrTotl;            // total value of user's cards
    vector<short>   usrVals,            // ids of user's cards
                    dlrVals;            // ids of dealer's cards
    string          strInpt;            // multi-character user input
    vector<string>  usrStrs,            // user's card strings
                    dlrStrs;            // dealer's card strings

    roundNo = 0;
    decksNo = 1;        // default no. of decks
    usrCash = 1000.0f;  // user starts with $1000.00
    
    //configure output to show two decimal places on dollar amounts
    cout << fixed << setprecision(2) << showpoint;  
    
    if (askMore(moreDck)) {
        cout << endl << "Enter number of decks to use." << endl;
        do {
            cout << "Input number: ";
            cin >> decksNo;
            if (decksNo < 1) 
                cout << "Minimum number of decks is 0.";
            else if (decksNo > 8) 
                cout << "Maximum number of decks is 8.";
            cout << endl << endl;
        } while (decksNo < 1 || decksNo > 8);
    }
    
    // initialize deck arrays now that decksNo is decided
    short   valDeck[N_DECK*decksNo];
    char    strDeck[N_DECK*decksNo][MAXCOLS];
    
    // fill deck(s) via redundant code to meet project criteria
    (moreDck) ? dckInit(valDeck, strDeck, decksNo) :
                dckInit(valDeck, strDeck);
                                                    
    // gameplay loop starts 
    while (true) {
        // get user bet & check if game should end
        betAmnt = takeBet(usrCash, allCash, allBets);
        
        // put user bet into the pot
        usrCash -= betAmnt;    
        
        // shuffle deck(s)
        shuffle(valDeck, strDeck, decksNo);
                
        // empty dealer & user hands
        usrVals.clear();
        usrStrs.clear();
        dlrVals.clear();
        dlrStrs.clear();
        
        // reset hand bools
        usrStnd = hndOver = dlrShow = false;
        
        // deal starting cards in proper order
        for (char i = 0; i < 4; i += 2) {
            usrVals.push_back(valDeck[i]);
            usrStrs.push_back(strDeck[i]);
            dlrVals.push_back(valDeck[i+1]);
            dlrStrs.push_back(strDeck[i+1]);
        }
        
        // begin hand loop
        do {
            // track how many cards are in hands
            usrCrds = usrVals.size();
            dlrCrds = dlrVals.size();
            crdsDlt = usrCrds + dlrCrds;
            
            // reset soft ace bools
            dlrSoft = usrSoft = false;
            usrTotl = calcHnd(usrVals, usrSoft);
            dlrTotl = calcHnd(dlrVals, dlrSoft);
            
            // check if user can draw more cards
            if (usrStnd || usrTotl > 20)
                dlrShow = true;
            // ... unless user can still go for five cards
            if (usrCrds < 5 && usrCrds > 2 && !usrStnd)
                if (usrTotl == 21 && usrSoft)
                    dlrShow = false;
            
            // current hand should be over if...
            hndOver = 
            // user has blackjack
            (usrCrds == 2 && usrTotl == 21)     ? true  :
            // dealer has blackjack
            (dlrCrds == 2 && dlrTotl == 21)     ? true  :
            // user busted
            (usrTotl >= 22 || dlrTotl >= 22)    ? true  :
            // user got five cards
            (usrCrds == 5 || dlrCrds == 5)      ? true  :
            // dealer beat the user
            (dlrShow && dlrTotl > usrTotl)      ? true  :
            // check for soft 17
            (dlrSoft && dlrTotl == 17)          ? false :
            // dealer must stand
            (dlrShow && dlrTotl >= 17)          ? true  : false;
            
            // show dealer cards if hand is over
            if (hndOver) dlrShow = true;
            
            // display dealer and user cards
            shwStrs(dlrStrs, dlrTotl, dlrShow);
            shwStrs(usrStrs, usrTotl);
            
            // prompt user decision if they can make one
            if (!dlrShow) {
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
                        case 'H':   usrVals.push_back(valDeck[crdsDlt]);
                                    usrStrs.push_back(strDeck[crdsDlt]);
                                    break;
                        case 'd':   // if user can't double down but tries
                        case 'D':   if (usrCash < betAmnt || usrCrds != 2) {
                                        validIn = false;
                                    }
                                    else {
                                        // user must stand after double down
                                        usrStnd = true;
                                        usrVals.push_back(valDeck[crdsDlt]);
                                        usrStrs.push_back(strDeck[crdsDlt]);
                                        usrCash -= betAmnt;
                                        betAmnt += betAmnt;
                                    }
                                    break;
                        default:    validIn = false;
                    }
                    // display why input is invalid
                    if (!validIn) {
                        if (usrInpt == 'd' || usrInpt == 'D') {
                            if (usrCrds != 2) {
                                cout << "You can only double down" << endl;
                                cout << "if you have two cards.";
                            }
                            else {
                                cout << "You need to have at least" << endl;
                                cout << "$" << betAmnt << " to double down.";
                            }
                        }
                        else cout << "Invalid input.";
                        cout << endl << endl;
                    }
                } while (!validIn);
                cout << endl;
            }
            else {
                cout << "Enter any text to continue." << endl;
                cin >> strInpt;
                cout << endl;
            }
            
            if (dlrShow && !hndOver) {
                cout << "DEALER HITS" << endl << endl;
                dlrVals.push_back(valDeck[crdsDlt]);
                dlrStrs.push_back(strDeck[crdsDlt]);
            }
        } while (!hndOver);
        
        // log how much was bet this hand
        allBets[roundNo] = betAmnt;
        
        // determine winner
        if (usrTotl > 21) {
            cout << "YOU BUST" << endl;
            cout << "DEALER WINS" << endl;
            betAmnt *= -1;  // make betAmnt negative to log a loss
        }
        else if (dlrTotl > 21) {
            cout << "DEALER BUSTS" << endl;
            cout << "YOU WIN!" << endl;
            betAmnt *= 2;   // standard win pays 1 to 1
        }
        else if (usrCrds == 5 || dlrCrds == 5) {
            cout << "FIVE CARDS" << endl;
            if (usrCrds == 5) {
                cout << "YOU WIN!" << endl;
                betAmnt *= 6;   // five cards pays 5 to 1
            }
            else {
                cout << "DEALER WINS" << endl;
                betAmnt *= -1;
            }
        }
        else if (crdsDlt == 4 && (dlrTotl == 21 || usrTotl == 21)) {
            cout << "BLACKJACK" << endl;
            if (usrTotl == 21 && dlrTotl == 21) {
                cout << "TIE" << endl;
                usrCash += betAmnt; // return pot to the user
                betAmnt = 0;    // set betAmnt to zero to log a tie
            }
            else if (usrTotl == 21) {
                cout << "YOU WIN!" << endl;
                betAmnt *= 4;   // blackjack pays 3 to 1
            }
            else {
                cout << "DEALER WINS" << endl;
                betAmnt *= -1;
            }
        }
        else if (usrTotl == dlrTotl) {
            cout << "DEALER STANDS" << endl;
            cout << "TIE" << endl;
            usrCash += betAmnt;
            betAmnt = 0;
        }
        else {
            cout << "DEALER STANDS" << endl;
            if (usrTotl > dlrTotl) {
                cout << "YOU WIN!" << endl;
                betAmnt *= 2;
            }
            else {
                cout << "DEALER WINS" << endl;
                betAmnt *= -1;
            }
        }
        cout << endl;
        
        // reward user if they won
        usrCash += (betAmnt > 0) ? betAmnt : 0;
        
        // log money won/lost this round
        allCash[roundNo] = betAmnt;
                
        // increment round counter
        roundNo++;
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
    
    // if user can't make minimum bet, game is over
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
                cout << "You can't bet more than you have, wise guy.";
                cout << endl;
            }
            else if (betAmnt < 0.0f) {
                validIn = false;
                cout << "You can't bet a negative amount. Nice try.";
                cout << endl;
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
    sumCash = sumBets = usrWins = usrStrk = 0;
    cntStrk = devCash = devBets = 0;
    
    // calculate bet/cash sums and win streak
    for (short i = 0; i < rnds; i++) {
        sumCash += cash[i];
        sumBets += bets[i];
        if (cash[i] > 0) {
            usrWins++;
            usrStrk = (++cntStrk > usrStrk) ? cntStrk : usrStrk;
        }
        else cntStrk = 0;
    }
    
    // calculate standard deviation sums 
    for (short i = 0; i < rnds; i++) {
        devCash += pow(abs(cash[i] - sumCash/rnds), 2);
        devBets += pow(abs(bets[i] - sumBets/rnds), 2);
    }
    
    // sort arrays for easy
    selSrt(cash, rnds);
    bublSrt(bets, rnds);
    
    // log session statistics in .txt file
    outData << "----------------------------------------" << endl;
    outData << "Hands played...........";
    outData << rnds << endl;
    outData << "Hands lost.............";
    outData << rnds - usrWins << endl;
    outData << "Hands won.............."; 
    outData << usrWins << endl;
    outData << "Best win streak........";
    outData << usrStrk << endl;
    outData << "Most $ won............$";
    outData << cash[rnds-1] << endl;
    outData << "Average $ won.........$"; 
    outData << ((rnds > 0) ? sumCash/rnds : 0) << endl;
    outData << "Standard deviation....$";
    outData << ((rnds > 0) ? sqrt(devCash/rnds) : 0) << endl;
    outData << "Most $ bet............$";
    outData << bets[rnds-1] << endl;
    outData << "Average $ bet.........$";
    outData << ((rnds > 0) ? sumBets/rnds : 0) << endl;
    outData << "Standard deviation....$";
    outData << ((rnds > 0) ? sqrt(devBets/rnds) : 0) << endl;
    outData << "----------------------------------------" << endl;
    
    // ask if user wants to see
    cout << "See session statistics? (y/n)" << endl << endl;
    cout << "Enter decision: ";
    cin >> usrInpt;
    cout << endl;
    
    // display if so
    if (usrInpt == 'y' || usrInpt == 'Y') {
        cout << "Hands played...........";
        cout << rnds << endl;
        cout << "Hands lost.............";
        cout << rnds - usrWins << endl;
        cout << "Hands won.............."; 
        cout << usrWins << endl;
        cout << "Best win streak........";
        cout << usrStrk << endl;
        cout << "Most $ won............$";
        cout << cash[rnds-1] << endl;
        cout << "Average $ won.........$"; 
        cout << ((rnds > 0) ? sumCash/rnds : 0) << endl;
        cout << "Standard deviation....$";
        cout << ((rnds > 0) ? sqrt(devCash/rnds) : 0) << endl;
        cout << "Most $ bet............$";
        cout << bets[rnds-1] << endl;
        cout << "Average $ bet.........$";
        cout << ((rnds > 0) ? sumBets/rnds : 0) << endl;
        cout << "Standard deviation....$";
        cout << ((rnds > 0) ? sqrt(devBets/rnds) : 0) << endl;
        cout << endl;
    }
    
    // i used binary search please give me an A :)
    if (binSrch(bets, rnds, 23*3) || binSrch(bets, rnds, 20*21))
        cout << "I know what you did." << endl;
    else
        cout << "Thank you for playing!" << endl;

    exit(0);
}


void dckInit(short vals[], char strs[][MAXCOLS], short decks) {
    for (short i = 0; i < N_DECK*decks; i++) {
        // log card id
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
        
        // pick random card to swap with
        short swap = card + rand()%(N_DECK*decks - card);
        
        // swap strings
        strcpy(tempStr, strs[card]);
        strcpy(strs[card], strs[swap]);
        strcpy(strs[swap], tempStr);
        
        // swap ids
        tempVal = vals[card];
        vals[card] = vals[swap];
        vals[swap] = tempVal;
    }
    return;
}


short calcHnd(vector<short> vals, bool &soft) {
    short val;
    short total = 0;
    for (char i = char(0); i < vals.size(); i++) {
        // parse what card face is
        val = (vals[i]-1)%13+1;
        
        // set value to 10 if face card
        if (val > 10) val = 10;
        total += val;
        
        // determine how aces are calculated
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
    
    // display dealer cards
    for (char i = char(0); i < strs.size(); i++) {
        // hide second dealer card if needed
        if (!show && i == 1) cout << "??";
        else cout << strs[i];
        cout << " ";
    }
    cout << endl << endl;
    return;
}


void shwStrs(vector<string> strs, short total) {
    cout << "Player: " << total << endl;
    
    // display user cards
    for (char i = char(0); i < strs.size(); i++)
        cout << strs[i] << " ";
    cout << endl << endl;
    return;
}


void selSrt(float arr[], short arrSize) {
    int minIndx, temp;
    for (int i = 0; i < arrSize; i++) {
        int minIndx = temp = i;
        
        for (int j = i+1; j < arrSize; j++)
            if (arr[j] < arr[minIndx]) 
                minIndx = j;
        
        if (minIndx != i) {
            temp = arr[i];
            arr[i] = arr[minIndx];
            arr[minIndx] = temp;
        }
    }
    return;
}


void bublSrt(float arr[], short arrSize) {
    int     i,
            temp;
    bool    swapped;
    
    i = 0;
    do {
        swapped = false;
        for (int j = 0; j < arrSize-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp        = arr[j];
                arr[j]      = arr[j+1];
                arr[j+1]    = temp;
                swapped     = true;
            }
        }
        i++;
    } while (swapped == true);
    return;
}


bool binSrch(float arr[], short arrSize, float toFind) {
    int first, 
        middle,
        last;
    
    first = 0;
    last = arrSize-1;
    while (first <= last) {
        middle = (first + last)/2;
        if (arr[middle] == toFind)
            return true;
        else if (arr[middle] > toFind)
            last = middle-1;
        else if (arr[middle] < toFind)
            first = middle+1;
    }
    return false;
}
