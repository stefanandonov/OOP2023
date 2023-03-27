//
// Created by Stefan Andonov on 27.3.23.
//

#include<iostream>
#include<cstring>

using namespace std;

class Student {
private:
    char ID [7];
    char * name; //1. declaration
    int numberOfGrades;
    int * grades; //1. declaration

    void copy (const Student & other){
        strcpy(this->ID, other.ID);
        this->name = new char [strlen(other.name)+1]; //2. initialization
        strcpy(this->name, other.name); //3. content
        this->numberOfGrades = other.numberOfGrades;
        this->grades = new int [this->numberOfGrades];
//        strcpy(this->grades, grades); PLEASE GOD NO!!!!!!
        for (int i=0;i<numberOfGrades;i++){
            this->grades[i] = other.grades[i];
        }
    }
public:

    Student (){
        name = new char[0];
        grades = new int [0];
        strcpy(ID, "");
        numberOfGrades = 0;
    }

    Student (char * ID, char * name, int numberOfGrades, int * grades){
        strcpy(this->ID, ID);
        this->name = new char [strlen(name)+1]; //2. initialization
        strcpy(this->name, name); //3. content
        this->numberOfGrades = numberOfGrades;
        this->grades = new int [numberOfGrades];
//        strcpy(this->grades, grades); PLEASE GOD NO!!!!!!
        for (int i=0;i<numberOfGrades;i++){
            this->grades[i] = grades[i];
        }
    }

    Student(const Student & other){
        copy(other);
    }

    Student & operator = (const Student & other) {
        if (this == &other){
            return *this;
        }

        delete [] name;
        delete [] grades;
        copy(other);
        return *this;
    }

    ~Student() {
        delete [] name;
        delete [] grades;
    }

    void print() {
        //TODO home calculate average grade;
        cout << ID << " " << name << endl;
    }

    friend class Faculty;
};

class Faculty {
private:
    char name [20];
    Student * students;
    int n;
public:
    Faculty(char * name = "FINKI"){ //2in1
        strcpy(this->name, name);
        n = 0;
        students = new Student [n];
    }

    bool alreadyExists (Student & s){
        for (int i=0;i<n;i++){
            if (strcmp(students[i].ID, s.ID)==0){
                return true;
            }
        }

        return false;
    }

    void add (Student & s){
        if (alreadyExists(s)){
            return ;
        }
        Student * tmp = new Student[n+1];
        for (int i=0;i<n;i++){
            tmp[i] = students[i];
        }

        tmp[n]=s;
        ++n;

        delete [] students;
        students = tmp;
    }

    ~Faculty() {
        delete [] students;
    }

    void print () {
        cout << name << endl;
        for (int i=0;i<n;i++){
            students[i].print();
        }
    }
};

int main () {


    Faculty faculty;
    int n;
    cin >> n;

    char ID [7];
    char  name[20]; //1. declaration
    int numberOfGrades;
    int  grades[10]; //1. declaration

    for (int i=0;i<n;i++){
        cin >> ID >> name >> numberOfGrades;
        for (int j=0;j<numberOfGrades;j++){
            cin >> grades[j];
        }
        Student s(ID, name, numberOfGrades, grades);
        faculty.add(s);
    }

    faculty.print();

    return 0;
}
