#include <iostream>
using namespace std;

int main() {
  cout << "Welcome to SimpleBank";

  while (true)
  {
    // Print the menu:
    cout << "[D]eposit: \n":
    cout << "[W]ithdraw\n";
    cout << "[A]ccount Balance\n";
    cout << "[C]alculate Interest-payment\n";
    cout << "[Q]uit\n";

    char menuSelection;  // the user's choice
    cin >> menuSelection;

    if (menuSelection == 'D' || menuSelection == 'd')
    {
      cout << "\n";
      // Code goes here
    }
    else if (menuSelection == 'H' || menuSelection == 'h')
    {
      cout << "\n";
      // Code goes here
    }
    else if (menuSelection == 'Q' || menuSelection == 'q')
    {
      break;  // avbryter while-loopen
    }
    else
    {
      cout << "Ogiltigt val!\n";
    }
  }

  cout << "Ange nr: ";
  int nr;
  cin >> nr;
  switch (nr)
  {
    case 1:
      cout << "case 1";
      break;

    case 2:
      cout << "case 2";
      break;

    default:
      cout << "defult case";
      break;
  }

  // cin.get()
  return 0;
}
