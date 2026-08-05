#include "project.hpp"
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool nearlyEqual(double actual, double expected, double tolerance = 0.0001) {
    return fabs(actual - expected) <= tolerance;
}

void createTestBudgetFile(string filename) {
    ofstream out(filename);

    out << "1 Food Lunch 15.50 0" << endl;
    out << "2 Salary Paycheck 1800.00 1" << endl;
    out << "3 Gas Fuel 45.25 0" << endl;

    out.close();
}

// Week 1: Program Basics
void testWeek1ProgramBasics() {
    TransactionNode* head = nullptr;

    addTransaction(head, {1, "Salary", "Paycheck", 1000.00, true});
    addTransaction(head, {2, "Food", "Lunch", 50.00, false});

    assert(nearlyEqual(calculateIncome(head), 1000.00));
    assert(nearlyEqual(calculateExpenses(head), 50.00));
    assert(nearlyEqual(calculateBalance(head), 950.00));

    clearTransaction(head);
}

// Week 2: Decisions and Loops
void testWeek2DecisionsAndLoops() {
    assert(isValidAmount(0));
    assert(isValidAmount(25.50));
    assert(!isValidAmount(-10));

    assert(isValidChoice(1));
    assert(isValidChoice(9));
    assert(!isValidChoice(0));
    assert(!isValidChoice(10));
}

// Week 3: Functions and Program Design
void testWeek3FunctionsAndProgramDesign() {
    TransactionNode* head = nullptr;
    Transaction transaction = {1, "Food", "Lunch", 12.50, false};
    addTransaction(head, transaction);
    TransactionNode* found = searchTransaction(head, 1);

    assert(found != nullptr);
    assert(found->data.category == "Food");

    clearTransaction(head);
}

// Week 4: Arrays, Searching, and Sorting
void testWeek4ArraysSearchingSorting() {
    TransactionNode* head = nullptr;

    addTransaction(head, {1, "Food", "Lunch", 25.00, false});
    addTransaction(head, {2, "Gas", "Fuel", 10.00, false});
    addTransaction(head, {3, "Salary", "Paycheck", 25.00, false});

    sortTransactionsByAmount(head);

    assert(nearlyEqual(head->data.amount, 10.00));
    assert(nearlyEqual(head->next->data.amount, 25.00));
    assert(nearlyEqual(head->next->next->data.amount, 50.00));

    clearTransaction(head);
}

// Week 5: Strings and Structures
void testWeek5StringsAndStructures() {
    Transaction transaction = {1, "Food", "Lunch", 12.50, false};

    assert(transaction.id == 1);
    assert(transaction.category == "Food");
    assert(transaction.description == "Lunch");
    assert(nearlyEqual(transaction.amount, 12.50));
    assert(transaction.isIncome == false);
}

// Week 6: Simple Linked Task List
void testWeek6SimpleLinkedList() {
    TransactionNode* head = nullptr;

    addTransaction(head, {1, "Food", "Lunch", 20.00, false});
    addTransaction(head, {2, "Salary", "Paycheck", 1000.00, true});
    addTransaction(head, {3, "Gas", "Fuel", 35.00, false});

    assert(searchTransaction(head, 2) != nullptr);
    assert(searchTransaction(head, 99) == nullptr);

    clearTransaction(head);

    assert(head == nullptr);
}

// Week 7: File-Based Inventory Report
void testWeek7FileIO() {
    string filename = "tests/resources/budget.txt";
    createTestBudgetFile(filename);

    TransactionNode* head = nullptr;
    
    int count = loadTransactions(filename, head);
    assert(count == 3);

    TransactionNode* found = searchTransaction(head, 2);

    assert(found != nullptr);
    assert(found->data.category == "Salary");
    assert(nearlyEqual(found->data.amount, 1800.00));

    clearTransaction(head);
}

int main() {
    testWeek1ProgramBasics();
    testWeek2DecisionsAndLoops();
    testWeek3FunctionsAndProgramDesign();
    testWeek4ArraysSearchingSorting();
    testWeek5StringsAndStructures();
    testWeek6SimpleLinkedList();
    testWeek7FileIO();

    cout << "All Budget Tracker tests passed!" << endl;
    return 0;
}
