#include <iostream>
#include <ctype>
using namespace std;

int main() {
  cout << "Welcome to SimpleBank." << endl;

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

  // cin.get()
  return 0;
}
