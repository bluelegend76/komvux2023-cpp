#include <iostream>
#include <ctype.h>
using namespace std;

void PrintMenu() {
  // Print menu
  cout << "-- menu --\n";
  cout << "[D]eposit\n";
  cout << "[W]ithdraw\n";
  cout << "[A]ccount Balance\n";
  cout << "[C]alculate Interest Payment\n";
  cout << " [R]eprint Menu\n";
  cout << "[Q]uit\n";
  cout << "----------\n";
}

int main() {
  float accountBalance = 0;

  cout << "Welcome to SimpleBank" << endl;
  cout << "current balance: " << accountBalance << endl;
  PrintMenu();

  while (true) {
    cout << "Your choice: ";
    char choice;
    cin >> choice;

    switch (tolower(choice))
    {
      case 'd':
        cout << "Amount to deposit: ";
        float deposit;
        cin >> deposit;

        if (deposit > 0) {
          accountBalance += deposit;
        }
        else {
          cout << "   No negative numbers. Returning to menu\n";
        }
        break;

      case 'w':
        cout << "Sum to withdraw: ";
        float withdrawal;
        cin >> withdrawal;

        if (accountBalance - withdrawal > 0) {
          accountBalance -= withdrawal;
        }
        else {
          cout << "   Withdrawal larger than balance. Returning to menu\n";
        }
        break;

      case 'a':
        cout << "Current balance: " << accountBalance << endl;
        break;

      case 'c':
        cout << "Calculate Interest-payment\n";
        float yearlyDeposit;
        int yearlyInterestRate;
        int numOfYears;
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        break;

      case 'r':
        PrintMenu();
        break;

      case 'q':
        return 0;

      default:
        cout << "   Unsupported input. Returning to menu.\n";
        break;
    }
  }

  // cin.get()
  return 0;
}

