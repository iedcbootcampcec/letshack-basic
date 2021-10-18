public class Search {

   public static void main(String[] args) {
      int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
      int key = 40;

      
      int index = binarySearch(arr, 0, arr.length, key);

  
      if (index == -1)
         System.out.println(key + " not Found.");
      else
         System.out.println(key + " Found at Index = " + index);
   }

   
   public static int binarySearch(int[] arr, int low,
                           int high, int key) {
      if (high >= low) {
        
         int mid = low + (high - low) / 2; 
     
         
         if (arr[mid] == key) return mid;
     
        
         if (arr[mid] > key) 
            return binarySearch(arr, low, mid - 1, key); 
     
          
         return binarySearch(arr, mid + 1, high, key); 
      } 
     
      
      return -1; 
   }

}
