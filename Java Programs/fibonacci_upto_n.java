import java.util.*;
class javafibonacci
{
	public static void main(String[] args)	
	{
		int i,n1=0,n2=1,n3;
		Scanner ip=new Scanner(System.in);
		System.out.println("Enter the number of terms:");
		int n=ip.nextInt();
		System.out.println("Fibonacci Series :");
		for(i=0;i<n;i++)
		{
			System.out.println(n1);
			n3=n1+n2;
			n1=n2;
			n2=n3;
		}
	}
}
