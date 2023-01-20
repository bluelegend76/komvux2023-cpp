#include <iostream>
#include <ctype.h>
using namespace std;

int main() {
  float accountBalance = 0;
  /* float deposit = 0; */
  float withdrawal = 0;
  float yearlyDeposit = 0;
  int yearlyInterestRate = 0;
  int numOfYears = 0;

  cout << "Welcome to SimpleBank" << endl;
  cout << "current balance: " << accountBalance << endl;

  // Print menu
  cout << "-- menu --\n";
  cout << "[D]eposit\n";
  cout << "[W]ithdraw\n";
  cout << "[A]ccount Balance\n";
  cout << "[C]alculate Interest Payment\n";
  cout << "[Q]uit\n";

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
          cout << "(No negative numbers. Returning to menu)\n";
        }
        break;

      case 'w':
        cout << "Sum to withdraw: ";
        break;

      case 'a':
        cout << "Current balance: " << accountBalance << endl;
        break;

      case 'c':
        cout << "Calculate Interest-payment\n";
        break;

      case 'q':
        return 0;

      default:
        cout << "Unsupported input! Try again.\n";
        break;
    }
  }

  // cin.get()
  return 0;
}
