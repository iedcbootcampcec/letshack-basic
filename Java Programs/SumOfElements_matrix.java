import java.io.*;
public class SumOfElements
{
	public static void main(String[] args)
	{
		int[][] matrix={
				{5,1,7},
				{3,1,2},
				{3,4,3},
				{10,1,2},
				};
		int sum=0;
		for(int i=0;i<matrix.length;i++)
		{
			for(int j=0;j<matrix[i].length;j++)
			{
				sum+=matrix[i][j];
			}
		}
		System.out.println("Sum of elements of matrix is "+sum);
	}
}
