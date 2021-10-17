def val():
    print("Output for Val")
    def pri():
        print("Output for pri")
    pri()
val()
"""Parameters"""
def fname(a,b):
    print(a+b)
fname(2,4)
def fname(a,b):
    sum=a+b
    return print(sum)
fname(2,8)
def fname(a,b):
    sum=a+b
    return sum
print(fname(2,10))
###################################

Name1="Devin"
Name2="Jagan"
def devin(change_name):
    txt="Its a {} normal name !!!!{}"
    name=change_name
    print(txt.format(Name1,name))
    def jagan(change_name):
        name=change_name
        txt="{} Its a Great Name Hahaha {}"
        print(txt.format(Name2,name))
    jagan("Cool Daaaa")
devin("Silly Boy")
#####################################
def sum(a,b):
    sum=a+b
    return sum
result=sum(a=5,b=-10)
print(result)
#####################################
"Arbiturury"
def valu(*val):
    for value in val:
        print("Hello ",value)
valu("Devin","Krian","Pramod","Dainty")
#######################################
"Keyword Arbitury"
print('\n')
def valu(**val):
    print(val)
    for key,value in val.items():
        print(key,value)
valu(a='Devin',b='Krian',c='Pramod',d='Dainty')
########################################
def fact(num):
    if num==1:
        return num
    else:
        return num*fact(num-1)
num1=int(input("enter the value"))
print(fact(num1))
#############################################
k=lambda n:n*2
print(k(20))
k=lambda a,c,d:a*c*d
print(k(1,2,3))
k=(lambda a,b,c:a+b+c)(1,2,3)
print(k)
k=lambda a,b:a if a>b else b
print(k(23,26))
s=["def","catee","dog","cow","animal","hu"]
s.sort()
print(s)
s.sort(key=lambda x:len(x))
print(s)
new=[1,2,3,4,5]
new_legend=[]
square=lambda x:x**2
for i in new:
    new_legend.append(square(i))
print(new)
print("Square Of All Values",new_legend)
