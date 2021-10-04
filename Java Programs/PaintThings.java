import java.util.*;
import java.text.DecimalFormat;
//1. Shape.java - Shape
abstract class Shape{
//Instance variable shapeName of type String
    protected String shapeName;
    public Shape(String shapeName)
    {
    this.shapeName = shapeName;
    }
//Abstract method for area
    abstract double area();
//toString method that returns the name of the shape
    public String toString()
    {
        this.shapeName = shapeName;
        return shapeName;
    }
}

//2. Sphere.java - Sphere
class Sphere extends Shape{
    private double radius; //In feet
    public Sphere(double radius)
    {
        super("Sphere");
        this.radius = radius;
    }
    public double area()
    {
        return 4*Math.PI*radius*radius;
    }
}

//Rectangle
class Rectangle extends Shape{
    private double length;
    private double width;
    public Rectangle(double length, double width)
    {
        super("Rectangle");
        this.length = length;
        this.width = width;
    }
    public double area()
    {
        return length*width;
    }
}

//Cylinder
class Cylinder extends Shape{
    private double radius;
    private double height;
    public Cylinder (double radius, double height)
    {
        super("Cylinder");
        this.radius = radius;
        this.height = height;
    }
    public double area()
    {
        return Math.PI*radius*radius*height;
    }
}

//3. Paint.java
class Paint{
    private double coverage; //number of square feet per gallon
    public Paint(double coverage)
    {
        this.coverage = coverage;
    }
    double amount(Shape s)
    {
        System.out.println("Computing amount for : " + s);
        return  s.area()/coverage;
    }
}

//4. PaintThings.java
public class PaintThings{
    public static void main(String[] args) {
        final double COVERAGE = 350;
        Paint paint = new Paint(COVERAGE);
        Rectangle deck;
        Sphere bigBall;
        Cylinder tank;
        deck = new Rectangle(20,35);
        bigBall = new Sphere(15);
        tank = new Cylinder(10,30);
        System.out.println("Number of gallons of paint needed : ");
        System.out.println("----------------------------------------------------------");
        System.out.println("Deck : " + paint.amount(deck) + " gal");
        System.out.println("----------------------------------------------------------");
        System.out.println("BigBall : " + paint.amount(bigBall) + " gal");
        System.out.println("----------------------------------------------------------");
        System.out.println("Tank : " + paint.amount(tank) + " gal");
    }
}