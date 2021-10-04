package second;
import java.io.*;
import java.util.*;
class Parent
{
	int n;
	Scanner sc=new Scanner(System.in);
	void read()
	{
		System.out.println("factors upto which number needed:");
		n=sc.nextInt();
	}
}
class Child extends Parent
{
	int num=0,i;
	void factors()
	{
		if(n<=0)
		{
	       System.out.println("invalid input!");
		}
		else if(n==1)
		{
			System.out.println("Factors of 1 are:"+" "+n);
		}
		else
		{
			System.out.println("factors of 1 are :1");
			for(i=2;i<=n;i++)
			{
				System.out.println("Factors of "+" "+i+" "+"are:");
				System.out.println("1");
				for(num=2;num<=i;num++)
				{
					if(i%num==0)
					{
						System.out.println(num);
					}
				}
			}
		}
	}
	
}
class Sample1
{
	public static void main(String[]args)
	{
		Child obj=new Child();
		obj.read();
		obj.factors();
	}
}
