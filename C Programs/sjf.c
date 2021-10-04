#include<stdio.h>
int main()
{
            int at[10],bt[10],pr[10];
            int n,i,j,temp,time=0,count,over=0,sum_wait=0,sum_turnaround=0,start;
            float avgwait,avgturn;
            printf("Enter the number of processes\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                        printf("Enter the arrival time and execution time for process %d\n",i+1);
                        scanf("%d%d",&at[i],&bt[i]);
                        pr[i]=i+1;
            }
            for(i=0;i<n-1;i++)
            {
                        for(j=i+1;j<n;j++)
                        {
                                    if(at[i]>at[j])
                                    {
                                                temp=at[i];
                                                at[i]=at[j];
                                                at[j]=temp;
                                                temp=bt[i];
                                                bt[i]=bt[j];
                                                bt[j]=temp;
                                                temp=pr[i];
                                                pr[i]=pr[j];
                                                pr[j]=temp;     
                                    }
                        
                        }
            }
            printf("\n\nProcess\t\tArrival time\t\tBurst time\t\tWaiting time\t\t\t\tTurnaround time\n\n");
            while(over<n)
            {
                        count=0;
                        for(i=over;i<n;i++)
                        {
                                    if(at[i]<=time)
                                    count++;
                                    else
                                    break;
                        }
                        if(count>1)
                        {
                                    for(i=over;i<over+count-1;i++)
                                    {
                                                for(j=i+1;j<over+count;j++)
                                                {
                                                            if(bt[i]>bt[j])
                                                            {
                                                                        temp=at[i];
                                                                        at[i]=at[j];
                                                                        at[j]=temp;
                                                                        temp=bt[i];
                                                                        bt[i]=bt[j];
                                                                        bt[j]=temp;
                                                                        temp=pr[i];
                                                                        pr[i]=pr[j];
                                                                        pr[j]=temp;     
                                                            }
                                                }                     
                                    }
                        }
                        start=time;
                        time+=bt[over];
                         printf("p[%d]\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t\t%d\n",pr[over],
                                    at[over],bt[over],time-at[over]-bt[over],time-at[over]);
                        sum_wait+=time-at[over]-bt[over];


                        sum_turnaround+=time-at[over];
                        over++;
            }
            avgwait=(float)sum_wait/(float)n;
            avgturn=(float)sum_turnaround/(float)n;
            printf("Average waiting time is %f\n",avgwait);
            printf("Average turnaround time is %f\n",avgturn);
            return 0;
}   
