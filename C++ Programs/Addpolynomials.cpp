#include<stdio.h>
#include<stdlib.h>
struct node1
{
    int coeff,exp;
    struct node1 *link;
};

typedef struct node1 node;

void newnode(int a,int b,node *temp)
{
    temp->coeff=a;
    temp->exp=b;
    temp->link=NULL;
}

void main()
{
    node *pheader,*qheader,*rheader,*pptr,*qptr,*rptr,*new;
    pheader = (node*)malloc(sizeof(node));
    newnode(0,0,pheader);
    qheader = (node*)malloc(sizeof(node));
    newnode(0,0,qheader);
    rheader = (node*)malloc(sizeof(node));
    newnode(0,0,rheader);
    pptr = (node*)malloc(sizeof(node));
    newnode(0,0,pptr);
    qptr = (node*)malloc(sizeof(node));
    newnode(0,0,qptr);
    rptr = (node*)malloc(sizeof(node));
    newnode(0,0,rptr);
    int np,nq,c,e,i;
    pptr=pheader;
    qptr=qheader;
    
    printf("\nEnter the order of P:\t");
    scanf("%d",&np);
    printf("\nEnter the elements of P in the form - coefficient,exponent\n");
    for(i=0;i<=np;i++)
    { 
      new = (node*)malloc(sizeof(node));
      newnode(0,0,new);
      scanf("%d",&c);
      scanf("%d",&e);
      new->coeff=c;
      new->exp=e;
      pptr->link=new;
      pptr=pptr->link;   
    }
    pptr->link=NULL;
    
    printf("\nEnter the order of Q:\t");
    scanf("%d",&nq);
    printf("\nEnter the elements of Q in the form - coefficient,exponent\n");
    for(i=0;i<=nq;i++)
    { 
      new = (node*)malloc(sizeof(node));
      newnode(0,0,new);
      scanf("%d",&c);
      scanf("%d",&e);
      new->coeff=c;
      new->exp=e;
      qptr->link=new;
      qptr=qptr->link;
    }
    qptr->link=NULL;
   
    pptr = pheader->link;

    printf("\nP:\n");
    while(1)
    {
     if(pptr->link==NULL){ printf(" %dx^%d \n",pptr->coeff,pptr->exp);break; }
     else printf(" %dx^%d +",pptr->coeff,pptr->exp);
     pptr=pptr->link;
    }
    
    qptr = qheader->link;
    
    printf("\nQ:\n");
    while(1)
    {
     if(qptr->link==NULL){ printf(" %dx^%d \n",qptr->coeff,qptr->exp);break; }
     else printf(" %dx^%d +",qptr->coeff,qptr->exp);
     qptr=qptr->link;
    } 
    
    pptr=pheader->link;
    qptr=qheader->link;
    rptr=rheader;
    
    while(pptr!=NULL && qptr!=NULL)
    {
     new = (node*)malloc(sizeof(node));
     newnode(0,0,new);
     if(new == NULL) { printf("\nMemory Underflow\n");break; }
     else if(pptr->exp == qptr->exp)
     {
        new->coeff=pptr->coeff+qptr->coeff;
        new->exp=pptr->exp;
        rptr->link=new;
        rptr=rptr->link;
        pptr=pptr->link;
        qptr=qptr->link;
     }
     else if(pptr->exp > qptr->exp)
     {
        new->coeff=pptr->coeff;
        new->exp=pptr->exp;
        new->link=NULL;
        rptr->link=new;
        rptr=rptr->link;
        pptr=pptr->link;
     }
     else
     {
        new->coeff=qptr->coeff;
        new->exp=qptr->exp;
        new->link=NULL;
        rptr->link=new;
        rptr=rptr->link;
        qptr=qptr->link;
     }
    }
    
    while(pptr!=NULL)
    {   new = (node*)malloc(sizeof(node));
        newnode(0,0,new);
        new->coeff=pptr->coeff;
        new->exp=pptr->exp;
        new->link=NULL;
        rptr->link=new;
        rptr=rptr->link;
        pptr=pptr->link;
    }
    
    while(qptr!=NULL)
    {   new = (node*)malloc(sizeof(node));
        newnode(0,0,new);
        new->coeff=qptr->coeff;
        new->exp=qptr->exp;
        new->link=NULL;
        rptr->link=new;
        rptr=rptr->link;
        qptr=qptr->link;
    }
    rptr->link=NULL;
    
    printf("\nR:\n");
    rptr=rheader->link;
    while(1)
    {
     if(rptr->link==NULL){ printf(" %dx^%d \n",rptr->coeff,rptr->exp);break; }
     else printf(" %dx^%d +",rptr->coeff,rptr->exp);
     rptr=rptr->link;
    }
     
 }
