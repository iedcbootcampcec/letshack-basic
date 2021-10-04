//4. PROGRAM OF PRIORITY

#include <stdio.h> 
void main()

{ 
int n, i, t, bt [20], at [20], j, sum = 0, bt1 [20], wt[20], tat[20], p [20], pro [30], index, pr=-1, temp = -1;

float avg_wt=0, avg_tat=0; 
printf ("Enter number of processes:"); 
scanf ("%d", &n); 
for(i=0;i<n; i++)

{ printf ("\n Arrival Time of P%d=", i+1);

scanf ("%d", & at [i]);

printf ("\n Bust Time of P%d= ", i+1);

scanf ("%d", & bt[i]);

printf ("\n Priority of P%d=", i+1); 
scanf ("%d", &p[i]);

pro[i] = i;

printf ("\n");
}
for (i=0;i<n; i++) {

for(j=i+1; j<n; j++) {

if (at[i]> at [j])
{
	temp= at [i];

	at [i] = at [j];
	at [j] = temp;

	temp = bt[i];
	bt[i]=bt[j];

	bt [j] = temp;

	temp= p[i];
p[i]=p[j];
p[j] = temp;
 temp= pro [i];

pro[i]=pro[j];
pro[j] = temp;

}

} 
sum=sum+bt[i]; 
bt1[i] = bt[i]; 
wt [i]=0; 
tat[i]=0; 
if (temp<p[i])
 temp=p[i];
}
t=0;
while (t<sum) { 
pr= temp+1; 
for (i=0; i<=n; i++)
 { 
 if (bt[i]>0 && at[i]<=t)
 	if (pr>p[i]) 
 	{
 	pr=p[i]; 
 	index=i;
 	}

}

 bt[index]=0;
  wt [index] = t-at [index];
   tat [index] = wt [index]+ bt1[index];
    t = t+bt1 [index];
   }


printf ("\n Process\t Arival Time \t Burst Time \t Waiting Time \t Turnaround Time \n");

for (i=0;i<n; i++)
{

printf ("p%d\t%d\t%d\t%d\t%d\n", (pro[i]+1), at [i], bt1[i], wt[i],tat[i]);

avg_wt= avg_wt + wt[i]; 
avg_tat= avg_tat + tat[i];

}
printf ("\n Average waiting time = %f\n Average turnaround time = %f",avg_wt/n,avg_tat/n);

} 
