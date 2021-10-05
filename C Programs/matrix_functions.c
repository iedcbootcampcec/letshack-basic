#include <stdio.h>

int read_matrix(int x,int y,int z[x][y]){
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            printf("Enter the values : ");
            scanf("%d",&z[i][j]);
        }
    } 
    return z[x][y];  
}

void display_matrix(int p , int q , int r[p][q]){
    for (int i=0;i<p;i++){
        for (int j=0;j<q;j++){
            printf("%d ",r[i][j]);
        }
        printf("\n");
    }
    
}

void matrix_addition(int row,int column,int mat_1[row][column],int mat_2[row][column]){
    int added[row][column];
    for (int i=0;i<row;i++){
        for (int j=0;j<column;j++){
            added[i][j]=mat_1[i][j]+mat_2[i][j];
        }
    }
    printf("\nThe added matrix is \n");
    display_matrix(row,column,added);

}

void matrix_multiplication(int row,int column,int column_1,int mat_1[row][column],int mat_2[row][column]){
    int multiplied[row][column];
    for (int i=0;i<row;i++){
        for (int j=0;j<column_1;j++){
            multiplied[i][j] = 0;
            for (int k=0;k<column;k++)
                multiplied[i][j] += (mat_1[i][k])*(mat_2[k][j]);
        }
    }
    printf("\nThe Multiplied matrix is \n");
    display_matrix(row,column,multiplied);

}

void matrix_transpose(int row,int column,int mat[row][column]){
    int transposed[row][column];
    for (int i=0;i<row;i++){
        for (int j=0;j<column;j++){
            transposed[j][i]=mat[i][j];
        }
    }
    printf("\nThe Transposed matrix is \n");
    display_matrix(row,column,transposed);
}

void main(){
    int a;
    
    printf("1. Matrix Addition  2.Matrix Multiplication  3.Transpose of matrix \n");
    printf("Enter a Choice (1,2,3) :");
    scanf("%d",&a);

    if (a==1 || a==2){
        int row,column,row_1,column_1;

        printf("Enter the dimensions of 1st matrix [row column] : ");
        scanf("%d %d",&row,&column);

        int mat_1[row][column];
        printf("Enter the values of 1st matrix \n");
        mat_1[row][column]=read_matrix(row,column,mat_1);

        printf("Enter the dimensions of 2nd matrix [row column] : ");
        scanf("%d %d",&row_1,&column_1);

        int mat_2[row_1][column_1];
        printf("Enter the values of 2nd matrix \n");
        mat_2[row_1][column_1]=read_matrix(row_1,column_1,mat_2);

        if (a==1){
            if (row==row_1 && column==column_1)
                matrix_addition(row,column,mat_1,mat_2);
        }
        if (a==2){
            if (column==row_1)
            matrix_multiplication(row,column,column_1,mat_1,mat_2);
        }
    }
    if (a==3){
        int row,column;

        printf("Enter the dimensions of matrices [row column] : ");
        scanf("%d %d",&row,&column);

        int mat[row][column];

        printf("Enter the values of matrix \n");
        mat[row][column]=read_matrix(row,column,mat);
        printf("\nThe Given matrix is \n");
        display_matrix(row,column,mat);
        matrix_transpose(row,column,mat);
    }  
}