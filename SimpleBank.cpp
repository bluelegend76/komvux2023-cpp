#include <iostream>
#include <ctype.h>
#include <limits>
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
//

// TODO: Check what '\n' does (!!)
void clearCin() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

int main() {
  float accountBalance = 0;

  cout << "Welcome to SimpleBank" << endl;
  cout << "current balance: " << accountBalance << endl;
  PrintMenu();

  while (true) {
    cout << "Your choice: ";
    char choice = 0;
    cin >> choice;
    if (cin.peek() != '\n') {
      clearCin();
      cout << "   Input error. Returning to menu.\n";
      continue;
    }

    float deposit = 0;
    float withdrawal = 0;
    float yearlyDeposit = 0;
    float yearlyInterestRate = 0;
    int   numOfYears = 0;
    float interestPaymentSum = 0;

    switch (tolower(choice))
    {
      case 'd':
        cout << "Amount to deposit: ";
        cin >> deposit;

        if (!cin) {
          // TODO: Include in cases below
          //  (+possibly moving 'general error message'
          //   to incide the clearCin-function)
          clearCin();
          cout << "   Input error. Returning to menu.\n";
          break;
        }
        if (deposit > 0) {
          accountBalance += deposit;
        }
        else {
          cout << "   No negative numbers. Returning to menu.\n";
        }
        break;

      case 'w':
        cout << "Sum to withdraw: ";
        cin >> withdrawal;

        if (accountBalance - withdrawal >= 0) {
          accountBalance -= withdrawal;
        }
        else if (withdrawal <= 0) {
          cout << "   No negative numbers. Returning to menu.\n";
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

        cout << "Sum to save (per year): ";
        cin >> yearlyDeposit;

        cout << "Interest rate (in percents): ";
        cin >> yearlyInterestRate;

        cout << "Number of years (to save during): ";
        cin >> numOfYears;

        // TODO Bit unclear in the spec:
        //  = Should result of the calculation
        //  - be added to balance, or
        //  - just echoed/reported? [X]
        for (int i=1; i <= numOfYears; i++) {
          /* accountBalance = (accountBalance + yearlyDeposit) * */
                             /* (1 + (yearlyInterestRate / 100)); */
          interestPaymentSum =
            (accountBalance + yearlyDeposit) * (1 + (yearlyInterestRate / 100));
          // -- temp-vars to check values during run of loop
          // cout << i << endl;
          // cout << accountBalance << endl;
          // ----
        }
        //cout << "Account balance is now: " << accountBalance << endl;
        cout << "----" << endl;
        cout << "Report:\n";
        cout << "Saving for " << numOfYears << " year(s),\n";
        cout << "with a yearly deposit of " << yearlyDeposit << ",\n";
        cout << "and at " << yearlyInterestRate << " percent interest,\n";
        cout << "would (including current balance) yield the sum " << interestPaymentSum << ".\n";
        cout << "----" << endl;
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

