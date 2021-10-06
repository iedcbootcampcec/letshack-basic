//Program for Palindrome
package lab;

public class Palindrome
{
 public static void main(String[] args)  {
 int n=151,s=0,r,cpy;
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

/*
output:
It is palindrome
*/
