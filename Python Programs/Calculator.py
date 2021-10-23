operation = int(input("Would you like to 1: add, 2: subtract, 3: multiply, 4: divide or 5:find total of a power(enter a number): "))
total = 0

if operation == 5:

  base = input("What is your base number(no fractions, only decimals): ") 
  exp = input("What is your exponent(whole numbers only): ")

  base = float(base)
  exp = int(exp)
  total = float(total)

  total = base

  while exp != 1:
    total = total*base
    exp = exp - 1

  print(total)

else:
  
  num1 = int(input("What's your first number? "))
  num2 = int(input("What's your second number? "))
  
  if operation == 1:
    total = num1 + num2

  elif operation == 2:
    total = num1 - num2

  elif operation == 3:
    total = num1 * num2

  elif operation == 4: 
    total = num1 // num2

print ("Your answer is " + str(total))
