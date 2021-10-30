# Binary Sequence

# Given four integers x, y, a and b. This program determine if there exists a binary string having 0's and 1's such that the total number of subsequences equal to the sequence "01" in it is 'a' and the total number of subsequences equal to the sequence "10" in it is 'b'

# A binary string is a string made of the characters '0' and '1' only.

# Input Format

# The first line contains a single integer T, denoting the number of test cases.

# Each of the next T lines contains four integers x, y, a and b

# Output Format

# For each test case, output 'Yes' if a string with given conditions exists and 'No' otherwise.

# #########################################################################################

import sys
s = sys.stdin.read() #read all increase performance but use more memory
user_in = s.split("\n")

s=[]
c=["No","Yes"]
mis=s.append #save call to best performance
for ias in user_in:
        ias=ias.split(' ')
        try:
                x,y,a,b = map(int,ias)
                mis(c[((a+b)==(x*y))])
        except:
                pass
print("\n".join(s))