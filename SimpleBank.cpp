#include <iostream>
#include <ctype>
using namespace std;

int main() {
  cout << "Welcome to SimpleBank." << endl;

  // {{{
  // while (true)
  // {
  //   // Print the menu:
  //   cout << "[D]eposit: \n";
  //   cout << "[W]ithdraw\n";
  //   cout << "[A]ccount Balance\n";
  //   cout << "[C]alculate Interest-payment\n";
  //   cout << "[Q]uit\n";

  //   char menuSelection;  // the user's choice
  //   cin >> menuSelection;

  //   if (menuSelection == 'D' || menuSelection == 'd')
  //   {
  //     cout << "(choice is Deposit)\n";
  //     // Code goes here
  //   }
  //   else if (menuSelection == 'W' || menuSelection == 'w')
  //   {
  //     cout << "(choice is Withdraw)\n";
  //     // Code goes here
  //   }
  //   else if (menuSelection == 'A' || menuSelection == 'a')
  //   {
  //     cout << "(choice is Account Balance)\n";
  //     // Code goes here
  //   }
  //   else if (menuSelection == 'C' || menuSelection == 'c')
  //   {
  //     cout << "(choice is Calculate Interest-payment)\n";
  //     // Code goes here
  //   }
  //   else if (menuSelection == 'Q' || menuSelection == 'q')
  //   {
  //     break;  // avbryter while-loopen
  //   }
  //   else
  //   {
  //     cout << "Unsupported choice! Try again.\n";
  //   }
  // }
  // }}}

  // {{{
  // Print menu
  cout << "[D]eposit\n";
  cout << "[W]ithdraw\n";
  cout << "[A]ccount Balance\n";
  cout << "[C]alculate Interest-payment\n";
  cout << "[Q]uit\n";
  
  while (true) {
    cout << "Your choice: \n";
    char choice;
    cin >> choice;

    switch (tolower(choice))
    {
      case 'd':
        cout << "Deposit\n";
        break;

      case 'w':
        cout << "Withdraw\n";
        break;

      case 'a':
        cout << "Account Balance\n";
        break;

      case 'c':
        cout << "Calculate Interest-payment\n";
        break;

      case 'q':
        return 0;
        break;

      default:
        cout << "Unsupported input! Try again.\n";
        break;
    }
  }
  // }}}

  // cin.get()
  return 0;
}
