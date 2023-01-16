#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int getRNG(int highLimit, int lowLimit){
    return rand() % highLimit + lowLimit;
} 
int getPrize(int highlowAnswer){
    int prize = 0; 
    if (highlowAnswer == 'h' || highlowAnswer == 'l'){
        prize = rand() % 199 + 500;
    } else if (highlowAnswer == 'e'){
        prize = rand() % 999 + 4000;
    }
    return prize;
}
int main(){
    srand(time(NULL));
    string discordInput;
    char highLowAnswer;
    int clueNumber, hiddenNumber, attempt = 1, prize = 0, prizeTotal = 0;
    cout << "Welcome to DANK MEMER!!!" << endl << endl;
    cout << "Type '/hl' if you want to play: "; cin >> discordInput;
    while (discordInput == "/hl"){
        clueNumber = getRNG(100, 1);
        hiddenNumber = getRNG(100, 1); 
        cout << "\nAttempt: " << attempt << endl;
        cout << "\nThe clue number is: " << clueNumber << endl;
        // cout << "Hidden number is: " << hiddenNumber << endl; // must be hidden upon real game
        cout << "Guess the hidden number if it is higher, lower, or exact to the clue number!" << endl;
        cout << " h - Higher \n l - lower \n e - exact(jackpot)" << endl;
        cout << "Answer: "; cin >> highLowAnswer;
        if(clueNumber > hiddenNumber){
            if (highLowAnswer == 'l'){
                prize = getPrize(highLowAnswer);
                prizeTotal += prize;
                cout << "\nCorrect! The number is " << hiddenNumber << endl;
                cout << "You got " << prize << " Pesos!" << endl;
                cout << "\nYou currently have " << prizeTotal << " Pesos in your wallet. " << endl;
            } else {
                cout << "Wrong! The number is " << hiddenNumber << endl;
                cout << "\nYou currently have " << prizeTotal << " Pesos in your wallet. " << endl;
            }
        } else if (clueNumber < hiddenNumber){
            if (highLowAnswer == 'h'){
                prize = getPrize(highLowAnswer);
                prizeTotal += prize;
                cout << "\nCorrect! The number is " << hiddenNumber << endl;
                cout << "You got " << prize << " Pesos!" << endl;
                cout << "\nYou currently have " << prizeTotal << " Pesos in your wallet. " << endl;
            } else {
                cout << "Wrong! The number is " << hiddenNumber << endl;
                cout << "\nYou currently have " << prizeTotal << " Pesos in your wallet. " << endl;
            }
        } else if (clueNumber == hiddenNumber){
            if (highLowAnswer == 'e'){
                prize = getPrize(highLowAnswer);
                prizeTotal += prize;
                cout << "\nJACKPOOOOT! The number is " << hiddenNumber << endl;
                cout << "You got " << prize << " Pesos!" << endl;
                cout << "\nYou currently have " << prizeTotal << " Pesos in your wallet. " << endl;
            } else {
                cout << "Wrong! The number is " << hiddenNumber << endl;
                cout << "\nYou currently have " << prizeTotal << " Pesos in your wallet. " << endl;
            }
        }
        ++attempt;
        cout << "\nEnter '/hl' if you want to play again. Enter '/cashout' if you want to cash out your prize.\nIf you entered anything aside from these two, you won't get any prize. " << endl;
        cout << "Prompt: "; cin >> discordInput;
        if (discordInput == "/cashout"){
            cout << "\nGreat! You are now cashing out... " << prizeTotal << " Pesos! Congratulations! " << endl;
            cout << "Thank you for playing!" << endl;
        } else if (discordInput != "/hl" && discordInput != "/cashout") {
        cout << "\nYou did not follow the rules. No prize for you." << endl;
        }
    }
    
}
