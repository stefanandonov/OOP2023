//
// Created by Stefan Andonov on 27.2.23.
//
#include<stdio.h>

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

Date readDate() {
    Date date;
    scanf("%d.%d.%d", &date.day, &date.month, &date.year);
    return date;
}

void readDatePtr(Date *date) {
    scanf("%d.%d.%d", &date->day, &date->month, &date->year);
}

void printDate(Date date) {
    printf("%02d.%02d.%04d\n", date.day, date.month, date.year);
}

//int intcmp (int left, int right) {
//
//}

int datecmp (Date left, Date right){
    /*
     * 1 left>right
     * 0 left==right
     * -1 left<right
     * */
    if (left.year > right.year){
        return 1;
    } else if (left.year < right.year) {
        return -1;
    } else { //left.year == right.year
        if (left.month > right.month){
            return 1;
        } else if (left.month < right.month){
            return -1;
        } else { //left.year == right.year && left.month == right.month
            if (left.day > right.day) {
                return 1;
            } else if (left.day < right.day) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}


int main() {
    Date date = readDate();
    Date date2;
    readDatePtr(&date2);

    printDate(date);
    printDate(date2);

    if (datecmp(date, date2)==0){
        printf("EQUAL");
    } else if (datecmp(date, date2)==1) {
        printf(">");
    } else {
        printf("<");
    }
    return 0;
}

