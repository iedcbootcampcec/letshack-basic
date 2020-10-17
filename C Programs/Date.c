#include<stdio.h>
       void main()
           {
	struct date
	     {	
	        int day;
	        int mth;
	        int yr;
	      }a;
	printf("Enter day,month and year\n");
	scanf("%d%d%d",&a.day,&a.mth,&a.yr);
	printf("Today's date:\n%d/%d/%d\n",a.day,a.mth,a.yr);
	   if(a.day==31&&a.mth!=12)
	       {
	          a.day=1;
	          a.mth=a.mth+1;
	       }
	   else if(a.mth%2==0&&a.day==30)
	      {
	          a.day=1;
	          a.mth=a.mth+1;
	      }
	   else if(a.mth==2&&a.day==28&&a.yr%4!=0)
	      {
	          a.day=1;
	          a.mth=a.mth+1;
	      }
	   else if(a.day==31&&a.mth==12)
	      {
	          a.day=1;
	          a.mth=1;
	          a.yr=a.yr+1;
                      }
	   else if(a.day==29&&a.mth==2&&a.yr%4==0)
	     {
	         a.day=1;
	         a.mth=a.mth+1;
	     }
	   else
	         a.day=a.day+1;
	printf("Tomorrow's Date:\n");
	printf("%d/%d/%d",a.day,a.mth,a.yr);
          }












