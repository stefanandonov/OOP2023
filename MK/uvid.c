#include<stdio.h>
#include<ctype.h>
#include<string.h>

/*
Да се напише програма која го наоѓа најмалиот позитивен цел број кој
недостатува во дадена низа А од N (N < 100) цели броеви.
Елементите на низата и нивниот број N се читаат од стандарден влез.
*/

int main() {
    int n;
    int max=0,min=99999,min2=99999;
    int a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]<min){
            min=a[i];
        }
        if(a[i]>max){
            max=a[i];
        }
    }

    for (int i=max;i>=min;i--){
    }

    for (int i=0;i<n;i++){
        for(int j=min;j<=max;j++){
            if(max==a[i]){
                printf("%d",max+1);
            }else if(a[i]<0){
                printf("1");
            }else if(a[j]!=a[i] && a[j]<min2){
                min2=a[j];
                printf("%d ",min2);
            }
        }
    }



    return 0;
}
