import java.io.*;
public class Array
{

public static float average(int[] arr)
{
float sum=0;
for(int i=0;i<arr.length;i++)
{
sum=sum+arr[i];
}
return sum/arr.length;
}

public static int max(int[] arr)
{
int large=arr[0];
for(int i=1;i<arr.length;i++)
{
if(arr[i]>large)
{
large=arr[i];
}
}
return large;
}

public static void main(String[] args)
{
int[] arr=new int[]{5,11,15,20,25};
float avrg=average(arr);
int maximum=max(arr);
System.out.println("Average is "+avrg);
System.out.println("Maximum is "+maximum);
}
}




