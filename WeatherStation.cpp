#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Function to clear cin up until the next linebreak
void ClearCin() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
}


class City {
  public:
    string name;
    int temp;

    string ToString() {
      return name + ", " + to_string(temp);
    }

    void GetData();
};

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
 
int linSearch(City obj[], int n, int key)
{
  for (int i=0; i < n; i++) {
    //@ cout << "Searching, inspecting city: " << obj[i].ToString() << endl;
    if (obj[i].temp == key) {
      return i;         
    }
  }
  return -1;
}

// Pseudo code BubbleSort ----
// FOR i = 0 to Length of list - 1
//   FOR j = 0 to Length of list - 1 - i
//     IF list[j] > list[j+1] THEN
//       Change place of elements list[j] and list[j+1]
//     END IF
//   END FOR
// END FOR
void bubbleSort(City obj[], int count) {
  //             'fält städer'
  for (int i = 0; i < count - 1; i++) {
    // inner: walking through elements
    int nrleft = count - 1 - i;  // counter for checking already processed objects
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
  // Declare an array with four cities (+including their temp-measures)
  const int asize = 4;
  City cities[asize];

  // Get data from user:
  // = name and temp for cities
  cout << "--- Enter Cities and Temperatures ---" << endl;
  for (int i = 0; i < asize; i++) {
    cities[i].GetData();
  }

  // Sorting array 'cities' by temp
  cout << "--- Sorting Cities by Temperature (coldest first) ---" << endl;
  bubbleSort(cities, asize);
  // print sorted city names (with corresponding temps)
  for (int i = 0; i < asize; i++) {
    cout << cities[i].ToString() << endl;
  }

  // Call function/method LinSearch
  // to search for city with certain temp
  cout << "--- Searching for city with certain temperature ---" << endl;
  cout << "Enter temp-value (=int) to search for: ";
  int key;
  cin >> key;
  int resultNum;
  resultNum = linSearch(cities, asize, key);

  if (resultNum == -1) {
    cout << "Result: No city-temp matches search key." << endl;
  }
  else {
    cout << "Result: " << cities[resultNum].name << " has temp " << key << endl;
  }

  cout << "--- Thanks for using WeatherStation! ---" << endl;
  return 0;
}

