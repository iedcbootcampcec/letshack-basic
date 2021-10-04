num=int(input("Enter a number: "))
while True:
      print("\n1.Prime or not")
      print("2.Armstrong")
      print("3.Odd or even")
      print("4.Factorial")
      print("5.Exit")
      choice=int(input("Select Function : "))
      if choice==1:
        if num<=1:
          print(num," is not a prime number")
        else:
          for i in range(2,num):
            if(num%i)==0:
              print(num,"is not a prime number")
              break
          else:
              print(num,"is a prime number")

      elif choice==2:
        sum=0
        temp=num
        n=len(str(num))
        while temp>0:
          digit=temp%10
          sum+=digit**3
          temp//=10
        if sum == num:
          print(num,"is Armstrong number")
        else:
          print(num,"is not Armstrong number")

      elif choice==3:
        if (num%2)==0:
          print(num,"is even")
        else:
          print(num,"is odd")

      elif choice==4:
        result=1
        if num<0:
          print("Invalid")
        else:
          for i in range(num,0,-1):
            result = result*i
          print(f"Factorial of {num} is: {result}")

      elif choice==5:
        print("Exiting...")
        break

      else:
        print("Wrong choice")
