// Program for calculator
x=int(input("Enter the first number:  "))
y=int(input("Enter the second number: "))
add=x+y
substract=x-y
multiply=x*y
divide=x/y
a=int(input("Which operation: 1.add 2.substract 3.multiply 4.divide ,\n Enter the digit of the no: given to each operation\n"))
if (a==1):
    print("Result: ",add)
elif (a==2):
    print("Result: ",substract)
elif (a==3):
    print("Result: ",multiply)
elif (a==4):
    print("Result: ",divide)
else:
    print("Invalid input ")
