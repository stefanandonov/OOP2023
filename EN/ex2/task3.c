
#include<stdio.h>
#include<string.h>

typedef struct SkiLift {
    char name[15];
    int capacity;
    int active;
} SkiLift;

SkiLift readSkiLift() {
    SkiLift result;
    scanf("%s%d%d", result.name, &result.capacity, &result.active);
    return result;
}

void printSkiLift(SkiLift skiLift) {
    //TODO maybe if needed
}

typedef struct SkiCenter {
    char name[20];
    char country[20];
    SkiLift skiLifts[20];
    int count;
} SkiCenter;

SkiCenter readSkiCenter() {
    SkiCenter result;
    scanf("%s%s%d", result.name, result.country, &result.count);
    for (int i = 0; i < result.count; i++) {
        result.skiLifts[i] = readSkiLift();
    }
    return result;
}

int skiCenterCapacity(SkiCenter sc) {
    int sum = 0;
    for (int i = 0; i < sc.count; i++) {
        if (sc.skiLifts[i].active) {
            sum += sc.skiLifts[i].capacity;
        }
    }
    return sum;
}

void printSkiCenter(SkiCenter sc) {
    printf("%s\n%s\n%d", sc.name, sc.country, skiCenterCapacity(sc));

}

int skicentercmp(SkiCenter left, SkiCenter right) {
    int leftCapacity = skiCenterCapacity(left);
    int rightCapacity = skiCenterCapacity(right);

    if (leftCapacity > rightCapacity) {
        return 1;
    } else if (leftCapacity < rightCapacity) {
        return -1;
    } else {
        if (left.count>right.count){
            return 1;
        } else if (left.count < right.count){
            return -1;
        } else {
            return 0;
        }
    }
}

void biggestCapacity(SkiCenter *sc, int n) {
    SkiCenter max = sc[0];
    for (int i = 1; i < n; i++) {
        if (skicentercmp(sc[i], max) == 1){
            max = sc[i];
        }
    }

    printSkiCenter(max);
}


int main() {
    int n;
    scanf("%d", &n);
    SkiCenter skiCenters[100];
    for (int i = 0; i < n; i++) {
        skiCenters[i] = readSkiCenter();
    }

    biggestCapacity(skiCenters, n);

//    for (int i = 0; i < n; i++) {
//        printSkiCenter(skiCenters[i]);
//    }

    return 0;
}