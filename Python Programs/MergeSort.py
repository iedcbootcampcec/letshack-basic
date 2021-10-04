def mergeSort(arr):
    if len(arr) > 1:
  
         # Finding the middle element of the array
        mid = len(arr)//2
  
        # Divide the array elements into two halves
        L = arr[:mid]
        R = arr[mid:]
  
        # Sort the first half recursively
        mergeSort(L)
  
        # Sort the second half recursively
        mergeSort(R)
  
        i = j = k = 0
  
        # Sorting the elements
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
  
        # Check if any element left
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
  
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
  

# Function to print out array
def printList(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()


# Driver Code
if __name__ == '__main__':
    print()
    arr = [16, 11, 13, 5, 27, 7, 2]
    print("Given array: ")
    printList(arr)

    mergeSort(arr)
    print("Sorted array: ")
    printList(arr)
