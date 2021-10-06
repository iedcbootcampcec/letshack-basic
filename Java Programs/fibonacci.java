import java.util.Scanner;

public class Fibonacci {

	public static void main(String[] args) {
      int a=0,b=0,c=1,n,i;
      System.out.println("Enter the number : " );
      Scanner sc =new Scanner(System.in);
      n=sc.nextInt();
      System.out.println("Fibonacci sequence is: ");
      for(i=1;i<=n;i++)
      {
    	  a=b;
    	  b=c;
    	  c=a+b;
     System.out.println(a+" ");
      }
	}

}
