import java.util.Scanner;



public class calculator {
    public static void main(String[] args) {
        System.out.println("Cases:\n 1- Addition\n 2- Subtraction\n 3- Multiplication\n 4- Division");
        Scanner x = new Scanner(System.in);
        int n= x.nextInt();
        System.out.println("Enter the numbers");
        
        int a= x.nextInt();
        
        int b = x.nextInt();
        switch (n){
            case 1:
            System.out.println((a+b));
            break;
            case 2:
            System.out.println((a-b));
            break;
            case 3:
            System.out.println((a*b));
            break;
            case 4:
            System.out.println((a/b));
            break;
            default :
            System.out.println("Option not found");
        }


    }
}
