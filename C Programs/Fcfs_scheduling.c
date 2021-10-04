#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(){
    int i=0,n,at[100],bt[100],ct[100],tat[100],wt[100];
    float totalTat =0, totalWt=0;

    printf("enter the limit of process required");
    scanf("%d",&n);

    for(i=0;i<n;i++){

        printf("enter the arrival time of %d process ",i+1);
        scanf("%d",&at[i]);
        printf("enter the burst  time of %d process",i+1);
        scanf("%d",&bt[i]);
    }
     ct[0]= bt[0];
    for(i=1;i<n;i++){
        ct[i] =ct[i-1]+bt[i] ;
    }

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        totalTat += tat[i];
    }
    for(i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
        totalWt += wt[i];
    }
    for(i=0;i<n;i++){
    printf("%d %d %d %d %d %d \n",(i+1),at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("Avg tat: %f",totalTat/n);
    printf("Avg wt: %f",totalWt/n);
}
