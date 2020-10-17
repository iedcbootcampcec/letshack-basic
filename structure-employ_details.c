# include<stdio.h>
# include<string.h>
struct employ
{
    char name[50];
    char id[50];
    float salary;
};
void main()
{
    struct employ x[100];
    int i,n;
    printf("enter the no:of employees:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the employs name:");
        scanf("%s",x[i].name);
        printf("\n enter the employ id:");
        scanf("%s",x[i].id);
        printf("\n enter employ salary:");
        scanf("%f",&x[i].salary);
    }
    printf ("\t\t\t EMPLOY DETAILS" );
    printf("\n\n");
    printf("SI.NO\tEMPLOY NAME\tEMPLOY ID\t  SALARY\n");
    for(i=0;i<n;i++)
    {
    printf(" %d\t  %s\t\t%s\t%f\n",i+1,x[i].name,x[i].id,x[i].salary);
    }
}
