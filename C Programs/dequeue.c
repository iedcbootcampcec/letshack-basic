# include<stdio.h>
void main()
{
    int i,size,x,front=0,rear=-1,queue[50],p,q,r,s;
    printf("\nenter the size of the queue:");
    scanf("\n%d",&size);
    printf("\nINSERT ELEMENTS TO DEQUEUE AT FRONT");
    printf("\n-------------------------------------");
    printf("\nenter the no:of elements to insert:");
    scanf("%d",&p);
    for ( i = 1; i <= p; i++)
    {
        if ((front==0&&rear==size-1)||(front==rear+1))
        {
            printf("\nOverflow");
        }
        else
        {
            printf("enter %d element to insert:",i);
            scanf("%d",&x);
            if (front==-1)
            {
                front=0;
                rear=0;
                queue[front]=x;
            }
            else if (front==0)
            {
                front=size-1;
                queue[front]=x;
            }
            else
            {
                front=front-1;
            }    
              
        }   
        
    }
    printf("\nDISPLAYING AFTER INSERTING AT FRONT");
    printf("\n----------------------------------");
    if (front==-1)
    {
        printf("\n Queue is Empty");
    }
    else
    {
        printf("\nQueue elements are:");
        for ( i = 0; i <size; i++)
        {
             printf("%d",queue[i]);
             printf("\n");
        }
        
    }
    printf("\nINSERT ELEMENTS TO DEQUEUE AT REAR");
    printf("\n-------------------------------------");
    printf("\nenter the no:of elements to insert:");
    scanf("%d",&q);
    for ( i = 1; i <= q; i++)
    {
        if ((front==0&&rear==size-1)||(front==rear+1))
        {
            printf("\n Overflow");
        }
        else
        {
            printf("enter %d element to insert:",i);
            scanf("%d",&x);
            if (front==-1)
            {
                front=rear=0;
                queue[rear]=x;
            }
            
            else 
            {
                rear=rear+1;
                queue[rear]=x;
            }
            
              
        }
        
        
    }
    printf("\nDISPLAYING AFTER INSERTING AT REAR");
    printf("\n----------------------------------");
    if (front==-1)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\nQueue elements are:");
        for ( i = 0; i <size; i++)
        {
             printf("%d",queue[i]);
             printf("\n");
        }
        
    }
    printf("\nDELETE ELEMENTS FROM DEQUEUE AT FRONT");
    printf("\n-------------------------------------");
    printf("\nenter the no:of elements to delete:");
    scanf("%d",&r);
    for ( i = 1; i <= r; i++)
    {
        if (front<0||rear<front)
        {
            printf("\nUnderflow");
        }
        else
        {
            printf("\n%d element deleted is%d",i,queue[front]);
            if (front==rear)
            {    
               front=rear=-1;
            }
            else
            {
                 front++;
            }
            
        }   
        
    }
    printf("\nDISPLAYING AFTER DELETING FROM FRONT");
    printf("\n----------------------------------");
    if (front==-1)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\nQueue elements are:");
        for ( i = 0; i <size; i++)
        {
             printf("%d",queue[i]);
             printf("\n");
        }
        
    }
    printf("\nDELETE ELEMENTS FROM DEQUEUE AT REAR");
    printf("\n-------------------------------------");
    printf("\nenter the no:of elements to delete:");
    scanf("%d",&s);
    for ( i = 1; i <=s; i++)
    {
        if (front<0||rear<front)
        {
            printf("\nUnderflow");
        }
        else
        {
             printf("\n%d element deleted is%d",i,queue[rear]);
             if (front==rear)
             {
                 front=rear=-1;     
             }
             else
             {
                 rear--;
             }
                  
        }
            
    }
    printf("\nDISPLAYING AFTER DELETING FROM REAR");
    printf("\n-----------------------------------");
    if (front==-1&&rear==-1)
    {
        printf("\n Queue is empty");
    }
    else if((front<=rear)&&(front=rear)!=-1)
    {
        printf("\nQueue elements are:");
        for ( i = front; i <=rear; i++)
        {
             printf("%d",queue[i]);
             printf("\n");
        }
        
    }
    else
    {
       for(i=front;i<=size-1;i++)
       {
            printf("%d",queue[i]);
             printf("\n");

       }
       for ( i = 0; i < =rear; i++)
       {

          printf("%d",queue[i]);
             printf("\n");
       }
       

    }
    
       

}