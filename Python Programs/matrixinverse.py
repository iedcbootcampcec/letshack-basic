#if numpy is not installed use pip install numpy
#importing numpy
import numpy as np

#inputing rows and column size
size=int(input("Enter the size of square matrix:"))

#initializing empty list.
mat=[]

#inputing the elements
for i in range(0,size):
    elm=[]
    for j in range(0,size):
        k=int(input("Enter Element:"))
        elm.append(k)

    mat.append(elm)

#converting the list to numpy array
matarr=np.array(mat)

#Displaying the given matrix
print("The given matrix is:",matarr)

#checking whether the determinant is zero or not.If it is not zero,print the inverse of the matrix.
if np.linalg.det(matarr)==0:
    print('Inverse doesnot exist')
else:
    print('The Inverse is:',np.linalg.inv(matarr))