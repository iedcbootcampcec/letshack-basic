
//To show  single inheritance
class singleinherit
   {
    public static void main(String args[])
     {
     testclass1 objectname= new testclass1();
     objectname.methodname();
     objectname.methodname1();
     }
   }
 class testclass //final class
{
 int a=5;
 void methodname() 
   {
    System.out.println("hello"+a);
    }
}
class testclass1 extends testclass
{
int b=10;
 void methodname1() 
   {
    System.out.println("hello"+b);
    }
}
