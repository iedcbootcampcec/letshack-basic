# program for sorting an array in python
def sorter(arr):
    for i in range(len(arr)):
        for j in range(len(arr)-i-1):
            if(arr[j+1] < arr[j]):
                arr[j+1],arr[j] = arr[j],arr[j+1]
    return arr

arr1 = [5,4,3,2,1]
print(sorter(arr1))
