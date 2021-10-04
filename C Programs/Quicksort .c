#include<stdio.h>
void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quicksort(int arr[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(arr[i]<=arr[pivot]&&i<last)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
            swap(&arr[i],&arr[j]);
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,first,j-1);
      quicksort(arr,j+1,last);

   }
}

int main(){
   int i, count, arr[25];

   printf("Enter number of elements: ");
   scanf("%d",&count);

   printf("Enter %d elements:\n", count);
   for(i=0;i<count;i++)
      scanf("%d",&arr[i]);

   quicksort(arr,0,count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",arr[i]);
   return 0;
}
