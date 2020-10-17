import java.util.*;
class calender
{
    int isLeap(int y) //function to check for leap year and return max days
    {
        if((y%400 == 0) || (y%100 != 0 && y%4 == 0))
            return 366;
        else
            return 365;
    }
 
    String postfix(int n) //function to find postfix of the number
    {
        int r = n%10;
        if(r == 1 && n != 11)
            return "ST";
        else if(r == 2 && n != 12)
            return "ND";
        else if(r == 3 && n != 13)
            return "RD";
        else
            return "TH";
    }
 
    void findDate(int d, int y) //function to find the date from day number
    {
        int D[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String MO[] = {"", "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY",
                          "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
        if(isLeap(y)==366)
        {
            D[2] = 29;
        }
        int m = 1;
        while(d > D[m])
        {
            d = d - D[m];
            m++;
        }
        System.out.println(d+postfix(d)+" "+MO[m]+", "+y);
    }
     
    void future(int d, int y, int n) //function to find future date
    {
        int max = isLeap(y);
        d = d + n;
        if(d>max)
        {
            d = d - max;
            y++; 
        }
        findDate(d,y); 
    }
     
    public static void main(String args[])
    {
        ISC2019_Q1 ob = new ISC2019_Q1();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the day number : ");
        int day = sc.nextInt();
        System.out.print("Enter the year : ");
        int year = sc.nextInt();
        int max = ob.isLeap(year);
        if(day > max)
        {
            System.out.println("DAY NUMBER OUT OF RANGE");
        }
        else if(year<1000 || year>9999)
        {
            System.out.println("YEAR OUT OF RANGE");
        }
        else
        {
            System.out.print("Enter the number of days after : ");
            int n = sc.nextInt();
            if(n<1 || n>100)
            {
                System.out.println("DATE AFTER (N DAYS) OUT OF RANGE");
            }
            else
            {
                System.out.print("DATE :\t\t\t");
                ob.findDate(day,year);
                System.out.print("DATE AFTER "+n+" DAYS :\t");
                ob.future(day,year,n);
            }
        }
    }       
}
