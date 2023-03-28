//
// Created by Stefan Andonov on 28.3.23.
//

#include<iostream>
#include<cstring>
using namespace std;

class Student {
private:
    char ID [7];
    char * name; //dynamically allocated array of chars
    int numberOfGrades;
    int * grades;

    void copy (const Student & other) {
        strcpy(this->ID, other.ID);
        this->name = new char [strlen(other.name)+1];
        strcpy(this->name, other.name);
        this->numberOfGrades = other.numberOfGrades;
        this->grades = new int [other.numberOfGrades];
        for (int i=0;i<numberOfGrades;i++){
            this->grades[i] = other.grades[i];
        }
    }
public:
    Student (char * ID = "151020", char * name = "Stefan", int numberOfGrades = 0, int * grades = {}){
        strcpy(this->ID, ID);
        this->name = new char [strlen(name)+1];
        strcpy(this->name, name);
        this->numberOfGrades = numberOfGrades;
        this->grades = new int [this->numberOfGrades];
        for (int i=0;i<numberOfGrades;i++){
            this->grades[i] = grades[i];
        }
    }

    Student (const Student & other){
        copy(other);
    }

    Student & operator = (const Student & other) {
        if (this==&other){
            return *this;
        }

        delete [] name;
        delete [] grades;
        copy(other);
        return *this;
    }

    ~Student(){
        delete [] name;
        delete [] grades;
    }
};

class Faculty {
private:
    char name [50];
    Student * students;
    int count;
public:
    Faculty(char * name = "FINKI"){
        strcpy(this->name, name);
        count = 0;
        students = new Student[0];
    }
};

int main () {
    Student students [100];
    return 0;
}
