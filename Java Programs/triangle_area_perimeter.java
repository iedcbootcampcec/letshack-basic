import java.io.*; 
class Triangle
{
  int x,y,z;
  double Area()
  {
    double ar = (x+y+z)/2;
    return Math.sqrt(s*(s-x)(s-y)(s-z));
  }
  int Perimeter()
  {
    return (x+y+z);
  }
}

class Calculate{
  public static void main(String [] args)
  {
    Triangle T = new Triangle();
    T.x = 1;
    T.y = 2;
    T.z = 3;
    System.out.println(T.Area());
    System.out.println(T.Perimeter());
  }
}	
