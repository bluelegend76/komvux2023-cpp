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
 
int linSearch(City obj[], int n, int key)
{
  for (int i=0; i <= n; i++) {
    if (obj[i].temp == key) {
      // return i;         
      cout << "Result: " << obj[i].name << endl;
      return 0;
    }
  }
  // return -1;
  cout << "Result: No city matches temp." << endl;
  return -1;
}   

void bubbleSort(City obj[2],int count) {
  //             'fält städer'
  for (int i = 0; i < count; i++) {
    // inner =walking through elements
    int nrleft = count - i;  // counter for checking already passed
    for (int j = 0; j < nrleft; j++) {
      if (obj[j].temp > obj[j+1].temp) { // comparing class-attributes
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
  const int asize = 2;
  City city[asize];

  // Get data from user:
  // = name and temp for cities
  //    +Check temp-values (between -60 and +60)
  cout << "--- Enter Cities and Temperatures ---" << endl;
  for (int i = 0; i < asize; i++) {
    city[i].getdata();
  }

  // Call function/method LinSearch
  // to search for city with certain temp
  cout << "--- Searching for city with certain temperature ---" << endl;
  cout << "Enter temp-value (=int) to search for: ";
  int key;
  cin >> key;
  linSearch(city, asize, key);

  // Sort array/vector 'cities' according to temp
  // (=coldest cities first)
  // +print names of cities (with temps)

    // simple initial echo-test
    // cout << city.ToString() << endl;
    // for (int i = 0; i < asize; i++) {
    //   // city[i].getdata();
    //   cout << city[i].ToString() << endl;
    // }

  cout << "--- Thanks for using WeatherStation! ---" << endl;

  return 0;
}

