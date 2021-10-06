#include<stdio.h>
void adjacency(int n,int x[][n]);
void printing(int n, int x[][n]);
//void push(int item,int n,int tw[n]);
void initialise(int n,int t[n]);
int top=-1;
void main()
{
int n,i,j,z,p;
printf("\nEnter number of vertices - ");
scanf("%d", &n);
int x[n+1][n+1];
adjacency(n+1,x);

printing(n+1,x);

int tw[n];
int level[n+1];
int pred[n+1];

top++;
tw[top]=1;
initialise(n+1,level);
initialise(n+1,pred);
pred[1]=0;
level[1]=0;
for(i=2;i<=n;i++)
level[i]=-1;

int c=0;
do
{
z=tw[top];
top--;  //popping
for(j=1;j<=n;j++)
{
if(x[z][j]==1)
{
p=j;
if(level[p]==-1)
{

top++;
tw[top]=p;

pred[p]=z;
level[p]=level[z]+1;
}
else
{
//print fundamental circuit
printf("\nFundamental ciruit %d is\t",++c);
int a=pred[p];
int b=z;
while(b!=a)
{
printf("%d\t",b);
b=pred[b];
}
printf("%d\t%d\t%d\t",a,p,z);
printf("\n");

}
x[z][p]=0;
x[p][z]=0;

}

}


}while(top!=-1);
printf("\nNo more vertices are left to be examined\n");
}
void adjacency(int n,int x[][n])
{
int i,i1,i2,j,e;
for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      x[i][j]=0;
printf("\nEnter the number of edges-");
scanf("%d", &e);
for(int i=1; i<=e;i++)
{
    printf("Enter the 2 vertices of edge %d - ",i);
    scanf("%d %d", &i1, &i2);
    x[i1][i2]=x[i2][i1]=1;
  }
}
void printing(int n, int x[][n])
{
int i,j;
printf("\nTHE ADJACENCY MATRIX-\n");
for(i=1;i<n;i++)
{
for(j=1;j<n;j++)
printf("%d\t",x[i][j]);
printf("\n");

}
}

void initialise(int n,int t[n])
{
int i;
for(i=0;i<n;i++)
t[i]=0;
}
