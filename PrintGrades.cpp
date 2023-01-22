#include <iostream>
#include <vector>
using namespace std;

// = 'amnen'  // (or 'courses')
// ev. skapa konstant för array-storlek
const string subjectAreas[5] = {"Math","English","French","History","Physics"};
int scores[5];   // = 'poang' // (or a vector)
// int scores[sizeof(subjectAreas) / sizeof(string)];
// 0-5 representing the grades A through F
// char grades[6]; (??)
int grades[6];  // = 'betyg'

int readScores() {  // = 'LasPoang'
  for (i=1; i < len-readScores, i++) {
    // (vector, list or array --v)
    cout << "Input score for subject " << subjectAreas[i] << ": ";
      // "Kom ihåg att du måste lägga
      // cin >> poang[i]; även i if satsen
      // annars räknas felaktiga poängen i allafall" (??)
    cin >> scores[i];
  }
}

int "Convert Scores to Grades"() {  // = '' [scoresToGrades]  ((readScores ??)
  for (i=0; i < scores.size(); i++) {
    for (; i < grades.size(); ) {
      if (scores[i] == 100) {  // If-statement [that converts test-scores to A-F-grades]
        //   A = 100-90ps
        //   B = 80-89ps
        //   C = 70-79ps
        //   D = 60-69ps
        //   E = 50-59ps
        //   F = <50ps
        grades[j]++
      }
      // else if (scores[i] < 100 && >= 90) {
      //   grades[j]++
      // }
    }
  }
}

int printGrades() {  // = 'skrivUtBetyg'
  cout << "=== Table of Grade Scores ===";
  for (i=0; i < grades.size(); i++) {
    for (j=0; j < subjectAreas.size(); j++) {
      cout << subjectAreas[j] << ": " << grades[i]
    }
  }
}

    // [+Pseudo Code | Flow Chart]
int gradeStats() {  // = 'Statistik'
  // Print number of A:s, C:s and F:s
  // Print total number of grade-score points
     // cout << "Input score for subject _";
}

int main() {
  cout << "Echo echo\n";
  return 0;
}
