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
    
}

// Week 2: Decisions and Loops
void testWeek2DecisionsAndLoops() {
    
}

// Week 3: Functions and Program Design
void testWeek3FunctionsAndProgramDesign() {
    
}

// Week 4: Arrays, Searching, and Sorting
void testWeek4ArraysSearchingSorting() {
    
}

// Week 5: Strings and Structures
void testWeek5StringsAndStructures() {
    
}

// Week 6: Simple Linked Task List
void testWeek6SimpleLinkedList() {
    
}

// Week 7: File-Based Inventory Report
void testWeek7FileIO() {
    
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
