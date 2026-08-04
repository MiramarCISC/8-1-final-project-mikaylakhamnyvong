[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=24283506)
# CISC 192 Final Project: Budget Tracker

## Overview

This repository implements a fully working budget tracker that allows you to control your transactions by reading from a file.

You may:
- Load transactions
- Add Transaction
- View Transactions
- Search Transactions
- Sort Transactions by Amount
- Show Total Income
- Show Total Expenses
- Show Current Balance

## How to Compile and Run

```bash
make
./main
```

## How to Run Tests

```bash
make test
```

## How to Clean Build Files

```bash
make clean
```

## Integrate and Test Course Topics

1. Week 1 Program Basics
   - Code location: calculateIncome(), calculateExpenses(), calculateBalance() in src/project.cpp
   - Test location:

2. Week 2 Decisions and Loops
   - Code location: menu loop and switch statement in src/main.cpp, isValidChoice() in src/project.cpp
   - Test location:

3. Week 3 Functions and Program Design
   - Code location: function declarations in include/project.hpp, function implementations in src/project.cpp
   - Test location:

4. Week 4 Arrays, Searching, and Sorting
   - Code location: sortTransactionByAmount() and searchTransaction() in src/project.cpp
   - Test location:

5. Week 5 Strings and Structures
   - Code location: Transaction and TransactionNode structures in include/project.hpp
   - Test location:

6. Week 6 Pointers, Dynamic Memory, and Linked Lists
   - Code location: addTransaction(), clearTransaction(), and linked list operations in src/project.cpp
   - Test location:

7. Week 7 File I/O and Integration
   - Code location: loadTransactions() in src/project.cpp and data/budget.txt
   - Test location:
```

## Known Limitations
- You can set multiple transactions to the same ID number, making it difficult to search for.

## Final Submission Checklist

- [x] My project compiles with `make`.
- [x] My project runs with `./main`.
- [ ] My tests run with `make test`.
- [x] I deleted or replaced the sample project code.
- [x] My project uses class names that are nouns from my own project.
- [x] My project integrates all 7 course topics in reachable code.
- [ ] My project includes at least one unit test per course topic.
- [x] My README explains where each topic appears.
- [ ] My README explains which test verifies each topic.
- [ ] My code is committed and pushed to GitHub Classroom.
