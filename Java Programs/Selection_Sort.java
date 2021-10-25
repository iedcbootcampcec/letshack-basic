import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int min;
        int temp;
        System.out.print("Enter The Length Of the Array :- ");
        int a =sc.nextInt();
        int[] b=new int[a];
        for(int i=0;i<a;i++)
        {
            System.out.println("Enter The "+(i+1)+"Number :- " );
            b[i]=sc.nextInt();
        }
        System.out.println("The Unsorted Array is");
        for(int e:b){
            System.out.print(e+" ");
        }
        System.out.println();
        System.out.println("The Sorted Array is :- ");
        for(int l=0;l<b.length;l++)
        {
            min=l;
            for(int j=l+1;j<b.length;j++)
            {
                if(b[l]>b[j])
                {
                    min=j;
                }
            }
            temp=b[l];
            b[l]=b[min];
            b[min]=temp;
        }
        for(int z:b)
        {
            System.out.print(z+" ");
        }
    }
}
