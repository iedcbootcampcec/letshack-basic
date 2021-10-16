//trapping rain water program
class Main{

public static int maxWater(int[] arr, int n)
{

    int result = 0;

    for(int i = 1; i < n - 1; i++)
    {

        int l = arr[i];
        for(int j = 0; j < i; j++)
        {
            l = Math.max(l, arr[j]);
        }

        int r = arr[i];
        for(int j = i + 1; j < n; j++)
        {
            r = Math.max(r, arr[j]);
        }

        result += Math.min(l, r) - arr[i];
    }
    return result;
}

public static void main(String[] args)
{
    int[] arr = { 3,0,2,0,4 };
    int n = arr.length;
 
    System.out.print(maxWater(arr,n));
}
}
