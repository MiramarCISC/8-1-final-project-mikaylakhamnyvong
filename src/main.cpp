#include "project.hpp"
#include <iostream>

using namespace std;

int main() {

    TransactionNode* head = nullptr;
    int choice;

    do {
        printMenu();
        cin >> choice;

        if(!isValidChoice(choice)) {
            cout << "\nInvalid menu choice.\n";
            continue;
        }

        switch(choice) {
            case 1: {
                int loaded = loadTransactions("data/budget.txt", head);

                cout << "Loaded "
                     << loaded
                     << "transactions.\n";
                break;
            }

            case 2: {
                Transaction transaction;

                cout << "Transaction ID: ";
                cin >> transaction.id;

                cout << "Category: ";
                cin >> transaction.category;

                cout << "Description: ";
                cin >> transaction.description;

                cout << "Amount: ";
                cin >> transaction.amount;

                if(!isValidAmount(transaction.amount)) {
                    cout << "\nAmount must be positive.\n";
                    break;
                }

                int type;

                cout << "(1) Income or (2) Expense: ";
                cin >> type;

                transaction.isIncome = (type == 1);
                addTransaction(head, transaction);

                cout << "\nTransaction added successfully.\n";

                break;
            }

            case 3: {
                displayTransactions(head);
                break;
            }

            case 4: {
                int id;

                cout << "\nEnter transaction ID: ";
                cin >> id;

                TransactionNode* found = searchTransaction(head, id);

                if(found == nullptr) {
                    cout << "Transaction not found.\n";
                }
                else {
                    cout << "\nTransaction Found\n";
                    cout << "ID: "
                         << found->data.id
                         << endl;

                    cout << "Category: "
                         << found->data.category
                         << endl;

                    cout << "Description: "
                         << found->data.description
                         << endl;

                    cout << "Amount: $"
                         << found->data.amount
                         << endl;

                    cout << "Type: "
                         << (found->data.isIncome ? "Income" : "Expense")
                         << endl;
                }

                break;
            }

            case 5: {
                sortTransactionsByAmount(head);
                cout << "\nTransactions sorted by amount.\n";
                break;
            }

            case 6: {
                cout << "\nTotal Income: $"
                     << calculateIncome(head)
                     << endl;
                break;
            }

            case 7: {
                cout << "\nTotal Expenses: $"
                     << calculateExpenses(head)
                     << endl;
                break;
            }

            case 8: {
                cout << "\nCurrent Balance: $"
                     << calculateBalance(head)
                     << endl;
                break;
            }
        }
    } 
    while(choice != 9);

    clearTransaction(head);

    return 0;
}
