#include <iostream>
#include <ctype.h>
using namespace std;


// Printing the Main Menu
void PrintMenu() {
  cout << "-- menu --\n";
  cout << "[D]eposit\n";
  cout << "[W]ithdraw\n";
  cout << "[A]ccount Balance\n";
  cout << "[C]alculate Interest Payment\n";
  cout << " [R]eprint Menu\n";
  cout << "[Q]uit\n";
  cout << "----------\n";
}

// float PercentToFraction(intPercent) {
//   return intPercent / 100;
// }


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
          cout << "   No negative numbers. Returning to menu.\n";
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
          cout << "   Withdrawal larger than balance. Returning to menu.\n";
        }
        break;

      case 'a':
        cout << "Current balance: " << accountBalance << endl;
        break;

      case 'c':
        cout << "-- Calculate Interest-payment --\n";
        float yearlyDeposit;
        float yearlyInterestRate;
        int numOfYears;
        // float interestPaymentSum;

        cout << "Sum to save (per year): ";
        cin >> yearlyDeposit;

        cout << "Interest rate (in whole percents): ";
        cin >> yearlyInterestRate;

        cout << "Number of years (to save during): ";
        cin >> numOfYears;

        // TODO Bit unclear in the spec:
        //  = should result of the calculation be added to balance,
        //    or just echoed/reported?
        for (int i=1; i <= numOfYears; i++) {
          accountBalance = (accountBalance + yearlyDeposit) *
                             (1 + (yearlyInterestRate / 100));
          // -- temp-vars to check values during run of loop
          cout << i << endl;
          cout << accountBalance << endl;
          // --
        }
        cout << "Account balance is now: " << accountBalance << endl;
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

// == First "0.1" testrun
// (=mainly checking the 'Calculate Interest-payment' functionality)
//
// Welcome to SimpleBank
// current balance: 0
// -- menu --
// [D]eposit
// [W]ithdraw
// [A]ccount Balance
// [C]alculate Interest Payment
//  [R]eprint Menu
// [Q]uit
// ----------
// Your choice: d
// Amount to deposit: 100
// Your choice: c
//  TODO: CHECK FIRST TESTRUN BELOW
// -- Calculate Interest-payment --
// Sum to save (per year): 10
// Interest rate (in whole percents): 2
// Number of years (to save during): 3
// 1
// 112.2
// 2
// 124.644
// 3
// 137.337
// Account balance is now: 137.337
// Your choice: 

