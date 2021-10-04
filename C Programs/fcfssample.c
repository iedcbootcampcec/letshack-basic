 #include <stdio.h>
#include<stdlib.h>

int main()
{
    int i,j;
    int temp,at[30],bt[30],ct[30]={0},tat[30],wt[30],n,sum=0;
    int tot_wt=0;
    int tot_tat=0;
    float atat,awt;
    printf("how many process");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the arrival time %d",i);
        scanf("%d",&at[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("enter the burst time %d",i);
        scanf("%d",&bt[i]);
    }


    for(i=0;i<n;i++)
    {
        sum += bt[i];           //complete time
        ct[i]+=sum;
    }
    for(i=0;i<n;i++)
    {
        tat[i] = ct[i]-at[i];           //turn around time
        tot_tat += tat[i];
    }
    for(i=0;i<n;i++)
    {
        wt[i] = tat[i]-bt[i];           //waiting time
        tot_wt+=wt[i];
    }

     printf("Process\t\tat\t\tbt\t\ttat\t\twt");
     atat=tot_tat/(float)n;
     awt=tot_wt/(float)n;

    for(i=0;i<n;i++)
    {
             printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,at[i],bt[i],tat[i],wt[i] );
    }
         printf("\nAveragae Turnaound time: %f",atat);
         printf("\nAveragae Turnaound time: %f",awt);



}

