/*
Name: Ayman Almansor

cheesy-program.cpp:
[!] The program does the following:
    1. Prompts the user to enter the total amount of cheese produced.
    2. Outputs the number of containers needed (Rounded to nearest integer.)
    3. Outputs the cost of producing the cheese.
    4. Outputs the profit for producing cheese.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>  

using namespace std;

// Constants
const double CHEESE_PER_CONTAINER = 2.76;
const double COST_PER_CONTAINER = 4.12;
const double PROFIT_PER_CONTAINER = 1.45;

// Header Generator Constants - Change values here to customize title header
const char SYMBOLE = '+';
const string HEADER_TITLE = " Calculate the profit from cheese production ";
const int HEADER_LENGTH = 75;

void headerGenerator()
{
    int titleLength = HEADER_TITLE.length();
    int headerHalfLength = (HEADER_LENGTH - titleLength) / 2;

    cout << setfill(SYMBOLE);
    cout << setw(HEADER_LENGTH) << SYMBOLE << endl;
    // Cast needed to avoid possible arithmetic overflow error
    cout << setw(static_cast<streamsize>(headerHalfLength) + titleLength)
         << HEADER_TITLE << setw(headerHalfLength) << SYMBOLE << endl;
    cout << setw(HEADER_LENGTH) << SYMBOLE << endl;

    // Reset fill
    cout << setfill(' ');
}

int main()
{
    headerGenerator();

    // Input
    int userTotalCheese = 0;
    cout << "\n[>] Please enter the total number of kilograms of cheese produced: ";
    cin >> userTotalCheese;

    // Calculations
    int containersNeeded = static_cast<int>(ceil(userTotalCheese / CHEESE_PER_CONTAINER));
    double totalCost = containersNeeded * COST_PER_CONTAINER;
    double totalProfit = containersNeeded * PROFIT_PER_CONTAINER;

    // Output messages
    string numMessage = "[+] The number of containers to hold the cheese is: ";
    string costMessage = "[+] The cost of producing " + to_string(containersNeeded) +" container(s) of cheese is: $";
    string profitMessage = "[+] The profit from producing " + to_string(containersNeeded) + " container(s) of cheese is: $";

    // Output
    cout << fixed << showpoint << setprecision(2) << endl;

    cout << numMessage << setw(HEADER_LENGTH - numMessage.length()) << containersNeeded << endl;
    cout << costMessage << setw(HEADER_LENGTH - costMessage.length()) << totalCost << endl;
    cout << profitMessage << setw(HEADER_LENGTH - profitMessage.length()) << totalProfit << endl;

    return 0;
}