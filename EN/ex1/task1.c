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

void readDate2(Date * date){
    scanf("%d.%d.%d", &date->day, &date->month, &date->year);
}

void printDate(Date date){
    printf("%02d.%02d.%d", date.day, date.month, date.year);
}

int intcmp (int left, int right){
    if (left>right){
        return 1;
    } else if (left<right){
        return -1;
    } else {
        return 0;
    }
}

int datecmp (Date left, Date right) {
    int cmpYear = intcmp(left.year, right.year);
    if (cmpYear!=0){
        return cmpYear;
    } else {
        int cmpMonth = intcmp(left.month, right.month);
        if (cmpMonth!=0){
            return cmpMonth;
        } else {
            return intcmp(left.day, right.day);
        }
    }



//    if (left.year > right.year){
//        return 1;
//    } else if (left.year < right.year) {
//        return -1;
//    } else { //left.year == right.year
//        if (left.month>right.month){
//            return 1;
//        } else if (left.month > right.month){
//            return -1;
//        } else { //left.year == right.year && left.month == right.month
//            if (left.day > right.day){
//                return 1;
//            } else if (left.day < right.day){
//                return -1;
//            } else {
//                return 0;
//            }
//        }
//    }
}

int main() {
//    Date date = readDate();
    Date left;
    Date right;
    readDate2(&left);
    readDate2(&right);

    if (datecmp(left,right)==1){
        printDate(left);
        printf(" > ");
        printDate(right);
    } else if (datecmp(left,right)==-1){
        printDate(left);
        printf(" < ");
        printDate(right);
    } else {
        printDate(left);
        printf(" == ");
        printDate(right);
    }
    return 0;
}