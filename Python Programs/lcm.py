#Defining a Function to find the prime factors of a given number and return them as a list
def primelist(n):
    if n<2:
        return 
    primes=[2]
    flg=True
    for i in range(3,n+1):
        for j in range(2,i):
            if i%j==0:
                flg=False
                break
        if flg:
            primes.append(i)

    return primes


#inputing the numbers
num1=int(input("Enter First Number:"))
num2=int(input("Enter Second Number:"))

#Storing values for output formating
a,b=num1,num2

#Taking the set union of the prime factors of both numbers and converting it to a list.
primes=list(set(primelist(num1)).union(set(primelist(num2))))
lcm=1
index=0

#Using prime factorisation to find the lcm
while(num1>1 and num2>1):   

    #Checking for common factors of both numbers.
    if num1%primes[index]==0 and num2%primes[index]==0:
        lcm*=primes[index]
        num1/=primes[index]
        num2/=primes[index]
    else:
        if num1%primes[index]==0:
            lcm*=primes[index]
            num1/=primes[index]
        elif num2%primes[index]==0:
            lcm*=primes[index]
            num2/=primes[index]
        else:
            index+=1

#Multiplying with leftover number
if num1>1:
    lcm*=num1
elif num2>1:
    lcm*=num2
else:
    pass

#Outputing the result
print("The LCM of {0} and {1} is {2}".format(a,b,lcm))




