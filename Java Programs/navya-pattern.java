import java.util.*;
public class Pattern
{  
    public static void pyramid(int n) 
    {  
        for (int i=0; i<n; i++) 
            { 
                System.out.print(" ");
            }  
            for (int j=0; j<=i; j++ ) 
            { 
                System.out.print("* "); 
            } 
  
            System.out.println();
        } 
    } 
  
    public static void main(String args[]) 
    { 
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); 
        pyramid(n); 
    } 
}
