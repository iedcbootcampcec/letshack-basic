import java.util.*;
class Fibonacci{
    public static void main(String [] args){
        long prevTerm=0; 
        long currentTerm=1;
        long  nextTerm;

        Scanner sc=new Scanner(System.in);
        System.out.println("Enter boundry: ");
        int n=sc.nextInt();

        for(int i=1; i<=n; i++){

            System.out.print(prevTerm+" ");

            nextTerm=prevTerm+currentTerm;
            prevTerm=currentTerm;
            currentTerm=nextTerm;
        }
    }
}
