#include <iostream>
#include <vector> // ??
using namespace std;

const int cArrsize = 5;
// (or 'courses') = 'amnen'
const string subjectAreas[cArrsize] = {"Math","English","French","History","Physics"};
int scores[cArrsize];  // = 'poang'  (or a vector)
  // int scores[sizeof(subjectAreas) / sizeof(string)];
const char grades[6] = {'A','B','C','D','E','F'};
// 0-5 =later to be referenced against grades A through F
int gradesBySubjects[cArrsize] = {0,0,0,0,0}; // = 'betyg'

void ReadScores() {  // = 'LasPoang'
  // TODO: Add checks
  //  - Only numbers as input (+how to handle inside a for-loop(??))
  //  - Only numbers from 0 to 100 allowed
      // TODO "Kom ihåg att du måste lägga {{{
      // cin >> poang[i]; även i if satsen
      // annars räknas felaktiga poängen i alla fall" (??) }}}
  for (int i=0; i < cArrsize; i++) {
    cout << "Input score for subject " << subjectAreas[i] << ": ";
    cin >> scores[i];
  }
}

// TODO: Comment about interpretation of grades-score spans
//       (=bit unclear in the spec)
// A = 90-100ps ... {{{
// B = 80-89ps
// C = 70-79ps
// D = 60-69ps
// E = 50-59ps
// F = <50ps }}}
void ScoresToGrades() {
  for (int i=0; i < cArrsize; i++) {
    // If-statement [that converts test-scores to A-F grades]
    // - later used to map to scores A-F (=using array 'grades')
    if (scores[i] >= 80 && scores[i] < 90) {
      // gradesBySubjects.push_back() 
      gradesBySubjects[i] = 1;
      continue;
    }
    else if (scores[i] >= 70 && scores[i] < 80) {
      gradesBySubjects[i] = 2;
      continue;
    }
    else if (scores[i] >= 60 && scores[i] < 70) {
      gradesBySubjects[i] = 3;
      continue;
    }
    else if (scores[i] >= 50 && scores[i] < 60) {
      gradesBySubjects[i] = 4;
      continue;
    }
    else if (scores[i] < 50) {
      gradesBySubjects[i] = 5;
      continue;
    }
  }
}

void PrintGrades() { // 'skrivUtBetyg'
  cout << "=== Your Grade Scores Table ===" << endl;
  for (int i=0; i < cArrsize; i++) {
    // mapping tally of grades to grade-letters
    cout << subjectAreas[i] << ": " << grades[gradesBySubjects[i]] << endl;
  }
}

// TODO: [add Pseudo Code + Flow Chart]
void GradeStats() { // = 'Statistik'
  // Print number of A:s, C:s and F:s
  cout << "=== Printing Some Grade Stats ===" << endl;
  int numOfAs = 0, numOfCs = 0, numOfFs = 0;
  for (int i=0; i < cArrsize; i++) {
    if (grades[gradesBySubjects[i]] == 'A') {
      numOfAs++;
      continue;
    }
    else if (grades[gradesBySubjects[i]] == 'C') {
      numOfCs++;
      continue;
    }
    else if (grades[gradesBySubjects[i]] == 'F') {
      numOfFs++;
      continue;
    }
  }
  cout << "Number of A grades: " << numOfAs << endl;
  cout << "Number of A grades: " << numOfCs << endl;
  cout << "Number of A grades: " << numOfFs << endl;

  // Print total number of grade-score points
  int scorePointsTotal = 0;
  for (int i=0; i < cArrsize; i++) {
    scorePointsTotal += scores[i];
  }
  cout << "Total number of points: " << scorePointsTotal << endl;
}


int main() {
  cout << "--- Welcome to PrintGrades ---\n";

  ReadScores();
  ScoresToGrades();

  PrintGrades();
  GradeStats();

  return 0;
}
