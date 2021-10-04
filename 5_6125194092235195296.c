
//2. PROGRAM OF STF

#include <stdio.h>

int main()

{

int at [100], bt[100], proces [100], ct [100], tat [100], wt [100]; 
int n, i, j, temp, current_time=0, start_time, completed=0 ,count;
float avg_tat=0.0, avg_wt=0.0;



printf ("Enter the number of processes:");

scanf ("%d", &n);
for(i=0; i<n; i++)
{
printf ("\n Enter the arival time of process %d :", i); 
scanf ("%d", & at [i]); 
printf ("\n Enter the burst time of process %d :", i); 
scanf ("%d", & bt[i]); 
proces [i]= i; 
printf("\n");
}
for(i=0; i<n-1; i++)
{
for (j=i+1; j<n; j++) 
{ 
	if (at[i]> at [j])

	{

temp=at[i]; 
at[i] = at[j];

at[j] = temp;
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;

temp = proces [i]; 
proces [i] = proces [j];
proces[j]=temp;
}
}
}

//Scanned with CamScanne

printf ("\n\n Process\t Arival time\t Burst Time\t Completion time\t Turn Around time\t waiting Time\n\n");

while (completed <n)

{

count = 0;

for (i=completed; i<n; i++)
{
if (at[i]<= current_time)
count++;

else{

break;
}
}
if (count >1)

for (i=completed; i< (completed + count-1); i++)
{
 for(j=i+1; j<completed + count; j++)

{

if (bt[i]>bt[j])

{
temp=at[i]; 
at[i] = at[j];

at[j] = temp;
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;

temp = proces [i]; 
proces [i] = proces [j];
proces[j]=temp;

}}}


start_time = current_time; 
ct[completed]=start_time + bt [completed]; 
tat [completed]= ct [completed]-at [completed]; 
wt [completed]=tat [completed]-bt[completed]; 
current_time = ct [completed]; 
printf ("P%d\t\t%d\t\t%d\t\t%d\t\t %d\t\t %d", proces [completed], at[completed], bt[completed],ct[completed], tat [completed], wt [completed]);
printf("\n");

avg_tat+=tat [completed];
avg_wt+= wt[completed];

completed++;
}
avg_tat=avg_tat/n;

avg_wt = avg_wt/n;

printf ("Average Turn around time=%.f\n", avg_tat); 
printf ("Average waiting time = %f \n", avg_wt);

return 0;

}
