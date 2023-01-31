#include <iostream>
#include <ctype.h>
#include <limits>
using namespace std;

// Clear cin (up until the next linebreak)
void ClearCin() {
  // resetting cin error flag
  cin.clear();
  // skip everything until next newline
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

// Printing the Main Menu
void PrintMenu() {
  // Note: May be a better approach to use 'endl' consistently
  cout << "-- menu --\n";
  cout << "[D]eposit\n";
  cout << "[W]ithdraw\n";
  cout << "[A]ccount Balance\n";
  cout << "[C]alculate Interest Payment\n";
  cout << "[R]eprint Menu\n";
  cout << endl;
  cout << "[Q]uit\n";
  cout << "----------\n";
}


int main() {
  float accountBalance = 0;

  cout << "Welcome to SimpleBank" << endl;
  cout << "Current balance: " << accountBalance << endl;
  PrintMenu();

  while (true) {
    cout << "Your choice: ";
    char choice = 0;
    cin >> choice;
    // Checking that input to menu is only one character
    if (cin.peek() != '\n') {
      ClearCin();
      cout << "   Input error. Returning to menu.\n";
      continue;
    }

    // Declaring variables for use in the switch
    float deposit = 0;
    float withdrawal = 0;
    float yearlyDeposit = 0;
    float yearlyInterestRate = 0;
    int   numOfYears = 0;
    float interestPaymentSum = 0;


      // Switch pseudo code: {{{
      // Case of choice
      //   d    Display "Amount to deposit"
      //        Read sum to deposit
      //        IF deposit > 0 THEN
      //           balance = balance + deposit
      //        ELSE
      //          Display "No negative numbers. Returning to menu."
      //        END IF
      //   w    Display "Sum to withdraw"
      //        Read sum to withdraw
      //        IF sum_to_withdraw <= 0 THEN
      //           Display "Only positive numbers. Returning to menu"
      //        ELSE IF balance - sum_to_withdraw >= 0
      //           balance = balance - sum_to_withdraw
      //        ELSE
      //           Display "Withdrawal larger than balance. Returning to menu"
      //        END IF
      //   a    Display balance
      //   c    Display "Calculate interest-payment"
      //        Read yearly_deposit
      //        Read interest_rate (percents)
      //        Read num_of_years
      //        Write balance to interest_payment_sum
      //        FOR i = 1 to num_of_years
      //           interest_payment_sum = (interest_payment_sum + yearly_deposit) * (1 + (interest_rate / 100))
      //        END FOR
      //        Display "Result of calculation is: " interest_payment_sum
      //   r    Re-display menu
      //   q    Exit program
      //   Else   Display "Input error. Returning to menu."
      // End }}}

    // make case irrelevant for char in variable choice
    switch (tolower(choice))
    {
      case 'd':
        cout << "Amount to deposit: ";
        cin >> deposit;

        if (!cin) {  // if cin fails to read the input
          ClearCin();
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
        if (!cin) {
          ClearCin();
          cout << "   Input error. Returning to menu.\n";
          break;
        }

        if (withdrawal <= 0) {
          cout << "   Only positive numbers. Returning to menu.\n";
        }
        else if (accountBalance - withdrawal >= 0) {
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

        cout << "Sum to save (per year): ";
        cin >> yearlyDeposit;
        if (!cin) {
          ClearCin();
          cout << "   Input error. Returning to menu.\n";
          break;
        }

        cout << "Interest rate (in percents): ";
        cin >> yearlyInterestRate;
        if (!cin) {
          ClearCin();
          cout << "   Input error. Returning to menu.\n";
          break;
        }

        cout << "Number of years (to save during): ";
        cin >> numOfYears;
        if (!cin) {
          ClearCin();
          cout << "   Input error. Returning to menu.\n";
          break;
        }

        // Note: Not entirely clear in the spec if one should:
        // - include the result back into current account balance, or
        // - just report the result back
        //
        // I chose to just report the result from the calculation
        // (as opposed to including it back into the account balance)
        interestPaymentSum = accountBalance;
        for (int i=1; i <= numOfYears; i++) {
          interestPaymentSum = (interestPaymentSum + yearlyDeposit)
                                 * (1 + (yearlyInterestRate / 100));
          // If one wanted to include the result back into account balance,
          // the approach would instead be:
          // accountBalance = (accountBalance + yearlyDeposit)
          //                     * (1 + (yearlyInterestRate / 100));
        }
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
        cout << "Thank you for using SimpleBank!\n";
        return 0;

      default:
        cout << "   Unsupported input. Returning to menu.\n";
        break;
    }
  }

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
// [R]eprint Menu
//
// [Q]uit
// ----------
// Your choice: d
// Amount to deposit: 100
// Your choice: c
// TODO: Check First Testrun Below
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

