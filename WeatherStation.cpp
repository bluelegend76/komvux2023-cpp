#include <iostream>
#include <string>
using namespace std;

class City {
  public:
    string name;
    int temp;

    string ToString() {
      return name + ", " + to_string(temp);
    }

    void getdata();
};

void City::getdata() {
  cout << "Enter city: ";
  cin >> name;
  cout << "Enter temperature: ";
  cin >> temp;
};
 
// "Om key inte finns med i din array
//  så kommer du att krascha"
int linSearch(City obj[], int n, int key)
{
  for (int i=0; i < n; i++) {
    // cout << "Searching, inspecting city: " << obj[i].ToString() << endl;
    if (obj[i].temp == key) {
      return i;         
    }
  }
  return -1;
}

// "Finns en bugg i sorten
//  som kommer göra att den kraschar
//  i slutet av sin körning"
//      + "kompileringsfel om
//         ändrar storlek på arrayen"
void bubbleSort(City obj[], int count) {
  //             'fält städer'
  for (int i = 0; i < count - 1; i++) {
    // inner =walking through elements
    int nrleft = count - 1 - i;  // counter for checking already processed objects
    for (int j = 0; j < nrleft; j++) {
      // comparing by value in object attribute 'temp'
      if (obj[j].temp > obj[j+1].temp) {
        cout << "Sorting, inspecting city: " << obj[j].ToString() << endl;
        cout << "Sorting, inspecting city: " << obj[i].ToString() << endl;
        // changing place
           // City tmp[1];
        City tmp = obj[j];
        obj[j] = obj[j+1];
        obj[j+1] = tmp;
      }
    }
  }
}


int main() {
  // Declare an array w. four cities (+including their temp-measures)
  // = Values to be input by user when the program runs
  const int asize = 4;
  City cities[asize];

  // Get data from user:
  // = name and temp for cities
  //    +Check temp-values (between -60 and +60)
  cout << "--- Enter Cities and Temperatures ---" << endl;
  for (int i = 0; i < asize; i++) {
    cities[i].getdata();
  }

  // Sorting array 'cities' by temp
  cout << "--- Sorting Cities by Temperature (coldest first) ---" << endl;
  bubbleSort(cities, asize);
  // +print sorted city names (with corresponding temps)
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

  // simple initial echo-test
  // cout << cities.ToString() << endl;
  // for (int i = 0; i < asize; i++) {
  //   // cities[i].getdata();
  //   cout << cities[i].ToString() << endl;
  // }

  cout << "--- Thanks for using WeatherStation! ---" << endl;
  return 0;
}

