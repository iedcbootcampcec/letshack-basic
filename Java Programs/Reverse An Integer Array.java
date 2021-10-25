import java.util.*;
public class Main {
    public void Reverse(){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter The Length Of Array :- ");
        int a =sc.nextInt();
        int[] b=new int[a];
        for(int i=0;i<a;i++)
        {
            System.out.println("Enter The "+(i+1)+" Value :- ");
            b[i]=sc.nextInt();
        }
        for(int x:b)
        {
            System.out.print(x+" , ");

        }
        System.out.println();
        int[] c =new int[a];
        for(int i=0;i<a;i++)
        {
            c[i]=b[a-i-1];
        }
        for(int j:c){
            System.out.print(j+" , ");
        }
    }

    public static void main(String[] args) {
        Main obj=new Main();
        obj.Reverse();

    }
}
