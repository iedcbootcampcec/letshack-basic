/*Program to  accept and print details of normal and covid19 patients in hospital*/ 
#include<stdio.h>
struct covid19
{
    char name[50];
    int age;
    char sex[10];
} s1[100];
struct normal
{
    char name[50];
    int age;
    char sex[10];
} s2[100];
void main()
{
    int i,n1,n2;
  //Collecting details of covid19 patients
    printf("Enter number of covid19 patients\n");
    scanf("%d",&n1);
    for(i=0; i<n1; i++)
    {
        printf("Enter the name,age and sex of covid19 patient %d\n",i+1);
        scanf("%s%d%s",s1[i].name,&s1[i].age,s1[i].sex);
    }
  //Collecting details of normal patients
    printf("Enter number of normal patients\n");
    scanf("%d",&n2);
    for(i=0; i<n2; i++)
    {
        printf("Enter the name,age and sex of normal patient %d\n",i+1);
        scanf("%s%d%s",s2[i].name,&s2[i].age,s2[i].sex);
    }
  //Displaying details of covid19 patients
    printf("Details of covid19 patients\n..........................\n");
    for(i=0; i<n1; i++)
    {
        printf("Patient %d\n---------\nName  :  %s\nAge   :  %d\nSex   :  %s\n",i+1,s1[i].name,s1[i].age,s1[i].sex);
    }
   //Displaying details of normal patients
    printf("Details of normal patients\n...........................\n");
    for(i=0; i<n2; i++)
    {
        printf("Patient %d\n---------\nName  :  %s\nAge   :  %d\nSex   :  %s\n",i+1,s2[i].name,s2[i].age,s2[i].sex);
    }
}
