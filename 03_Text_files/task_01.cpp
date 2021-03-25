#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const unsigned SUBJECT_SIZE = 129;
const unsigned GRADES_COUNT = 5;
const unsigned MAX_SUBJECTS_COUNT = 20;

//grades[0] - брой 2-ки
//grades[1] = брой 3-ки
//...
//grades[4] - брой 6-ци

struct Subject {
    char subjectName[SUBJECT_SIZE];
    unsigned grades[GRADES_COUNT];
};

struct GradesBook {
    Subject subjects[MAX_SUBJECTS_COUNT];
    unsigned countSubjects;
};

Subject createSubject(const char* subjectName) {

    Subject newSubject;
    strcpy(newSubject.subjectName, subjectName);

    for(int i = 0; i < GRADES_COUNT; i++) {
        newSubject.grades[i] = 0;
    }

    return newSubject;
}

bool addGradeToSubject(unsigned grade, const char* subject, GradesBook& gradesBook) {

    if(grade < 2 || grade > 6)
        return 0;

    for(int i = 0; i < gradesBook.countSubjects; i++) {

        if(strcmp(subject, (gradesBook.subjects[i]).subjectName) == 0) {
             (gradesBook.subjects[i]).grades[grade - 2]++;
             return 1;
        }
    }

    if(gradesBook.countSubjects == MAX_SUBJECTS_COUNT)
        return 0;

    unsigned addAt = gradesBook.countSubjects;
    gradesBook.subjects[addAt] = createSubject(subject);
    (gradesBook.subjects[addAt]).grades[grade - 2]++;

    gradesBook.countSubjects++;
    return 1;
}

void writeSubject(ofstream& oFile, const Subject& subject) {

    oFile << subject.subjectName << endl;

    for(int i = 0; i < GRADES_COUNT; i++) {
        oFile << subject.grades[i] << ' ';
    }

    oFile << endl;
}

void writeGradesBook(const char* filename, const GradesBook& gradesBook){

    ofstream oFile(filename, ios::out);

    oFile << gradesBook.countSubjects << endl;

    for(int i = 0; i < gradesBook.countSubjects; i++)
        writeSubject(oFile, gradesBook.subjects[i]);

    oFile.close();
}

void readSubject(ifstream& iFile, Subject& subject) {

    iFile >> subject.subjectName;

    for(int i = 0; i < GRADES_COUNT; i++) {
        iFile >> subject.grades[i];
    }
}

void readgradesBook(const char* filename, GradesBook& gradesBook) {

    ifstream iFile(filename, ios::in);

    iFile >> gradesBook.countSubjects;

    for(int i = 0; i < gradesBook.countSubjects; i++) 
        readSubject(iFile, gradesBook.subjects[i]);

    iFile.close();
}

double getAverageScore(const Subject& subject) {
    
    unsigned grades = 0;
    double gradesSum = 0;

    for(int i = 0; i < GRADES_COUNT; i++) {
        grades += subject.grades[i];
        gradesSum += ((i + 2) * subject.grades[i]);
    }

    return (gradesSum / grades);
}

void printSubject(const Subject& subject) {

    cout << "Subject: " << subject.subjectName << endl 
         << "Grades: " << endl;

    for(int i = 0; i < GRADES_COUNT; i++)
        cout << i + 2 << ": " << subject.grades[i] << endl;

    cout << "Average score: " << getAverageScore(subject) << endl;
}

void summarizeSubject(const GradesBook& gradesBook, const char* subjectName) {

    for(int i = 0; i < gradesBook.countSubjects; i++) {
        if(strcmp ((gradesBook.subjects[i]).subjectName, subjectName) == 0) {
            printSubject(gradesBook.subjects[i]);
            return;
        }
    }
}

void summarizeGradesbook(const GradesBook& gradesBook) {

    double gradesSum = 0;
    double averageScore = 0;

    for(int i = 0; i < gradesBook.countSubjects; i++) {

        averageScore = getAverageScore(gradesBook.subjects[i]);
        gradesSum += averageScore;

        cout << "Subject: "       
             << (gradesBook.subjects[i]).subjectName
             << " ----- "
             << "Average score: " 
             << averageScore << endl;
    }

    cout << "Score: " << (gradesSum / gradesBook.countSubjects) << endl;
}

int main () {

    return 0;
}