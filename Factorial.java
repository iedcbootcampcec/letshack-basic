package lab;

public class Factorial 
{
  public static void main(String args[])
    {
        int i,n=3,f=1;
        for(i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                f*=j;
            }
            System.out.println("The Factorial of "+i+" is: "+f);
            f=1;
        }
    }
}


/*
output:
The Factorial of 1 is: 1
The Factorial of 2 is: 2
The Factorial of 3 is: 6
*/