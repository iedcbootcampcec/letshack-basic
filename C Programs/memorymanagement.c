# include <stdio.h>
int bsizef[10],bsizeb[10],bsizew[10],psize[10], bno, pno;
void firstfit(int bno,int pno,int bsizef[],int psize[]);
void bestfit(int bno,int pno,int bsizeb[],int psize[]);
void worstfit(int bno,int pno,int bsizew[],int psize[]);
void main()
{
    int i, j;
	printf("Enter no:of blocks: ");
	scanf("%d", &bno);
	printf("\nEnter size of each block: ");
	for(i = 0; i < bno; i++)
	{
		scanf("%d", &bsizef[i]);
		bsizeb[i]=bsizef[i];
		bsizew[i]=bsizef[i];
	}	
	printf("\nEnter no:of processes: ");
	scanf("%d", &pno);
	printf("\nEnter size of each process: ");
	for(i = 0; i < pno; i++)
    {
		scanf("%d", &psize[i]);
    }

    printf("\nFIRST FIT MEMORY ALLOCATION");
    printf("\n----------------------------");
    firstfit(bno,pno,bsizef,psize);
    printf("\nBEST FIT MEMORY ALLOCATION");
    printf("\n----------------------------");
    bestfit(bno,pno,bsizeb,psize);
    printf("\nWORST FIT MEMORY ALLOCATION");
    printf("\n----------------------------");
    worstfit(bno,pno,bsizew,psize);
    
}
void firstfit(int bno,int pno,int bsizef[],int psize[])
{
	int i, j,allocation1[10];
	for(i = 0; i < 10; i++)
	{
		allocation1[i] = -1;
	}
	for(i = 0; i < pno; i++)  
	{
		for(j = 0; j < bno; j++)
		{
			if(bsizef[j] >= psize[i])
			{
				allocation1[i] = j;
				bsizef[j]-=psize[i];
			
				break;
			}
			
		}
	}	
	printf("\nProcess No \tProcess Size\t Block No\n");
	  
	for (i = 0; i <pno; i++)
    {
          printf("%d\t\t %d\t\t",i+1, 
                  psize[i] );
          if (allocation1[i] != -1)
            printf("  %d \n",allocation1[i] + 1);
          else
            printf("Not Allocated\n");
    }
    printf("Blocks remaining\n");
    printf("-----------------\n");
    printf("Blocks no \t size\n");
    for(int i=0;i<bno;i++)
    {
          printf("%d\t\t  %d\n",i+1,bsizef[i]);
    }
      
}

void bestfit(int bno,int pno,int bsizeb[],int psize[])
{
	int i, j,best,allocation2[10];
	for(i = 0; i < 10; i++)
	{
		allocation2[i] = -1;
	}
	for(i = 0; i < pno; i++)  
	{
	     
	    best=-1;
		for(j = 0; j < bno; j++)
		{
		    if(bsizeb[j]>=psize[i])
		    {
			   if(best==-1)
			   {
				   best=j;
			   }
			   else if(bsizeb[best]>bsizeb[j])
			   {
			      best=j; 
			   }
		    }   
			
		}
		if(best!=-1)
		{
		    allocation2[i]=best;
		    bsizeb[best]-=psize[i];
		}
		
		
	}	
	printf("\nProcess No \tProcess Size\t Block No\n");
	  
	for (i = 0; i <pno; i++)
    {
          printf("%d\t\t %d\t\t",i+1, 
                  psize[i] );
          if (allocation2[i] != -1)
            printf("  %d \n",allocation2[i] + 1);
          else
            printf("Not Allocated\n");
    }
    printf("Blocks remaining\n");
    printf("-----------------\n");
    printf("Blocks no \t size\n");
    for(i=0;i<bno;i++)
    {
          printf("%d\t\t  %d\n",i+1,bsizeb[i]);
    }
      
}


void worstfit(int bno,int pno,int bsizew[],int psize[])
{
    int i, j,worst,allocation3[10];
    for(i = 0; i < 10; i++)
	{
		allocation3[i] = -1;
	}
    for(i = 0; i < pno; i++)  
	{
	     
	    worst=-1;
		for(j = 0; j < bno; j++)
		{
		    if(bsizew[j]>=psize[i])
		    {
			   if(worst==-1)
			   {
				   worst=j;
			   }
			   else if(bsizew[worst]<bsizew[j])
			   {
			      worst=j; 
			   }
		    }   
			
		}
		if(worst!=-1)
		{
		    allocation3[i]=worst;
		    bsizew[worst]-=psize[i];
		}
		
		
	}	
	printf("\nProcess No \tProcess Size\t Block No\n");
	  
	for (i = 0; i <pno; i++)
    {
          printf("%d\t\t %d\t\t",i+1, psize[i] );
          if (allocation3[i] != -1)
            printf("  %d \n",allocation3[i] + 1);
          else
            printf("Not Allocated\n");
    }
    printf("Blocks remaining\n");
    printf("-----------------\n");
    printf("Blocks no \t size\n");
    for(i=0;i<bno;i++)
    {
          printf("%d\t\t  %d\n",i+1,bsizew[i]);
    }
      
}


