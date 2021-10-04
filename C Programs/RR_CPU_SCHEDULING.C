#include<stdio.h>
int main()
{
    int T[10][4],CT[10],TAT[10],WT[10],p_no;
    int BT_rm[10],count=0,tot=0,quantum;
    int total_TAT=0,total_WT=0;
    int i,j,k;
    
    printf("\n\t\tRound Robin Scheduling");
    printf("Enter number of processes: ");
    scanf("%d",&p_no);
    
    printf("Enter the arrival time and burst time:\n");
    for(i=0;i<p_no;i++)
    {
        printf("Process no:%d\n",i+1);
        scanf("%d%d",&T[i][0],&T[i][1]);
        T[i][2]=i;
        BT_rm[i]=T[i][1];
    }
    
    printf("Enter the quantum");
    scanf("%d",&quantum);


    while(count<p_no)
    {
        for(i=0;i<p_no;i++)
        {
            if(BT_rm[i]>quantum)
            {
                tot+=quantum;
                BT_rm[i]-=quantum;
            }
            
            else if(BT_rm[i]!=0)
            {
                tot+=BT_rm[i];
                BT_rm[i]=0;
                count++;
                CT[i]=tot;
                TAT[i]=CT[i]-T[i][0];
                WT[i]=TAT[i]-T[i][1];
                total_TAT+=TAT[i];
                total_WT+=WT[i];
            }
        }
    }

    printf("ProcessID\tArrival\tBurst\tCompletion\tTurn around\tWaiting\n");
    for(i=0;i<p_no;i++)
    {
        printf("%d\t\t%d\t%d\t%d\t\t%d\t\t%d\n",T[i][2],T[i][0],T[i][1],CT[i],TAT[i],WT[i]);
    }
    
    printf("Average Waiting Time= %f",total_WT*1.0/p_no);
    printf("Average Turn Around Time= %f",total_TAT*1.0/p_no);
}
