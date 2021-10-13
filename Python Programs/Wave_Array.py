def wave(arr):
    size = len(arr)

    for index in range(0, size, 2):
        if(index > 0 and arr[index-1] > arr[index]):
            arr[index-1], arr[index] = arr[index], arr[index-1]

        if(index < size-1 and arr[index] < arr[index+1]):
            arr[index], arr[index+1] = arr[index+1], arr[index]

    return arr

arr = [3,5,12,2,6,10,7,9,8] 
print(wave(arr))               