import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
	    Scanner sc=new Scanner(System.in);
        System.out.print("Enter The String :- ");
        String a=sc.nextLine();
        String b="";
        for(int i=a.length()-1;i>=0;i--)
        {
            b=b+a.charAt(i);
        }
        if(a.equalsIgnoreCase(b))
        {
            System.out.println("The Entered String is Pallindrome");
        }
        else
        {
            System.out.println("The Entered String is not Pallindrome");
        }
    }
}