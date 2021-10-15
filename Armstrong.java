
package lab;

public class Armstrong
{
public static void main(String[] args) {
 int s=0,r,temp;
 int n=153;
 temp=n;
 while(n!=0)
 {
   r=n%10;
   s+=(r*r*r);
   n=n/10;
 }
   if(s==temp)
   {
     System.out.println("The given number is armstrong");
   }
   else
   {
	   System.out.println("The given number is not armstrong");
   }
}

}

/*
output:
The given number is armstrong
*/
