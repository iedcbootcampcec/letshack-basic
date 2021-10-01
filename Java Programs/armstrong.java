import java.util.Scanner;

public class Armstrong {

	public static void main(String[] args) {
	int s=0,r,n,n1;
	System.out.println("Enter the number:");
	Scanner sc = new Scanner(System.in);
	n=sc.nextInt();
	n1=n;
	while(n!=0)
	{
		r=n%10;
		s+=(r*r*r);
		n=n/10;
	}
   if(s==n1)
   {
	   System.out.println("The given number is armstrong");
   }
   else
   {
	   System.out.println("The given number is not armstrong");
   }
	}

}
