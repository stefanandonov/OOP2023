#include <stdio.h>
#include <string.h>
typedef struct Employee
{
    char name[100];
    char id[100];
    char dpt[100];
    int salary;
} Employee;

typedef struct Company
{
    char name[100];
    int employees;
    Employee emp[100];
} Company;

void printEmployeesBelowAverageSalary(Company *comp, int numCompanies)
{
    int sum=0;
    float avg=0;
    for (int i=0;i<numCompanies;i++)
    {
        sum=0;
        avg=0;
        for (int j=0;j<comp[i].employees;j++)
        {
            sum+=comp[i].emp[j].salary;
        }
        avg=(sum*1.0)/comp[i].employees;
        for (int j=0;j<comp[i].employees;j++)
        {
            if (comp[i].emp[j].salary<avg)
            {
                printf("%s %s %s %d\n",comp[i].emp[j].name,comp[i].emp[j].id,comp[i].emp[j].dpt,comp[i].emp[j].salary);
            }
        }
    }

}

int main() {
    int n;
    Company A[100];
    char dpt[100];

    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%s\n%d",A[i].name,&A[i].employees);
        for (int y=0;y<A[i].employees;y++)
        {
            scanf("%s %s %s %d",A[i].emp[y].name,A[i].emp[y].id,A[i].emp[y].dpt,&A[i].emp[y].salary);
        }
    }
    scanf("%s",dpt);
    printf("Employees with salaries below the average:\n");
    printEmployeesBelowAverageSalary(A,n);
    //printHighestSalaryEmployee(A,n,dpt);
    return 0;
}