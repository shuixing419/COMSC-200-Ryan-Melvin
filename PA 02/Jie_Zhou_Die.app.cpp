#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Jie_Zhou_Die.h"

using namespace std;

void playGame();
bool userWantsToContinue();

int main() 
{
    srand(time(0));  // Seed random number generator
    playGame();
    return 0;
}

// Main game logic for 21 game
void playGame() {
    Die die1(6);
    Die die2(6);

    int userTotal = 0;
    int computerTotal = 0;
    bool diceRolled = false;

    cout << "Let's play a game of 21!" << endl << endl;
    cout << "--------------------------------" << endl;

    // Main game loop - continue until user stops or exceeds 21 points
    while (userWantsToContinue() && userTotal <= 21) {
        diceRolled = true;

        // Computer's turn
        die1.roll();
        die2.roll();
        computerTotal += die1.getValue() + die2.getValue();

        // User's turn
        die1.roll();
        die2.roll();
        int rollTotal = die1.getValue() + die2.getValue();
        userTotal += rollTotal;

        cout << "You have " << userTotal << " points." << endl << endl;

        // Check if user busted
        if (userTotal > 21) {
            cout << "--------------------------------" << endl;
            cout << "The computer had " << computerTotal << " points." << endl;
            cout << "You had " << userTotal << " points." << endl << endl;
            cout << "Better luck next time." << endl << endl;
            cout << "--------------------------------" << endl << endl;
            cout << "Game Over" << endl << endl;
            cout << "Press any key to continue . . ." << endl;
            return;
        }
    }

    // Display final results if any rolls occurred
    if (diceRolled) {
        cout << "--------------------------------" << endl;
        cout << "The computer had " << computerTotal << " points." << endl;
        cout << "You had " << userTotal << " points." << endl;

        // Determine winner
        if (userTotal <= 21 && userTotal <= computerTotal) {
            cout << endl << "Better luck next time." << endl;
        }
        if (userTotal > computerTotal && userTotal <= 21) {
            cout << endl << "Congratulations! You won!" << endl << endl;
        }
        cout << "--------------------------------" << endl;
    }
    else {
        cout << "--------------------------------" << endl << endl;
    }

    cout << "Game Over" << endl << endl;
    cout << "Press any key to continue . . ." << endl;
}

// Prompt user to continue playing
bool userWantsToContinue() {
    char choice;
    cout << "Would you like to roll the dice?" << endl;
    cout << "Enter Y for yes or N for no: ";
    cin >> choice;
    cout << endl;
    return (choice == 'Y' || choice == 'y');
}