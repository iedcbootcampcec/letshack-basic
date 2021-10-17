#Function to return the sum of two numbers
def sum(x,y):
    sum=x+y 
    return sum

#Function to return the product of two numbers
def product(x,y):
    product=x*y
    return product
 
#Function to return the difference among two numbers
def difference(product,sum):
    difference=product-sum
    return difference


a=int(input("Enter first number:"))   #input first number
b=int(input("Enter second number:"))  #input second number

#find sum
c=sum(a,b)
print("\nSum of entered numbers =",c)

#find product
d=product(a,b)
print("Product of entered numbers =",d)

#find difference
e=difference(d,c)
print("Difference of product and sum of entered numbers =",e)
