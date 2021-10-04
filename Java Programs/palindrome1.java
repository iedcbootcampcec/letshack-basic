import java.util.Scanner;

public class Palindrome {

	public static void main(String[] args) {
		int s=0,r,cpy;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number: ");
		int n=sc.nextInt();
		cpy=n;
		while(n>0)
		{
			r=n%10;
			s=(s*10)+r;
			n=n/10;
		}
		if(cpy==s)
		{
			System.out.println("It is palindrome");
		}
		else
		{
			System.out.println("It is not palindrome");
		}
	}

}
