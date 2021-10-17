import mysql.connector as a
import tabulate as t


# Connect
def Connect():
    try:
        x = a.connect(host="localhost", user="root", passwd='', database='VKV')
        return x
    except:
        print("Server Offline")
        print()
        b1()
        menu()


def b1():
    for i in range(70):
        print("=", end='')
    print("\n")


def b2():
    for i in range(70):
        print("_", end='')
    print('\n')


def sshow(x):  # Student Show
    print("Python Successfully connected to the database")
    c = x.cursor()
    c.execute('select * from student')
    f = [('  Name  ', '  Class  ', '  Roll No.  ', '  Address  ', '  Phone Number  ')]
    for i in c:
        f.append(i)
    print(t.tabulate(f, headers="firstrow", tablefmt="pretty"))
    print()
    b1()
    menu()


def sushow(x):  # Student Show
    print("Python Successfully connected to the database")
    c = x.cursor()
    c.execute('select * from student')
    f = [('  Name  ', '  Class  ', '  Roll No.  ', '  Address  ', '  Phone Number  ')]
    for i in c:
        f.append(i)
    print(t.tabulate(f, headers="firstrow", tablefmt="pretty"))
    print()
    b1()


def sins(x):  # Student Insert
    global s
    print("Python Successfully connected to the database")
    c = x.cursor()
    p = 1
    l = []
    while p == 1:
        na = input("Enter Student's Name : ")
        nb = input("Enter Student's Class : ")
        nc = input("Enter Student's Roll No : ")
        nd = input("Enter Student's Address : ")
        ne = input("Enter Student's Phone : ")
        t = (na, nb, nc, nd, ne)
        l.append(t)
        p = int(input('To enter more record press 1 else press 0:'))
        s = "INSERT INTO Student VALUES (%s, %s, %s, %s, %s)"
    c.executemany(s, l)
    x.commit()
    print(c.rowcount, "records successfully inserted \n")


def sirun():  # Student Insert Run
    try:
        x = Connect()
        if x.is_connected():
            sins(x)
            d = int(input('To view the final Data press 1 else press 0:'))
            print('\n\n')
            if d == 1:
                sshow(x)
                print()
                b1()
                menu()
            else:
                print()
                b1()
                menu()
        else:
            print('Access to the database is denied.Please Check the connection')
            print()
            b1()
            menu()
    except:
        print('Please Check the connection')
        print()
        b1()
        menu()


def sdlt(x):
    print("Python Successfully connected to the database \n")
    u = int(input("Do you want to view record ?\n (press 1 to view Record else press 0) : "))
    if u == 1:
        sushow(x)
    c = x.cursor()
    print('Which Record do you want to Delete?\n')
    n = input("Enter Class of the record to be deleted :")
    n1 = input('Enter Roll Number of the record to be deleted :')
    print('\n\n')
    s1 = "Select * From STUDENT WHERE class =" + n + " And roll = " + n1
    c.execute(s1)
    f = [('  Name  ', '  Class  ', '  Roll No.  ', '  Address  ', '  Phone Number  ')]
    for i in c:
        f.append(i)
    print(t.tabulate(f, headers="firstrow", tablefmt="pretty"))
    print('\n')
    z = int(input(
        "Are you Sure you want to delete this record ? \n Press 1 to Confirm (This cannot be undone) \n Else press 0 to end process:"))
    if z == 1:
        s = "Delete From STUDENT WHERE class =" + n + " And roll = " + n1
        c.execute(s)
        x.commit()
        print("Record is successfully deleted")
    else:
        print()
        b1()
        menu()


def sdrun():
    x = Connect()
    if x.is_connected():
        sdlt(x)
        d = int(input('To view the final Data press 1 else press 0:'))
        print('\n')
        if d == 1:
            sshow(x)
        else:
            print()
            b1()
            menu()
    else:
        print('Access to the database is denied.Please Check the connection')
        print()
        b1()
        menu()


def supt(x):
    print("Python Successfully connected to the database \n")
    u = int(input("Do you want to view record ?\n (press 1 to view Record else press 0) : "))
    if u == 1:
        sushow(x)
    c = x.cursor()
    w = int(input(
        "Which Data do you want to update?\n 1.Name \n 2.Class \n 3. Roll No. \n 4. Address \n 5. Phone \n Enter your choice :"))

    if w == 1:
        n2 = input("Enter Roll No whose record is to be changed:")
        n = input("Enter Class whose record is to be changed:")
        n3 = input("Enter New Name:")
        s = "UPDATE STUDENT SET name = '" + n3 + "' WHERE class =" + n + " And roll = " + n2
        c.execute(s)
        x.commit()
        print("Record is successfully updated")

    if w == 2:
        b1 = input("Enter Roll Number whose record is to be changed:")
        b = input('Enter Class Which is to be changed:')
        b3 = input("Enter New Class:")
        s = "UPDATE STUDENT SET class =" + b3 + " WHERE class = " + b + " And roll =" + b1
        c.execute(s)
        x.commit()
        print("Record is successfully updated")

    if w == 3:
        m = input('Enter Roll Number Whose record is to be changed:')
        m1 = input("Enter Class whose record is to be changed:")
        m3 = input("Enter New Roll no:")
        s = "UPDATE STUDENT SET roll = " + m3 + " WHERE class = " + m1 + " And roll = " + m
        c.execute(s)
        x.commit()
        print("Record is successfully updated")

    if w == 4:
        m = input('Enter Roll No. Whose record is to be changed:')
        m1 = input("Enter Class whose record is to be changed:")
        m3 = input("Enter New Address:")
        s = "UPDATE STUDENT SET address =' " + m3 + "' WHERE class = " + m1 + " And roll = " + m
        c.execute(s)
        x.commit()
        print("Record is successfully updated")

    if w == 5:
        m = input('Enter Roll Number Which is to be changed:')
        m1 = input("Enter Class whose record is to be changed:")
        m3 = input("Enter New Phone:")
        s = "UPDATE STUDENT SET phone = " + m3 + " WHERE class = " + m1 + " And roll = " + m
        c.execute(s)
        x.commit()
        print("Record is successfully updated")


def surun():
    x = Connect()
    if x.is_connected():
        supt(x)
        d = int(input('To view the final Data press 1 else press 0:'))
        print('\n')
        if d == 1:
            sshow(x)
        else:
            print()
            b1()
            menu()
    else:
        print('Access to the database is denied.Please Check the connection')
        print()
        b1()
        menu()


def tshow(x):  # Teacher Show
    print("Python Successfully connected to the database")
    c = x.cursor()
    c.execute('select * from teacher')
    f = [('  Name  ', '  Post  ', '  Salary  ', '  Address  ', '  Phone  ', '  Account Id  ')]
    for i in c:
        f.append(i)
    print(t.tabulate(f, headers="firstrow", tablefmt="pretty"))
    print()
    b1()
    menu()


def tushow(x):  # Teacher Show
    print("Python Successfully connected to the database")
    c = x.cursor()
    c.execute('select * from teacher')
    f = [('  Name  ', '  Post  ', '  Salary  ', '  Address  ', '  Phone  ', '  Account Id  ')]
    for i in c:
        f.append(i)
    print(t.tabulate(f, headers="firstrow", tablefmt="pretty"))


def tins(x):  # teacher Insert
    global s
    print("Python Successfully connected to the database")
    c = x.cursor()
    p = 1
    l = []
    while p == 1:
        na = input("Enter Teachers's Name : ")
        nb = input("Enter Post : ")
        nc = input("Enter Salary : ")
        nd = input("Enter Address : ")
        ne = input("Enter Phone : ")
        nf = input("Enter Account Id : ")
        t = (na, nb, nc, nd, ne, nf)
        l.append(t)
        p = int(input('To enter more record press 1 else press 0:'))
        s = "INSERT INTO teacher VALUES (%s, %s, %s, %s, %s, %s)"
    c.executemany(s, l)
    x.commit()
    print(c.rowcount, "records successfully inserted \n")


def tirun():  # teacher Insert Run
    try:
        x = Connect()
        if x.is_connected():
            tins(x)
            d = int(input('To view the final Data press 1 else press 0:'))
            print('\n\n')
            if d == 1:
                tshow(x)
            else:
                print()
                b1()
                menu()
        else:
            print('Access to the database is denied.Please Check the connection')
            print()
            b1()
            menu()
    except:
        print('Please Check the connection')
        print()
        b1()
        menu()


def tdlt(x):
    print("Python Successfully connected to the database \n")
    u = int(input("Do you want to view record ?\n (press 1 to view Record else press 0) : "))
    if u == 1:
        tushow(x)
    c = x.cursor()
    print('Which Record do you want to Delete?\n')
    n1 = input('Enter Account id of the record to be deleted :')
    print('\n\n')
    s1 = "Select * From teacher WHERE account_id =" + n1
    c.execute(s1)
    f = [('  Name  ', '  Post  ', '  Salary  ', '  Address  ', '  Phone  ', '  Account Id  ')]
    for i in c:
        f.append(i)
    print(t.tabulate(f, headers="firstrow", tablefmt="pretty"))
    print('\n')
    z = int(input(
        "Are you Sure you want to delete this record ? \n Press 1 to Confirm (This cannot be undone) \n Else press 0 to end process:"))
    if z == 1:
        s = "Delete From teacher WHERE account_id =" + n1
        c.execute(s)
        x.commit()
        print("Record is successfully deleted")
    else:
        print()
        b1()
        menu()


def tdrun():
    x = Connect()
    if x.is_connected():
        tdlt(x)
        d = int(input('To view the final Data press 1 else press 0:'))
        print('\n')
        if d == 1:
            tshow(x)
        else:
            print()
            b1()
            menu()
    else:
        print('Access to the database is denied.Please Check the connection')
        print()
        b1()
        menu()


def tupt(x):
    print("Python Successfully connected to the database \n")
    u = int(input("Do you want to view record ?\n (press 1 to view Record else press 0) : "))
    if u == 1:
        tushow(x)
    c = x.cursor()
    w = int(input(
        "Which Data do you want to update?\n 1.Name \n 2.Post \n 3. Salary \n 4. Address \n 5. Phone \n Enter your choice :"))
    if w == 1:
        n2 = input("Enter Account Id whose record is to be changed:")
        n3 = input("Enter New Name:")
        s = "UPDATE Teacher SET name = '" + n3 + "' WHERE account_id =" + n2
        c.execute(s)
        x.commit()
        print("Record is successfully updated")
    if w == 2:
        n2 = input("Enter Account Id whose record is to be changed:")
        n3 = input("Enter New Post:")
        s = "UPDATE Teacher SET post = '" + n3 + "' WHERE account_id =" + n2
        c.execute(s)
        x.commit()
        print("Record is successfully updated")
    if w == 3:
        n2 = input("Enter Account Id whose record is to be changed:")
        n3 = input("Enter New Salary")
        s = "UPDATE Teacher SET salary = " + n3 + " WHERE account_id =" + n2
        c.execute(s)
        x.commit()
        print("Record is successfully updated")

    if w == 4:
        n2 = input("Enter Account Id whose record is to be changed:")
        n3 = input("Enter New Address:")
        s = "UPDATE Teacher SET address = '" + n3 + "' WHERE account_id =" + n2
        c.execute(s)
        x.commit()
        print("Record is successfully updated")

    if w == 5:
        n2 = input("Enter Account Id whose record is to be changed:")
        n3 = input("Enter New Phone:")
        s = "UPDATE Teacher SET phone = " + n3 + " WHERE account_id =" + n2
        c.execute(s)
        x.commit()
        print("Record is successfully updated")


def turun():
    x = Connect()
    if x.is_connected():
        tupt(x)
        d = int(input('To view the final Data press 1 else press 0:'))
        print('\n')
        if d == 1:
            tshow(x)
        else:
            print()
            b1()
            menu()
    else:
        print('Access to the database is denied.Please Check the connection')
        print()
        b1()
        menu()


def satins(x):  # Student Insert
    print("Python Successfully connected to the database")
    c = x.cursor()
    nx = input("Class:")
    na = input("Date (yyyy-mm-dd) : ")
    nb = input("Number of Absent Students : ")
    s = "INSERT INTO S_attendance VALUES( \"{}\" ,{},{})".format(na, nx, nb)
    c.execute(s)
    x.commit()
    print(c.rowcount, "records successfully inserted \n")


def satrun():  # Student Insert Run
    try:
        x = Connect()
        if x.is_connected():
            satins(x)
            print()
            b1()
            menu()
        else:
            print('Access to the database is denied.Please Check the connection')
            print()
            b1()
            menu()
    except:
        print('Please Check the connection')
        print()
        b1()
        menu()


def tatins(x):  # Student Insert
    print("Python Successfully connected to the database")
    c = x.cursor()
    na = input("Date (yyyy-mm-dd) : ")
    nb = input("Number of Absent Teacher : ")
    s = "INSERT INTO T_attendance VALUES(\"{}\",{})".format(na, nb)
    print(s)
    c.execute(s)
    x.commit()
    print(c.rowcount, "records successfully inserted \n")


def tatrun():  # Student Insert Run
    try:
        x = Connect()
        if x.is_connected():
            tatins(x)
        else:
            print('Access to the database is denied.Please Check the connection')
            print()
            b1()
            menu()
    except:
        print('Please Check the connection')
        print()
        b1()
        menu()


def feeins(x):  # Student Insert
    print("Python Successfully connected to the database")
    c = x.cursor()
    na = input("Student Name :")
    nb = input("Class  : ")
    nc = input("Roll No.:")
    nd = input("Month and Year (mmyyyy):")
    ne = input("Fees:")
    nf = input("Date(yyyy-mm-dd):")
    s = "INSERT INTO fee VALUES('{}',{},{},{},{},\"{}\")".format(na, nb, nc, nd, ne, nf)
    c.execute(s)
    x.commit()
    print(c.rowcount, "records successfully inserted \n")


def feerun():  # Student Insert Run
    try:
        x = Connect()
        if x.is_connected():
            feeins(x)
        else:
            print('Access to the database is denied.Please Check the connection')
            print()
            b1()
            menu()
    except:
        print('Please Check the connection')
        print()
        b1()
        menu()


def salains(x):  # Student Insert
    print("Python Successfully connected to the database")
    c = x.cursor()
    na = input("Teacher Name :")
    nb = input("Month(mm): ")
    nc = input("Year (yyyy):")
    nd = input("Paid (0 or 1):")
    s = "INSERT INTO salary VALUES('{}',{},{},{})".format(na, nb, nc, nd)
    c.execute(s)
    x.commit()
    print(c.rowcount, "records successfully inserted \n")


def salarun():  # Student Insert Run
    try:
        x = Connect()
        if x.is_connected():
            salains(x)
        else:
            print('Access to the database is denied.Please Check the connection')
            print()
            b1()
            menu()
    except:
        print('Please Check the connection')
        print()
        b1()
        menu()


def csshow(x):  # Student Show
    print("Python Successfully connected to the database")
    c = x.cursor()
    cs = input("Enter Class:")
    c.execute('select * from student where class = {}'.format(cs))
    f = [('  Name  ', '  Class  ', '  Roll No.  ', '  Address  ', '  Phone Number  ')]
    for i in c:
        f.append(i)
    print(t.tabulate(f, headers="firstrow", tablefmt="pretty"))
    print()
    b1()
    menu()


def tshow(x):  # Student Show
    print("Python Successfully connected to the database")
    c = x.cursor()
    c.execute('select * from teacher')
    f = [('  Name  ', '  Post  ', '  Salary  ', '  Address  ', '  Phone  ', '  Account Id  ')]
    for i in c:
        f.append(i)
    print(t.tabulate(f, headers="firstrow", tablefmt="pretty"))
    print()
    b1()
    menu()


def ext():
    l = int(input("Are you sure you want to exit? \n Press 1 to Exit or 0 to go back to main menu "))
    if l == 1:
        exit(0)
    else:
        menu()


def menu():
    try:
        Connect()
        print('\033[0m \033[94m \n 1. Add Student \t\t\t 2. Remove Student \n 3. Update Student '
              '\t\t\t 4. Add Teacher \n 5. Remove Teacher \t\t\t 6. Update Teacher \n'
              ' 7. Class Attendance \t\t 8. Teacher Attendance \n 9. Submit Fees \t\t\t 10. Salary Details\n'
              ' 11. Display Students \t\t 12. Teachers List \n\t\t \t\t\t 13. Exit'
              ' \n   \n \033[0m')
        x = int(input('\033[91mEnter Your Choice : \033[0m'))
        if x == 1:
            sirun()
        if x == 2:
            sdrun()
        if x == 3:
            surun()
        if x == 4:
            tirun()
        if x == 5:
            tdrun()
        if x == 6:
            turun()
        if x == 7:
            satrun()
        if x == 8:
            tatrun()
        if x == 9:
            feerun()
        if x == 10:
            salarun()
        if x == 11:
            x = Connect()
            csshow(x)
        if x == 12:
            x = Connect()
            tshow(x)
        if x == 13:
            pass

        else:
            print("Please enter Correct value.")
            b1()
            print()
            menu()
    except:
        print("There is some error in your input. Please try again")
        b1()
        menu()

print('\t\t\t\t\033[1m \033[92m \033[4m Vivekananda Kendra Vidyalaya')
lst = []
b1()
menu()
