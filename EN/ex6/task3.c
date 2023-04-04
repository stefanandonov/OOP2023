//
// Created by Stefan Andonov on 3.4.23.
//

#include<stdio.h>

typedef struct CertificateCov19 {
    int day, month, year;
    char name[50];
    int order;
} CertificateCov19;

typedef struct Patient {
    char name[50];
    char embg[14];
    CertificateCov19 certificate;
} Patient;

CertificateCov19 readCertificate() {
    CertificateCov19 certificate;
    scanf("%s\n%d/%d/%d\n%d", certificate.name, &certificate.day, &certificate.month, &certificate.year,
          &certificate.order);
    return certificate;
}

Patient readPatient() {
    Patient patient;
    scanf("%s\n%s", patient.name, patient.embg);
    patient.certificate = readCertificate();
    return patient;
}


void eligibleForThirdDose(Patient patients[], int count, int d, int m, int y) {
    for (int i = 0; i < count; i++) {
        if (patients[i].certificate.order == 2) {
            int desiredMonth = m - 6;
            int desiredYear = y;
            if (desiredMonth < 0) {
                desiredMonth += 12;
                desiredYear -= 1;
            }
            if (patients[i].certificate.day <= d
                && patients[i].certificate.month <= desiredMonth
                && patients[i].certificate.year == desiredYear) {
                printf("Name: %s - EMBG: %s\n", patients[i].name, patients[i].embg);
            }
        }
    }
}

void printPercent (Patient patients [], int n){
    int count = 0;
    for (int i=0;i<n;i++){
        if (patients[i].certificate.order==3){
            ++count;
        }
    }

    printf("%.2f%% of the patients have received a third dose of the vaccine", count*100.0/n);
}


int main() {
    Patient patients[30];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        patients[i] = readPatient();
    }

    int d, m, y;
    scanf("%d/%d/%d", &d, &m, &y);

    printf("Patients that can get a thrid dose on %d/%d/%d are:\n", d, m, y);
    eligibleForThirdDose(patients, n, d, m, y);

    printPercent(patients, n);

    return 0;
}
