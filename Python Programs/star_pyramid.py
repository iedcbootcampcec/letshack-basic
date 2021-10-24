k=1
i=1
for i in range(9):
    x=1
    for i in range(9-i):
        print(" ",end=" ")
        x+=1
    j=1
    for j in range(k):
        print("*",end=" ")
        j+=1
    k+=2
    print()
    i+=1
