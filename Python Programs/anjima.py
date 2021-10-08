#program tofind the reverse of string
def string_reverse(str1):
    return str1[::-1]   #pythonic way of finding reverse of a string using list slicing

mystring=input("Enter a String:")
print("The Reverse is:"+string_reverse(mystring))
