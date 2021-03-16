#include <iostream>
#include <fstream>
#include <cstring>

const unsigned SUBJECT_SIZE = 129;
const unsigned GRADES_COUNT = 5;
const unsigned MAX_SUBJECTS_COUNT = 20;

//grades[0] - брой 2-ки
//grades[1] = брой 3-ки
//...
//grades[4] - брой 6-ци

struct Subject {
    char subject[SUBJECT_SIZE];
    unsigned grades[GRADES_COUNT];
};

struct GradesBook {
    Subject subjects[MAX_SUBJECTS_COUNT];
    unsigned countSubjects;
};

Subject createSubject(const char* subject) {

    Subject newSubject;
    strcpy(newSubject.subject, subject);

    for(int i = 0; i < GRADES_COUNT; i++) {
        newSubject.grades[i] = 0;
    }

    return newSubject;
}

bool addGradeToSubject(unsigned grade, const char* subject, GradesBook& gradesbook) {

    if(grade < 2 || grade > 6)
        return 0;

    for(int i = 0; i < gradesbook.countSubjects; i++) {

        if(strcmp(subject, (gradesbook.subjects[i]).subject) == 0) {
             (gradesbook.subjects[i]).grades[grade - 2]++;
             return 1;
        }
    }

    if(gradesbook.countSubjects == MAX_SUBJECTS_COUNT)
        return 0;

    unsigned addAt = gradesbook.countSubjects;
    gradesbook.subjects[addAt] = createSubject(subject);
    (gradesbook.subjects[addAt]).grades[grade - 2]++;

    gradesbook.countSubjects++;
    return 1;
}

int main () {

    return 0;
}