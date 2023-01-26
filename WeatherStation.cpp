#include <iostream>
#include <string>
using namespace std;

// Skapa en klass 'stad' som innehåller två attribut. {{{
//
// class Cities (
//   string name; // 'namn'
//   int temp;
//   public string ToString()
//     return this.name;
//     return (string)this.temp;
//   (=Note: Not print to console)
//
// // write PseudoCode + FlowCharts
// function|method: linearsearch of array (or vector)
//   with cities =return index of city w. specific temp
//     (+return '-1' if (temp) not found)
//
// 'int linsok(fält städer, int n, int söktemp)'
// int linearSearch(array cities, int n, int söktemp)
//                                 ^
//                      num. of elements in the array
//
// Skriv också en funktion/metod som
//  sorterar ett stad-fält efter temperatur
//  (kallast först).
// 'void bubblesort(fält städer, int n)'
// void bubblesort(array cities, int n)
// }}}
// - klassdeklarationen specificerar själva klassen (=.h-fil) {{{
// 
// . filen 'Lion.h'
// 
// // #include-guards används för att undvika att
// // en och samma klass inkluderas mer än en gång
// #ifndef LION_H
// #define LION_H
// 
// class Lion
// {
//   public:
//     int weight;
//     int age;
// 
//     void eat();
//     void sleep();
//     void hunt();
// };
// #endif  // Avsluta #include-guarden
// 
// 
// - klassdefinitionen (som innehåller definitionen(!) av klassen) (=.cpp-fil)
//     (definition av metoderna)
// 
// . filen 'Lion.cpp'
// 
// #include "lion.h"
//   // början: =inkludera deklarationen av klassen Lion
// #include <iostream>
// 
// using namespace std;
// void Lion::eat()
//   // void=returtyp
//   // Lion=namn på typen
//      // '::' =scope operator
//   //eat()=signatur för metoden
// {
//   cout << "eating" << endl;
// }
// void Lion::sleep()
// {
//   cout << "sleeping" << endl;
// }
// void Lion::hunt()
// {
//   cout << "hunting" << endl;
// }
// 
// 
// // int main() {
// //   cout << "Echo echo\n";
// //   return 0;
// // }
// // }}}
// class example {{{
// class CRectangle {
//     int x, y;
//   public:
//     void set_values (int,int);
//     int area () {return (x*y);}
// };
// 
// void CRectangle::set_values (int a, int b) {
//   x = a;
//   y = b;
// }
// }}}

class City {
  public:
    string name;
    int temp;

    string ToString() {
      return name + ", " + to_string(temp);
    }

    void getdata();
};

// linear search {{{
/* int LinSearch(string cities[], int arrsize, int tempsearch) { */
/*   // [+Pseudo code | Flow chart] */
/*   // -- */
/*   // Search array of city objects */
/*   // for city w. specific temperature */
/*   // and return array-index of that city */
/*   // (or -1 if no city is found) */
/*   // */ 

/* FOR i = 0 to the length of list */
/*   IF list[i] = element to search for THEN */
/*     Return i */
/*   END IF */
/* END FOR */

/* 3|15|7|1|42|97|52|33|82|19 */

/* Om vi söker efter talet 33 behöver vi gå igenom 8 element av 10 för att hitta */
/* det. Om vi skulle söka efter talet 19 skulle vi behöva gå igenom 10. Detta */
/* är okej då vi har en så kort lista. Men om vi skulle gå igenom en lista som */
/* innehåller miljontals element, skulle linjär sökning bli långsam. */

/* int myList[] = {3, 15, 7, 1, 42, 97, 52, 33, 82, 19}; */
/* int key = 33;  // Numret vi söker efter */

/* for (int i = 0; i < 10; i++)  // Gå igenom hela listan */
/* { */
/*   if (myList[i] == key)  // Är det numret vi söker? */
/*   { */
/*     cout << "elementet finns på index " << i; */
/*     break;  // Vi är klara och kan avbryta! */
/*   } */
/* } */

/* Exempel 15.2: Linjär sökning med struct */

/* #include <iostream> */
/* #include <vector> */
/* using namespace std; */

/* // STRUCT: Innehåller en person */
/* struct Person */
/* { */
/*   string name; */
/*   int pers_nr; */
/* }; */


/* // funktion: sätter den info som behövs, observera att vi skickar */
/* // in person som en referens. */
/* void SetInfo(vector<Person> &personList, string name, int pers_nr) */
/* { */
/*   Person person; */
/*   person.name = name; */
/*   person.pers_nr = pers_nr; */
/*   personList.push_back(person); */
/* } */

/* // funktion: LinearSearch söker reda på en person i en lista */
/* int LinearSearch(vector<Person> &personList, int key) */
/* { */
/*   for (int i = 0; i < 10; i++)  // Gå igenom hela listan */
/*   { */
/*     // Är det numret vi söker? */
/*     if (personList[i].pers_nr == key) */
/*         return i; */
/*   } */
/*   return -1;  // Personen hittades ej */
/* } */
/*   return 0; */
/* } */
/* // }}} */

// bubble sort {{{
/* void BubbleSort(string cities[], int arrsize) { */
/*   //             'fält städer' */

/* 15 13 7 1 42 */

/* Detta är första genomgången av listan, vi behöver kontrollera alla element. */

/* Steg 1.1: Talet 15 är mer än talet 13, byt plats! */

/* 13 15 7 1 42 */

/* Steg 1.2: Talet 15 är mer än talet 7, byt plats! */

/*     evince -p 165 ~/Empire/Doks/Comp/lang/clangs/cpp/cppprogr1.pdf & */

/* Steg 1.3: Talet 15 är mer än talet 1, byt plats! */

/* Steg 1.4: Talet 15 är mindre än än talet 42, gör ingenting! */

/* Nu har vi gått igenom alla tal i listan en gång, men listan är fortfarande inte */
/* färdigsorterad. Vad vi kan säga med säkerhet är dock att sista elementet i listan */
/* är på sin rätta plats. I fortsättningen kommer vi inte behöva gå igenom det. */


/* 2:a genomgången av listan */

/* Nu börjar vi om och gör samma sak en gång till, fast utan att jämföra med */
/* sista elementet, eftersom vi redan vet att det är klart. */

/* Steg 2.1: Talet 3 är mindre än talet 7, gör ingenting! */

/* Steg 2.2: Talet 7 är mer än talet 1, byt plats! */

/* Steg 2.3: Talet 7 är mindre än talet 15, gör ingenting! */

/* Vi kan nu vara säkra på att de två sista elementen är sorterade. */


/* 3:e genomgången av listan */

/* Steg 3.1: Talet 3 är mer än talet 1, byt plats! */

/* Som du kanske ser är listan redan färdigsorterad. Bubblesort är tyvärr inte lika */
/* smart som vi och fattar inte detta själv, utan kör vidare ändå! */

/* Steg 3.2: Talet 3 är mindre än talet 7, gör ingenting! */


/* 4:e genomgången av listan */

/* Steg 4.1: Talet 1 är mindre än talet 3, gör ingenting! */

/* Det finns inte längre några par att jämföra med varandra. Nu fattar bubblesort */
/* att listan är färdigsorterad! */

/*     evince -p 166 ~/Empire/Doks/Comp/lang/clangs/cpp/cppprogr1.pdf & */


/* 15.5.1 Implementering av bubblesort */

/* Jag hoppas att du nu förstår teorin bakom bubblesort. Låt oss nu implementera */
/* den i C++. För att göra detta behöver vi två loopar. En yttre och en inre loop: */

/* - En yttre loop, som går igenom listan flera gånger tills den är sorterad */
/* - En inre loop som går igenom element för element och jämför dem. Vi */
/* behöver inte gå igenom de redan sorterade talen. */

/* Följande pseudokod för Bubblesort hittade jag på webben: */

/* FOR i = 0 to length of list - 1 */
/*   FOR j = 0 to length of list - 1 - i */
/*     IF list[j] > list[j+1] THEN */
/*       Swap list[j] and list[j+1] */
/*     END IF */
/*   END FOR */
/* END FOR */

/* Om vi skapar en array, sorterar den och skriver ut, så kan vi göra på följande */
/* sätt: */

/* Exempel 15.3: Implememering av bubblesort */

/* int myList[] = {15, 3, 7, 1, 42}; */
/* int max = 4; */
/* // Den yttre loopen, går igenom hela listan */
/* for (int i = 0; i < max; i++) */
/* { */
/*   // Den inre, går igenom element för element */
/*   int nrLeft = max - i;  // För att se hur många som redan gåtts igenom */
/*   for (int j = 0; j < nrLeft; j++) */
/*   { */
/*     if (mylist[j] > mylist[j+1])  // Jämför elementen */
/*     { */
/*       // Byt plats! */
/*       int temp = mylist[j]; */
/*       myList[j] = mylist[j+1]; */
/*       myList[j+1] = temp; */
/*     } */
/*   } */
/* } */

/* // Skriv ut listan: */
/* for(int i = 0; i < 5; 1++) */
/*     cout << myList[i] << endl; */


/*   return 0; */
/* } */
/* // }}} */

void City::getdata() {
  cout << "Enter city: ";
  cin >> name;
  cout << "Enter temperature: ";
  cin >> temp;
};
 
int main() {
  // Declare an array w. four cities (+including their temp-measures)
  // = Values to be input by user when the program runs
  const int n = 4;
  City city[n];

  // Get data from user:
  // = name and temp for cities
  //    +Check temp-values (between -60 and +60)
  cout << "--- Enter Cities and Temperatures ---" << endl;
  for (int i = 0; i < n; i++) {
    city[i].getdata();
  }

  // Call function/method LinSearch
  // to search for city with certain temp

  // Sort array/vector 'cities' according to temp
  // (=coldest cities first)
  // +print names of cities (with temps)

  // cout << city.ToString() << endl;
  for (int i = 0; i < n; i++) {
    // city[i].getdata();
    cout << city[i].ToString() << endl;
  }
  cout << "--- Thanks for using WeatherStation ---"

  return 0;
}

