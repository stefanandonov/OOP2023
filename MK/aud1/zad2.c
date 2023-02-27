//
// Created by Stefan Andonov on 27.2.23.
//

#include<stdio.h>

typedef struct Student {
    char name[20];
    int index, t1, t2, t3, t4;
} Student;

Student readStudent() {
    Student result;
    scanf("%s %d %d %d %d %d", result.name, &result.index, &result.t1, &result.t2, &result.t3, &result.t4);
    return result;
}

int grade(int points) {
    int grade = points / 10 + 1;
    if (grade > 10) {
        grade = 10;
    }
    if (grade < 5) {
        grade = 5;
    }
    return grade;
}

int totalPoints(Student student) {
    return student.t1 + student.t2 + student.t3 + student.t4;
}

void printStudent(Student student) {
    int pts = totalPoints(student);
    printf("%s %d Total points: %d Grade: %d\n", student.name, student.index, pts, grade(pts));
}


int studentcmp(Student left, Student right) {
    int leftTotalPoints = totalPoints(left);
    int rightTotalPoints = totalPoints(right);

    if (leftTotalPoints > rightTotalPoints) {
        return 1;
    } else if (leftTotalPoints < rightTotalPoints) {
        return -1;
    } else {
        return 0;
    }

}

void swap(Student *xp, Student *yp) {
    Student temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(Student * students, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (studentcmp(students[j], students[j + 1]) == -1)
                swap(&students[j], &students[j + 1]);
}

int main() {
    Student students[100];
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        students[i] = readStudent();
    }

    bubbleSort(students, N);

    for (int i = 0; i < N; i++) {
        printStudent(students[i]);

    }
    return 0;
}

