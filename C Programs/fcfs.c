#include <stdio.h>
int main()
{
  int i,n,at[20],bt[20],ct[20],tat[20],wt[20],sum=0;
  float totWT=0,totTAT=0;
  printf("Enter the no:of processes:");
  scanf("%d",&n);
 
  for(i=0;i<n;i++)
  {
        printf("\nEnter arrival time of process %d :",i);
        scanf("%d",&at[i]);
        printf("\nEnter burst time of process %d :",i);
        scanf("%d",&bt[i]);
  }
 
  for(i=0;i<n;i++)
  {
        sum+=bt[i];
        ct[i]=sum;
  }
 
  for(i=0;i<n;i++)
  {
        tat[i]=ct[i]-at[i];
        totTAT+=tat[i];
  }
 
  for(i=0;i<n;i++)
  {
        wt[i]=tat[i]-bt[i];
        totWT+=wt[i];
  }
  printf("\nTABLE");
  printf("\n-----------");
  printf("\n\nP.NO\t AT\t BT\t CT\t TA\t WT");
 
  for(i=0;i<n;i++)
    {
        printf("\nP%d\t %d\t %d\t %d\t %d\t %d",i,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

  printf("\nAverage Turnaround Time: %f",totTAT/n);
  printf("\nAverage Waiting Time: %f\n",totWT/n);
}