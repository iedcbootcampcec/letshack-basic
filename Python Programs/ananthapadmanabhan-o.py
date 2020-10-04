# program to find the roots of a quadratic equation by computing the coefficients

from math import sqrt  # importing sqrt function

print('\n[------Quadratic Equation solver (ax²+bx+c=0)------]')

#user inputs of coefficients
a=int(input('\nEnter the value of a: '))
b=int(input('\nEnter the value of b: '))
c=int(input('\nEnter the value of c: '))


d= (b**2)-(4*a*c) #calcutation of Discriminent value

#The roots are calculated with respect to the value of Discriminent (d)

if d>0:
    print('\n\n[-----The equation has two real and distinct roots-----]')  #if d is greater than zero then there are two real and unequal roots 
    # formula for the roots
    root1=(-b-sqrt(d))/(2*a) 
    root2=(-b+sqrt(d))/(2*a)
    print('\n\nThe roots of the equation are ',root1,'and',root2)

elif d==0:
    print('\n\n[-----The equation has equal and real root-----]') #if the d is equal to zero then there is only one real root
    # formula for the root
    root=(-b)/(2*a)
    print('\n\nThe root of the equation is',root)

else:
    print('\n\n[-----The equation has two imaginary (complex) roots-----]') #if d is lesser than zero then there are two imaginary and unequal roots 
    #here d is negative number
    d=abs(d) # returns absolute value of d

    real = (-b)/(2*a)  #The real part of root
    imaginary = sqrt(d)/(2*a) #The imaginary part of root

    root1= str(real)+" + "+str(imaginary)+"i"  #The squar root is represented by (i)
    root2= str(real)+" - "+str(imaginary)+"i"

    print('\n\nThe roots of the equation are ',root1,'and',root2)   

print('\n\n------THANK YOU------\n')    
