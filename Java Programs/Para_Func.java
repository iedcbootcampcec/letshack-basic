public class Para_Func{
  public static void main(String args[]){
    sayHello("john");
    int sum=add(10,20);
    int result=sum*10;
    System.out.print(result);
  }
  public static void sayHello(String name){
    System.out.println("Hello"+" "+name);
  }
  public static int add(int a,int b){
      System.out.println(a+b);
      return (a+b);
  }

}
