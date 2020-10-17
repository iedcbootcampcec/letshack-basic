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
        Overload obj = new Overload();
         obj.calculateArea(5,10);
         obj.calculateArea(6.5,8.6);
         obj.calculateArea(6.1);
    }
}
