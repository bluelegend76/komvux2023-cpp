#include <iostream>
#include <limits>
using namespace std;

// Clear cin (up until the next linebreak)
void ClearCin() {
  // resetting cin error flag
  cin.clear();
  // skip everything until next newline
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

// 'LasPoang' - Ask user to input subject-area scores
void ReadScores(const string subjectAreas[], int scores[], int arrsize) {
  for (int i=0; i < arrsize; i++) {
    bool inputOk = false;
    // ask repeatedly for scores until value passes checks
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

// The exact score ranges were not given in the spec,
// but this is the way I interpreted the instructions
// A: 90-100 ps
// B: 80-89 ps
// C: 70-79 ps
// D: 60-69 ps
// E: 50-59 ps
// F: <50 ps
void ScoresToGrades(int gradesBySubject[], const int scores[], int arrsize) {
  for (int i=0; i < arrsize; i++) {
    // If-statement [that converts test-scores to A-F grades]
    // - later used to map to grades A-F (=using array 'grades')
    if (scores[i] >= 90 && scores[i] <= 100) {
      gradesBySubject[i] = 0;
      continue;
    }
    else if (scores[i] >= 80 && scores[i] < 90) {
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

// 'skrivUtBetyg'
void PrintGrades(const string subjectAreas[], const char grades[], const int gradesBySubject[], int arrsize) {
  cout << "=== Your Grade Scores Table ===" << endl;
  for (int i=0; i < arrsize; i++) {
    // mapping tally of grades to grade-letters
    cout << subjectAreas[i] << ": " << grades[gradesBySubject[i]] << endl;
  }
}

  // 'Statistik' pseudo code:
  // FOR i = 0 to length of arrsize
  //    IF grades[grades_by_subject[i]] = 'A' THEN
  //       increment num_of_As
  //    ELSE IF grades[grades_by_subject[i]] = 'C' THEN
  //       increment num_of_Cs
  //    ELSE IF grades[grades_by_subject[i]] = 'F' THEN
  //       increment num_of_Fs
  //    END IF
  // END FOR
  // Display num_of_As
  // Display num_of_Cs
  // Display num_of_Fs
  // 
  // FOR i = 0 to length of arrsize
  //    score_points_total = score_points_total + scores[i]
  // END FOR
// 'Statistik'
void GradeStats(const int gradesBySubject[], const char grades[], const int scores[], int arrsize) {
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
  const string subjectAreas[arrsize] = {"Math","English","French","History","Physics"}; // 'amnen'
  int scores[arrsize]; // 'poang'
  const char grades[6] = {'A','B','C','D','E','F'};
  // 0-5 =later to be referenced against grades A through F
  int gradesBySubject[arrsize] = {0}; // = 'betyg'

  cout << "--- Welcome to PrintGrades ---" << endl;

  // Get subject-area scores from the user
  ReadScores(subjectAreas, scores, arrsize);
  // Convert scores to A-F grades (stored as integers 0-5)
  ScoresToGrades(gradesBySubject, scores, arrsize);

  // Match 0-5 grades to A-F scores and print grade-results
  PrintGrades(subjectAreas, grades, gradesBySubject, arrsize);
  // Printing number of A:s, C:s and F:s, and total num of score points
  GradeStats(gradesBySubject, grades, scores, arrsize);

  return 0;
}
