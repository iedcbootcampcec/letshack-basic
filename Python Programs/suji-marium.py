def sum(x,y):
    sum=x+y 
    return sum

def product(x,y):
    product=x*y
    return product
 
def difference(product,sum):
    difference=product-sum
    return difference

a=int(input("Enter first number:"))
b=int(input("Enter second number:"))

c=sum(a,b)
print("\nSum of entered numbers =",c)
d=product(a,b)
print("Product of entered numbers =",d)
e=difference(d,c)
print("Difference of product and sum of entered numbers =",e)
