//program for fcfs
#include <stdio.h>

void main()

{

int i,j,temp,n,at[25], bt[25], ct[25], tat[25],wt[25],sum=0;

float totWT=0, totTAT=0;

printf ("Enter the no: of processer: ");

scanf ("%d", &n);

for (i=0; i<n; i++)

{ 

printf ("\n Enter arrival time of process %d:", i); 

scanf ("%d",&at[i]); 

printf ("\n Enter burst time of process %d:",i);

scanf("%d",&bt[i]);

}

//CALCULATING COMPLETION TIME 

for (i=0; i<n; i++) 

{

 sum=sum+bt[i];

 ct[i]=sum;

}

//CALCULATING TURN AROUND TIME 

for (i=0; i<n; i++)

{ tat[i]=ct[i]-at[i]; 

 totTAT+=tat[i];

}

//| CALCULATING, WAITING TIME X3 

for (i=0; i<n; i++)

{

wt[i]=tat[i]-bt[i];

totWT+=wt[i]; 

}

printf ("\n TABLE");

printf ("\n----- ");

printf ("\n\n P.No\t AT\t BT\t CT\t TAT\t WT"); 

for (i=0; i<n; i++)

{

printf ("\n P%d\t %d\t %d\t %d\t %d\t%d",i,at[i],bt[i],ct[i],tat[i],wt[i]);

}

printf ("\n Average Turn around Time: %f", (totTAT/n)); 

printf ("\n Average waiting Time: %f \n", totWT/n);

}

//return 0;

