a,b=100,200
if a<b:
    print("yes A is less than B")
c=300
if a<c:
    print("yes A is less than c")
if b<c:
    print("yes b is less than c")
###############################################
print('\n')
a=11
b=10
if a>b:
    print('a is big value')
elif b==a:
    print('hii')
elif b>a:
    print('b is big value')
elif a>b:
    print('devin')
################################################
print('\n')
a=11
b=10
if a>b:
    print('a is big value')
elif b==a:
    print('hii')
elif b>a:
    print('b is big value')
else:
    print('devin')
#################################################
print('\n')
a=11
b=10
c=23
if a<b or b<c:
    print('a and b is small value')
else:
    print('c is small value')
###################################################
print('\n')
b=2
a=300
print("A") if a>b else print("B")
###################################################
b,a=2,300
print("A") if a>b else print("B")
###################################################
a=11
b=10
if a<b:
    pass
elif b==a:
    print('hi')
elif b>a:
    print('a is bigger than b')
else:
    print('sorry')
######################################################
x=111
if x>10:
    print("hiii")
    if x>200:
        pass
    elif x<200:
        print("but not above 20")
else:
    print('sorry')
#######################################################
a=int(input("enter the number:"))
if a%2==0:
    print("even")
else:
    print("odd")
