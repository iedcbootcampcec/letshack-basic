def empty_coord(giv):
    for q in range(0, 9, 1):
        for lo in range(0, 9, 1):
            if giv[q][lo] == 0:
                return q,lo
def rule(giv, row, coloumn, inputt):
    wx, wy, wz = 0, 0, 0
    for compare in range(0, 9, 1):
        if (inputt == giv[row][compare]) or (inputt == giv[compare][coloumn]):
            wx = 1
    rott = row // 3
    cott = coloumn // 3
    for rq in range(rott * 3, rott * 3 + 3):
        for re in range(cott * 3, cott * 3 + 3):
            if inputt == giv[rq][re]:
                wy = 1
    if wx == 1 or wy == 1:
        wz = 1
    return wz
def back_tracking(giv):
    fifi=empty_coord(giv)
    if not fifi:
        return True
    else:
        rr, yy = fifi
    for i in range(1,10,1):
        x=rule(giv,rr,yy,i)
        if x==0:
            giv[rr][yy]=i
            if back_tracking(giv)==True:
                return True
            else:
                giv[rr][yy]=0
    return False
def board(giv):
    for p1 in range(0,9,1):
        print("|",giv[p1][0],giv[p1][1],giv[p1][2],"|",giv[p1][3],giv[p1][4],giv[p1][5],"|",giv[p1][6],giv[p1][7],giv[p1][8],"|")
        if p1+1==3 or p1+1==6:
            print("-------------------------")

def input_values(giv):
    for qq1 in range(0,9,1):
        for qq2 in range(0,9,1):
            giv[qq1][qq2]=input("enter the value")


giv = [[7, 8, 0, 4, 0, 0, 1, 2, 0],
       [6, 0, 0, 0, 7, 5, 0, 0, 9],
       [0, 0, 0, 6, 0, 1, 0, 7, 8],
       [0, 0, 7, 0, 4, 0, 2, 6, 0],
       [0, 0, 1, 0, 5, 0, 9, 3, 0],
       [9, 0, 4, 0, 6, 0, 0, 0, 5],
       [0, 7, 0, 3, 0, 0, 0, 1, 2],
       [1, 2, 0, 0, 0, 7, 4, 0, 0],
       [0, 4, 9, 2, 0, 6, 0, 0, 7]]




board(giv)

back_tracking(giv)

print(" ")
print("the solved is")
print(" ")
print("-------------------------")
board(giv)
print("-------------------------")
