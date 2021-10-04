//C program to find the mode of a list of numbers. 
//Mode of a list of numbers is the number that occurs most frequently in the list.
#include <stdio.h>

int mode(int x[], int c) 
{

    int l = x[0];
    int i;
    for (i = 1; i < c; i++) //to find the largest number in the list
    {
        if (x[i] > l)
            l = x[i];
    }
    int t = l + 1;

    int counts[t]; //array to store the count of each number in the list
    int ctr;
    for (i = 0; i < t; i++)
    {
        counts[i] = 0;
    }

    for (i = 0; i < c; i++)
    {

        counts[x[i]]++;
    }

    int k = counts[0];
    int mode;
    for (i = 1; i < t; i++) //to find the number with maximum occurence in the list based on the count
    {

        if (counts[i] > k)
        {

            k = counts[i];
            mode = i;
        }
    }

    return mode;
}

int main()
{
    int i, N, A[50];
    printf("Enter the number of elements in the list:  ");
    scanf("%d", &N);
    printf("Enter the elements in the list:\n");
     for (i = 0; i < N; i++)
       {
            scanf("%d", &A[i]);
        }
        printf("Mode of the given list of numbers is %d\n", mode(A, N));
        
   
}
