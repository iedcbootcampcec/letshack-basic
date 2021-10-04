

#include<stdio.h>
int main()
{
int BT[10]={0}, AT[10]={0}, TAT[10]={0}, WT[10]={0}, CT[10]={0};
int n, sum=0;
float total_TAT=0, total_WT=0;
printf("\n Enter Number Of Processes: ");
scanf("%d",&n);
printf("\n Enter Arrival & Burst Time Of Each Process: \n\n");
for(int x=0;x<n;x++)
 {
   printf("Arrival time Of process[%d]: ",x);
   scanf("%d", &AT[x]);
   printf("Burst Time Of Process[%d]",x);
   scanf("\n");
 }
for(int y=0;y<n;y++)
 {
  sum+=BT[y];
  CT[y]+=sum;
 }
for(int z=0; z<n;z++)
 {
  TAT[z]=CT[z]-AT[z];
  total_TAT+=TAT[z]; 
 }
for(int z=0;z<n;z++)
 {
  WT[z]=TAT[z]-BT[z];
  total_WT+=WT[z];
 }

printf("Process \t AT \t BT \t CT \t TAT \t WT \t \n\n");

for(int x=0; x<n; x++)
 {
   printf("P %d \t %d \t %d \t %d \t %d \t %d \t \n", x, AT[x], BT[x], CT[x], TAT[x], WT[x]);
 }

printf("\n Average Turnaround Time is %f\n", total_TAT);
printf("\n Average WT is %f \n\n", total_WT);
return 0;
} 
