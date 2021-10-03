 package lab cycle;
import java.util.*;
public class Triangle
{
    public Triangle()
    {
        double perimeter,area;
        int a=3, b=4, c=5;
        perimeter = a+b+c;
        double s=perimeter/2.0;
        area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
        System.out.println("Area of triangle: "+area);
        System.out.println("Perimeter of Triangle: "+perimeter);
    }
    public static void main(String[]args){
        Triangle t = new Triangle();
    }
}