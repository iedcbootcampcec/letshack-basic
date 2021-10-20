#include <stdio.h>
#define MAX 100

int sum(int arr[], int start, int len);

int main()
{
    int arr[MAX];
    int N, i, sumofarray;
    printf("Enter size of the array: ");
    scanf("%d", &N);
    printf("Enter elements in the array: \n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    sumofarray = sum(arr, 0, N);
    printf("Sum of array elements: %d", sumofarray);

    return 0;
}
int sum(int arr[], int start, int len)
{
    if (start >= len)
        return 0;

    return (arr[start] + sum(arr, start + 1, len));
}
