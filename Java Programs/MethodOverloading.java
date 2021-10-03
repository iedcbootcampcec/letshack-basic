import java.util.*;
class Overload
{
    void calculateArea(int a , int b)
    {
        System.out.println("Area of the triangle: "+a*b/2+" sq units");
    }
    void calculateArea(double x, double y)
    {
        System.out.println("Area of the rectangle: "+x*y+" sq units");
    }
    void calculateArea(double r)
    {
        double area = 3.14*r*r;
        System.out.println("Area of the circle: "+area+" sq units");
    }
}
     class Area{
    public static void main(String args[]){
        int n1, n2;
        float n3, n4;
        Overload obj = new Overload();
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the options ");
        System.out.println("1. Triangle \n 2. Reactangle \n 3. Circle");
        int choice = scan.nextInt();
        switch(choice)
        {
            case 1: n1=scan.nextInt();
                n2=scan.nextInt();
                obj.calculateArea(n1,n2);
            break;

            case 2: n3= scan.nextDouble();
                n4= scan.nextDouble();
                obj.calculateArea(n3,n4);
            break;
              
            case 3: n3= scan.nextDouble();
                obj.calculateArea(n3);
            break;
         }
}
