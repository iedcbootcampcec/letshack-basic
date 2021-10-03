#include <stdio.h>
int main()
{
  int array[100], search, c, n,p;
  int flag=0;
  printf("LINEAR SEARCH\n");
  printf("-------------\n");
  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter the elements one by one\n");

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  printf("Enter the number to be found\n");
  scanf("%d", &search);

  for (c = 0; c < n; c++)
  {
    if (array[c] == search)
    {
      p=c+1;
      flag=1;
      break;
    }
  }
  if (flag == 1)
    printf("Element found at %d th position \n",p);
    else
        printf("Element not found");

  return 0;
}
