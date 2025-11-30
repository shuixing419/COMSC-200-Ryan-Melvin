#include <iostream>
#include <iomanip>
#include "Jie_Zhou_Coin.h"

using namespace std;

void playRound(Coin& quarter, Coin& dime, Coin& nickel, double& playerBalance, double& computerBalance, int round);
void displayResults(double playerBalance, double computerBalance, int round);

int main() 
{
    // Create coin objects
    Coin quarter, dime, nickel;

    // Initialize balances
    double playerBalance = 0.0;
    double computerBalance = 0.0;

    // Set output precision
    cout << fixed << setprecision(2);

    // Display starting balances
    cout << "Your starting balance: $" << playerBalance << endl;
    cout << "The computer's starting balance: $" << computerBalance << endl;

    int round = 1;
    // Main game loop - continue until someone reaches $1.00
    while (playerBalance < 1.00 && computerBalance < 1.00) 
    {
        playRound(quarter, dime, nickel, playerBalance, computerBalance, round);
        displayResults(playerBalance, computerBalance, round);
        round++;
    }

    // Display final results
    cout << "\nYour ending balance: $" << playerBalance << endl;
    cout << "The computer's ending balance: $" << computerBalance << "\n\n";

    // Determine winner
    if (playerBalance >= 1.00 && computerBalance >= 1.00) 
    {
        if (playerBalance == computerBalance) 
        {
            cout << "Tie! Nobody wins." << endl;
        }
        else if (playerBalance < computerBalance) 
        {
            cout << "Congratulations! You won." << endl;
        }
        else 
        {
            cout << "Sorry! The computer won." << endl;
        }
    }
    else if (playerBalance >= 1.00) 
    {
        cout << "Congratulations! You won." << endl;
    }
    else 
    {
        cout << "Sorry! The computer won." << endl;
    }

    cout << "\nPress any key to continue . . ." << endl;

    return 0;
}

// Play one round: toss coins and update balances
void playRound(Coin& quarter, Coin& dime, Coin& nickel, double& playerBalance, double& computerBalance, int round) 
{
    // Player's turn - toss coins
    quarter.toss();
    dime.toss();
    nickel.toss();

    // Add values for heads
    if (quarter.getSideUp() == "heads") playerBalance += 0.25;
    if (dime.getSideUp() == "heads") playerBalance += 0.10;
    if (nickel.getSideUp() == "heads") playerBalance += 0.05;

    // Computer's turn - toss coins
    quarter.toss();
    dime.toss();
    nickel.toss();

    // Add values for heads
    if (quarter.getSideUp() == "heads") computerBalance += 0.25;
    if (dime.getSideUp() == "heads") computerBalance += 0.10;
    if (nickel.getSideUp() == "heads") computerBalance += 0.05;
}

// Display current balances after each round
void displayResults(double playerBalance, double computerBalance, int round) 
{
    cout << "\nYour balance after round " << round << ": $" << playerBalance << endl;
    cout << "The computer's balance after round " << round << ": $" << computerBalance << endl;
}