# Python 3 implementation of above approach 

# Recursive function that returns 1 if 
# palindrome, 0 if not palindrome 
def palindrome(arr, begin, end): 

	# base case 
	if (begin >= end) : 
		return 1
	
	if (arr[begin] == arr[end]) : 
		return palindrome(arr, begin + 1, 
								end - 1) 
	
	else : 
		return 0

# Driver code 
if __name__ == "__main__": 
	a = [ 3, 6, 0, 6, 3 ] 
	n = len(a) 

	if (palindrome(a, 0, n - 1) == 1): 
		print("Palindrome") 
	else: 
		print("Not Palindrome")
