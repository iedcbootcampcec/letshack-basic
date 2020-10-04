#include <stdio.h>
int main()
{
  int p, q, r, s, matrix[10][10], transpose[10][10];
  printf("Enter the number of rows and columns of a matrix\n");
    scanf("%d%d", &p, &q);
      printf("Enter elements of the matrix\n");
  for (r = 0; r < p; r++)
      for (s = 0; s < q; s++)
            scanf("%d", &matrix[r][s]);
  for (r = 0; r < p; r++)
      for (s = 0; s < q; s++)
            transpose[s][r] = matrix[r][s];
  printf("Transpose of the matrix:\n");
  for (r = 0; r < q; r++) {
      for (s = 0; s < p; s++)
            printf("%d\t", transpose[r][s]);
                printf("\n");
                  }
  return 0;
  }
