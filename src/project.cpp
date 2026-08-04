#include "project.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

// ----- Menu -----
void printMenu() {
    cout << "----- Budget Tracker -----\n";
    cout << "1. Load Transactions\n";
    cout << "2. Add Transaction\n";
    cout << "3. View Transactions\n";
    cout << "4. Search Transaction\n";
    cout << "5. Sort Transactions by Amount\n";
    cout << "6. Show Total Income\n";
    cout << "7. Show Total Expenses\n";
    cout << "8. Show Current Balance\n";
    cout << "9. Exit\n";
    cout << "--------------------------\n";
    cout << "Enter your choice: ";
}


