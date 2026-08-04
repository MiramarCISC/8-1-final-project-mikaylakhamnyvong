#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <string>
#include <iostream>

using namespace std;

// Stores one record in the budget tracker
struct Transaction {
    int id;
    string category;
    string description;
    double amount;
    bool isIncome;
};

// Creates a linked list
struct TransactionNode {
    Transaction data;
    TransactionNode* next;
};

// Input Validation
bool isValidAmount(double amount);
bool isValidChoice(int choice);

// Linked List Functions
void addTransaction(TransactionNode*& head, Transaction transaction);
void displayTransactions(TransactionNode* head);
TransactionNode* searchTransaction(TransactionNode* head, int id);
void clearTransaction(TransactionNode*& head);

// Calculations
double calculateIncome(TransactionNode* head);
double calculateExpenses(TransactionNode* head);
double calculateBalance(TransactionNode* head);

// Sorting
void sortTransactionsByAmount(TransactionNode* head);

// File I/O
int loadTransactions(string filename, TransactionNode*& head);

// Menu
void printMenu();

#endif
