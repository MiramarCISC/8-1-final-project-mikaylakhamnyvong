#include "project.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

// ----- Input Validation -----
bool isValidAmount(double amount) {
    // Checks if the amount is a valid amount.
    return amount >= 0;
}

bool isValidChoice(int choice) {
    // Checks if the choice is a valid choice.
    return choice >= 1 && choice <= 9;
}

// ----- Linked List -----
void addTransaction(TransactionNode*& head, Transaction transaction) {
    // Creates a new transaction node and adds it to the end of the linked list.
    TransactionNode* newNode = new TransactionNode;

    newNode->data = transaction;
    newNode->next = nullptr;

    if(head == nullptr) {
        head = newNode;
    }
    else {
        TransactionNode* current = head;

        while(current-> next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }
}

void displayTransactions(TransactionNode* head) {
    // Displays all transactions in the linked list.
    if(head == nullptr) {
        cout << "\nNo Transactions found.\n";
        return;
    }

    TransactionNode* current = head;
    while(current != nullptr) {
        cout << "\n--------------------------\n";
        cout << "Transaction ID: " << current->data.id << endl;
        cout << "Category: " << current->data.category << endl;
        cout << "Description: " << current->data.description << endl;
        cout << "Amount: $" << fixed << setprecision(2)
             << current->data.amount << endl;
        cout << "Type: "
             << (current->data.isIncome ? "Income" : "Expense")
             << endl;
        
             current = current->next;
    }

    cout << "--------------------------\n";
}

TransactionNode* searchTransaction(TransactionNode* head, int id) {
    // Searches the linked list for a transaction with the given ID.
    TransactionNode* current = head;

    while(current != nullptr) {
        if(current->data.id == id) {
            return current;
        }

        current = current->next;
    }

    return nullptr;
}

void clearTransaction(TransactionNode*& head) {
    // Deletes every node in the linked lists and frees allocated memory.
    while(head != nullptr) {
        TransactionNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// ----- Calculations -----
double calculateIncome(TransactionNode* head) {
    // Calculates total income transactions.
    double total = 0;
    
    while(head != nullptr) {
        if(head->data.isIncome) {
            total += head->data.amount;
        }

        head = head->next;
    }

    return total;
}

double calculateExpenses(TransactionNode* head) {
    // Calculates total expense transactions.
    double total = 0;

    while(head != nullptr) {
        if(!head->data.isIncome) {
            total += head->data.amount;
        }

        head = head->next;
    }

    return total;
}

double calculateBalance(TransactionNode* head) {
    // Calculates current balance.
    return calculateIncome(head) - calculateExpenses(head);
}

// ----- Sorting -----
void sortTransactionsByAmount(TransactionNode* head) {
    if(head == nullptr || head->next == nullptr) {
        return;
    }

    bool swapped;

    do {
        swapped = false;
        TransactionNode* current = head;

        while(current->next != nullptr) {
            if(current->data.amount > current->next->data.amount) {
                Transaction temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                swapped = true;
            }

            current = current->next;
        }
    }
    while (swapped);
}

// ----- File I/O -----
int loadTransactions(string filename, TransactionNode*& head) {
    ifstream input(filename);

    if(!input.is_open()) {
        return 0;
    }

    int count = 0;
    Transaction transaction;

    while(input >> transaction.id
                >> transaction.category
                >> transaction.description
                >> transaction.amount
                >> transaction.isIncome) {
        addTransaction(head, transaction);
        count++;
    }

    input.close();
    return count;
}

// ----- Menu -----
void printMenu() {
    // Displays menu options for the budget tracker.
    cout << "\n----- Budget Tracker -----\n";
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
