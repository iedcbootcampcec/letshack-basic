import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int a = scan.nextInt();
        int b = scan.nextInt();
        int value=0;
        if(n>=-100 && n<=100)
        if(n==1)
             value=a+b;
        else if(n==2)
            value=a-b;
        else if(n==3)
            value=a*b;
        else if(n==4)
            if(b==0)
            { System.out.println("Error");
              System.exit(0);}
        else 
        { System.out.println("Option not found");
          System.exit(0);}
        System.out.println(value);
            
    }
}
