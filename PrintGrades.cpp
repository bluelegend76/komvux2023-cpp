#include <iostream>
#include <vector> // ??
using namespace std;

// Function to clear cin up until the next linebreak
void ClearCin() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
}


void ReadScores(const string subjectAreas[], int scores[], int arrsize) {  // = 'LasPoang'
  for (int i=0; i < arrsize; i++) {
    bool inputOk = false;
    while (!inputOk) {
      cout << "Input score for subject " << subjectAreas[i] << ": ";
      cin >> scores[i];
      if (!cin) {
        ClearCin();
        cout << "Input error. Try again.\n";
      }
      else if (scores[i] < 0 || scores[i] > 100) {
        cout << "Only values from 0 to 100. Try again.\n";
      }
      else {
        inputOk = true;
      }
    }
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
void ScoresToGrades(int gradesBySubject[], const int scores[], int arrsize) {
  for (int i=0; i < arrsize; i++) {
    // If-statement [that converts test-scores to A-F grades]
    // - later used to map to grades A-F (=using array 'grades')
    if (scores[i] >= 90 && scores[i] <= 100) {
      gradesBySubject[i] = 0;
      continue;
    }
    if else (scores[i] >= 80 && scores[i] < 90) {
      gradesBySubject[i] = 1;
      continue;
    }
    else if (scores[i] >= 70 && scores[i] < 80) {
      gradesBySubject[i] = 2;
      continue;
    }
    else if (scores[i] >= 60 && scores[i] < 70) {
      gradesBySubject[i] = 3;
      continue;
    }
    else if (scores[i] >= 50 && scores[i] < 60) {
      gradesBySubject[i] = 4;
      continue;
    }
    else if (scores[i] < 50) {
      gradesBySubject[i] = 5;
      continue;
    }
  }
}

void PrintGrades(const string subjectAreas[], const char grades[], const int gradesBySubject[], int arrsize) {  // 'skrivUtBetyg'
  cout << "=== Your Grade Scores Table ===" << endl;
  for (int i=0; i < arrsize; i++) {
    // mapping tally of grades to grade-letters
    cout << subjectAreas[i] << ": " << grades[gradesBySubject[i]] << endl;
  }
}

// TODO: [add Pseudo Code + Flow Chart]
void GradeStats(const int gradesBySubject[], const char grades[], const int scores[], int arrsize) {  // = 'Statistik'
  // Print number of A:s, C:s and F:s
  cout << "=== Printing Some Grade Stats ===" << endl;
  int numOfAs = 0, numOfCs = 0, numOfFs = 0;
  for (int i=0; i < arrsize; i++) {
    if (grades[gradesBySubject[i]] == 'A') {
      numOfAs++;
      continue;
    }
    else if (grades[gradesBySubject[i]] == 'C') {
      numOfCs++;
      continue;
    }
    else if (grades[gradesBySubject[i]] == 'F') {
      numOfFs++;
      continue;
    }
  }
  cout << "Number of A grades: " << numOfAs << endl;
  cout << "Number of C grades: " << numOfCs << endl;
  cout << "Number of F grades: " << numOfFs << endl;

  // Print total number of grade-score points
  int scorePointsTotal = 0;
  for (int i=0; i < arrsize; i++) {
    scorePointsTotal += scores[i];
  }
  cout << "Total number of points: " << scorePointsTotal << endl;
}


int main() {
  const int arrsize = 5;
  const string subjectAreas[arrsize] = {"Math","English","French","History","Physics"};  // 'amnen'
  int scores[arrsize];  // = 'poang'
  const char grades[6] = {'A','B','C','D','E','F'};
  // 0-5 =later to be referenced against grades A through F
  int gradesBySubject[arrsize] = {0}; // = 'betyg'

  cout << "--- Welcome to PrintGrades ---\n";

  ReadScores(subjectAreas, scores, arrsize);
  ScoresToGrades(gradesBySubject, scores, arrsize);

  PrintGrades(subjectAreas, grades, gradesBySubject, arrsize);
  GradeStats(gradesBySubject, grades, scores, arrsize);

  return 0;
}
