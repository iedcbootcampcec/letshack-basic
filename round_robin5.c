#include <stdio.h>

void main ()

{ 
int i, n,x, complete=0,count=0, time_quantum; 
int at[25], bt[25], temp[25]; 
float totWT=0, totTAT=0;

printf ("\n Enter the no: of processes:"); 
scanf ("%d", &n); 
x=n;
for (i=0; i<n; i++)
{ 
printf ("\n Enter arrival time of process %d:", i); 
scanf ("%d",&at[i]); 
printf ("\n Enter burst time of process %d:",i);
scanf("%d",&bt[i]);
temp[i]=bt[i];
}


printf ("\n Enter the time quantum :"); 
scanf ("%d", &time_quantum); 
printf ("\n\n P.No\t AT\t BT\t CT\t TAT\t WT"); 
for (complete = 0,i=0;x!=0;)
{ 

if (temp[i]<= time_quantum & & temp[i]>0)
{
complete+= temp[i];

temp[i]=0;
 count = 1;
}
else if(temp[i]>0)


{
temp[i] =temp[i]-time_quantum; 
complete +=time_quantum;
}


if (temp[i] == 0 && count == 1)

{

x--;
printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i,at[i],bt[i],complete,complete-at[i],complete - at[i]-bt[i]);
totTAT+= complete - at [i]; 
totWT+= complete-at[i]-bt[i];

count=0;
}
if (i==n-1)
{
i=0;
}
else if (at [i+1]<= complete)
{i++;
}
else
{
i=0;
}}
printf ("\n Average Turn around Time: %f", (totTAT/n)); 
printf ("\n Average waiting Time: %f \n", totWT/n);
}
