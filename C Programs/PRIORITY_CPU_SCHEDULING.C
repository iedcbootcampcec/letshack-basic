#include<stdio.h>
int main()
{
    int T[10][4],CT[10],TAT[10],WT[10],p_no;
    int total_TAT=0,total_WT=0,time=0;
    int i,j,k,m,count;
    
    printf("Enter number of processes: ");
    scanf("%d",&p_no);

    printf("Enter the arrival time, burst time and priority:\n");
    for(i=0;i<p_no;i++)
    {
        printf("Process ID:%d\n",i);
        T[i][2]=i;
        scanf("%d%d%d",&T[i][0],&T[i][1],&T[i][3]);
    }

    for(i=0;i<p_no;i++)
        for(j=0;j<p_no-i-1;j++)
            if(T[j][0]>T[j+1][0])
                for(k=0;k<4;k++)
                {
                    int temp=T[j][k];
                    T[j][k]=T[j+1][k];
                    T[j+1][k]=temp;
                }
  
    for(m=0;m<p_no;m++)
    {
        count=0;
        for(i=m;i<p_no && T[i][0]<=time;i++)
            count++;

        if(count>1)
            for(i=m;i<m+count-1;i++)
                for(j=i+1;j<m+count;j++)
                    if(T[i][3]>T[j][3])
                        for(k=0;k<4;k++)
                        {
                            int temp=T[j][k];
                            T[j][k]=T[i][k];
                            T[i][k]=temp;
                        }

        CT[m]=time+T[m][1];
        TAT[m]=CT[m]-T[m][0];
        WT[m]=TAT[m]-T[m][1];
        time=CT[m];
        total_TAT+=TAT[m];
        total_WT+=WT[m];
    }

    printf("ProcessID\tArrival\tBurst\tPriority\tCompletion\tTurn around\tWaiting\n");
    for(i=0;i<p_no;i++)
        printf("%d\t\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n",T[i][2],T[i][0],T[i][1],T[i][3],CT[i],TAT[i],WT[i]);

    printf("\nAverage Waiting Time= %f\n",total_WT*1.0/p_no);
    printf("Average Turn Around Time= %f",total_TAT*1.0/p_no);
}
