class ParentClass
{
  public void pmethod()
  {
    System.out.println("This is parent class");
  }
}

class ChildClass extends ParentClass{
  public void cmethod()
  {
    System.out.println("This is child class");
  }
}

public class MainClass
{
  public static void main(String [] args)
  {
    ParentClass p = new ParentClass();
    ChildClass c = new ChildClass();
    p.pmethod();
    c.cmethod();
    c.pmethod();
  }
}	
