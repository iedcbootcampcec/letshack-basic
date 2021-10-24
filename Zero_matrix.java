import java.util.*;
class Zero_matrix {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no. of rows and cols: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        int arr[][] = new int[m][n];
        int zarr[][]=new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.println("Enter val: ");
                zarr[i][j]=arr[i][j] = sc.nextInt();
            }
        }
        System.out.println("Given Matrix: ");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (arr[i][j] == 0) {
                   // System.out.println(i+" "+j);
                    if (i == 0) {
                        if (j == 0){
                            zarr[i][j + 1] = zarr[i + 1][j] = 0;
                            zarr[i][j]=arr[i][j+1]+arr[i+1][j];
                        }
                        else if (j == (n-1)){
                            zarr[i][j - 1] = zarr[i + 1][j] = 0;
                            zarr[i][j]=arr[i][j-1]+arr[i+1][j];
                        }
                        else{
                            zarr[i][j + 1] = zarr[i + 1][j] = zarr[i][j - 1] = 0;
                            zarr[i][j]=arr[i][j+1]+arr[i][j-1]+arr[i+1][j];
                        } 
                    }
                    else if (i == (m-1)) {
                        if (j == 0){
                            zarr[i][j + 1] = zarr[i - 1][j] = 0;
                            zarr[i][j]=arr[i][j+1]+arr[i-1][j];
                        }
                        else if (j == (n-1)){
                            zarr[i][j - 1] = zarr[i - 1][j] = 0;
                            zarr[i][j]=arr[i][j-1]+arr[i-1][j];
                        }
                        else{
                            zarr[i][j + 1] = zarr[i][j - 1] = zarr[i - 1][j] = 0;
                            zarr[i][j]=arr[i][j+1]+arr[i][j-1]+arr[i-1][j];
                        }
                    }
                    else {
                        if (j == 0){
                            zarr[i][j + 1] = zarr[i + 1][j]=zarr[i-1][j] = 0;
                            zarr[i][j]=arr[i][j+1]+arr[i+1][j]+arr[i-1][j];
                        }
                        else if (j == (n-1)){
                            zarr[i][j - 1] = zarr[i + 1][j]=zarr[i-1][j] = 0;
                            zarr[i][j]=arr[i][j-1]+arr[i+1][j]+arr[i-1][j];
                        }
                        else{
                            zarr[i][j + 1] = zarr[i + 1][j] = zarr[i][j - 1]=zarr[i-1][j]= 0;
                            zarr[i][j]=arr[i][j+1]+arr[i][j-1]+arr[i+1][j]+arr[i-1][j];
                        }
                    }
                }
            }
        }
        System.out.println("Zero Matrix: ");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(zarr[i][j] + " ");
            }
            System.out.println();
        }
    }
}
