#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Clear cin (up until the next linebreak)
void ClearCin() {
  // resetting cin error flag
  cin.clear();
  // skip everything until next newline
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

// Storing city and temperature in an object
// (+ability to print compound as a string)
class City {
  public:
    string name;
    int temp;

    string ToString() {
      return name + ", " + to_string(temp);
    }

    void GetData();
};

// Get city and temperature data from user
void City::GetData() {
  cout << "Enter city: ";
  cin >> name;

  bool inputOk = false;
  while (!inputOk) {
    cout << "Enter temperature: ";
    cin >> temp;
    if (!cin) {
      ClearCin();
      cout << "Input error. Try again.\n";
    }
    else if (temp < -60 || temp > 60) {
      cout << "Only values from -60 to 60. Try again.\n";
    }
    else {
      inputOk = true;
    }
  }
};
 
// Search by attribute 'temp' in an array of City objects
// returning object index if found
int linSearch(City obj[], int n, int key)
{
  for (int i=0; i < n; i++) {
    if (obj[i].temp == key) {
      return i;         
    }
  }
  // matching object was not found
  return -1;
}

  // Pseudo code BubbleSort ----
  // FOR i = 0 to arrlength - 1
  //   FOR j = 0 to arrlength - 1 - i
  //     IF array[j] > array[j+1] THEN
  //       Change place of elements array[j] and array[j+1]
  //     END IF
  //   END FOR
  // END FOR
// Sort array of City objects
// TODO: FLOWCHART
void bubbleSort(City obj[], int count) {
  for (int i = 0; i < count - 1; i++) {
    // inner: walking through elements
    int nrleft = count - 1 - i;  // counter for tracking already processed objects
    for (int j = 0; j < nrleft; j++) {
      // comparing by value in object attribute 'temp'
      if (obj[j].temp > obj[j+1].temp) {
        // changing place
        City tmp = obj[j];
        obj[j] = obj[j+1];
        obj[j+1] = tmp;
      }
    }
  }
}


int main() {
  // Declaring an array of class City objects
  const int asize = 4;
  City cities[asize];

  // Get data from user
  // (name and temp for cities)
  cout << "--- Enter Cities and Temperatures ---" << endl;
  for (int i = 0; i < asize; i++) {
    cities[i].GetData();
  }

  // Sorting array 'cities' by temp
  cout << "--- Sorting Cities by Temperature (coldest first) ---" << endl;
  bubbleSort(cities, asize);
  // print data for sorted array of City instances
  for (int i = 0; i < asize; i++) {
    cout << cities[i].ToString() << endl;
  }

  // Search for city with certain temp using linSearch
  cout << "--- Searching for city with certain temperature ---" << endl;
  cout << "Enter temp-value (=int) to search for: ";
  int key;
  cin >> key;
  int resultNum;
  resultNum = linSearch(cities, asize, key);
  // report result of search operation
  if (resultNum == -1) {
    cout << "Result: No city-temp matches search key." << endl;
  }
  else {
    cout << "Result: " << cities[resultNum].name << " has temp " << key << endl;
  }

  cout << "--- Thanks for using WeatherStation! ---" << endl;
  return 0;
}

