public class factorial  {

    public static void main(String[] args) {
        int a=5;
        sample a1 = new sample();
        a1.factor(a);
        a1.sqr(a);
        
        
    }
}
 class sample {
     void factor(int x) {
        int i,f;
        f=1;
        for (i=1;i<=x;i++)
        {
            f = f * i;
        }
        System.out.println("Factorial is :"+f);

        
    }
    void sqr(int x){
        int a;
        a=x*x;
        System.out.println("Square is :"+a);
    }
}