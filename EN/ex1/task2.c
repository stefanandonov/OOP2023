//
// Created by Stefan Andonov on 27.2.23.
//

#include<stdio.h>
#include<ctype.h>
#include<string.h>

typedef struct Student {
    char name[20];
    int index;
    int points[4];
} Student;

Student readStudent() {
    Student student;
    scanf("%s %d", student.name, &student.index);
    for (int i = 0; i < 4; i++) {
        scanf("%d", &student.points[i]);
    }
    return student;
}

int totalPoints(Student student) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += student.points[i];
    }
    return sum;
}

int grade(int points) {
    int grade = (points / 10) + 1;
    if (grade > 10) {
        grade = 10;
    }
    if (grade < 5) {
        grade = 5;
    }
    return grade;
}

void normalizeName (char * name){
    name[0] = toupper(name[0]);
    for (int i=1;i<strlen(name);i++){
        name[i]= tolower(name[i]);
    }
}

void printStudent(Student student) {
    int points = totalPoints(student);
    int gr = grade(points);
    normalizeName(student.name);
    printf("%d %s %d %d\n", student.index, student.name, points, gr);
}

int studentcmp (Student left, Student right){
    if (totalPoints(left)> totalPoints(right)){
        return 1;
    } else if (totalPoints(left) < totalPoints(right)){
        return -1;
    } else {
        return 0;
    }
}

void swap(Student* xp, Student* yp)
{
    Student temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(Student students[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (studentcmp(students[j], students[j + 1])==-1)
                swap(&students[j], &students[j + 1]);
}

int main() {

    int N;//size of the array or the number of students
    Student students[100];

    scanf("%d", &N);

    for (int i=0;i<N;i++){
        students[i] = readStudent();
    }

    bubbleSort(students, N);

    for (int i=0;i<N;i++){
        printStudent(students[i]);
    }
    return 0;
}

