#include <iostream>
#include <time.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Card{
    int value;//1 = 1. . . 10 = jack+, Ace = 11/1
    string faceValue; //J, Q, K, A, 2...
    string suit; // 0 = hearts, 1 = diamonds, 2 = spades, 3 = clubs
};

void playGame();
Card newCard();
void makeDeck();
bool isBust(int hand);
int getCard();
bool dealerAI(int score);

Card userHand[23];//technically, you can have 22 aces.
Card houseHand[23];
Card deck[52];

string SUITS[4] = {"HEARTS", "DIAMONDS", "SPADES", "CLUBS"};
string FACE_VALUE[14] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
int VALUES[14] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

int main(){

    string userInput;
    //makeDeck();
    cout << "Welcome to blackjack.Would you like to play? (Y || N)" << endl << endl;
    cin >> userInput;

    //game loop
    while(userInput == "Y" || userInput == "y"){
        playGame();
        cout << "Again?" << endl;
        cin >> userInput;
    }
    cout << "Thanks" << endl;
    return 0;
}

//this causes an error for some reason.
void makeDeck(){
    int counter = 0;
    for(int i = 0; i < 52; i++){
        deck[i].faceValue = FACE_VALUE[counter];
        deck[i].value = VALUES[counter];
        if(counter == 13)
            counter = 0;
        counter++;
    }
    for(int i = 0; i < 52; i++){
        deck[i].suit = SUITS[counter];
        if(counter == 3)
            counter = 0;
        counter++;
    }
    //random_shuffle(&deck[0], &deck[52]);
}

Card newCard(int SIZE){
    Card c;

    //get card from top of deck.

    return c;
}
//game
void playGame(){
    srand(time(NULL));

    int userHand = 0, houseHand = 0;
    string hitO = "Y";

    cout << "Your hand: " << endl;
    cout << deck[0].value << " of " << deck[0].suit << endl;
    //TODO: add card type
    userHand += getCard();
    userHand += getCard();
    cout << "Value of hand : " << userHand << endl;

    houseHand += getCard();
    houseHand += getCard();

    while(!isBust(userHand) && (hitO == "Y" || hitO == "y")){
        cout << "Hit? (Y or N) " << endl;
        cin >> hitO;

        if(hitO == "N" || hitO == "n")
            break;

        userHand += getCard();

        if(isBust(userHand)){
            cout << "Bust!" << endl;
            goto endRound;
        }
        else
            cout << "Value of hand: " << userHand << endl;
    }
    //dealerAI
    while(dealerAI(houseHand)){
        houseHand += getCard();
        cout << "Dealer hits. Dealer hand: " << houseHand << endl;
        if(isBust(houseHand))
            goto endRound;
    }


endRound:
    cout << "Dealers hand: " << endl;
    cout << houseHand << endl;
    cout << "Your hand: " << endl;
    cout << userHand << endl;

    if(houseHand == 21)
        cout << "You lose." << endl;
    else if(isBust(userHand))
        cout << "You lose." << endl;
    else if(isBust(houseHand))
        cout << "You win!" << endl;
    else if(houseHand > userHand)
        cout << "You lose." << endl;
    else if(houseHand == userHand)
        cout << "Tie!" << endl;
    else
        cout << "You win!" << endl;
}

bool isBust(int hand){
    return hand > 21;
}
//random card
int getCard(){
    return rand() % 11 + 1;
}
bool dealerAI(int score){
    if(score >= 17)
        return false;
    else if(score < 17)
        return true;
}
