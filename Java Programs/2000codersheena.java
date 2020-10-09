import java.util.Scanner;
public class Multiply_Recursion 
{
    public static void main(String[] args) 
    {
        int[] a = new int[2];
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the first number:");
        a[0] = s.nextInt();
        System.out.print("Enter the second number:");
        a[1] = s.nextInt();
        Multiply_Recursion obj = new Multiply_Recursion();
        int mul = obj.multiply(a,0);
        System.out.println("Answer:"+mul);
    } 
   int multiply(int x[], int i)
    {
        if(i < 2)
        {
            return x[i] * multiply(x, ++i);
        }
        else
        {
            return 1;
        }
    }
}
