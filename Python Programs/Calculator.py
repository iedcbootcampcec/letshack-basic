operation = input("Would you like to 1: add, 2: subtract, 3: multiply, 4: divide or 5:find total of a power(enter a number): ")

if operation != 5:
  
  a = float(input("What's your first number? "))
  b = float(input("What's your second number? "))
  total = 0.0

  if operation == 1:
    total = a + b

  if operation == 2:
    total = a - b

  if operation == 3:
    total = a * b

  else: 
    total = a // b

  print ("Your answer is " + (total))

if operation == 5:

  base = input("What is your base number(no fractions, only decimals): ") 
  exp = input("What is your exponent(whole numbers only): ")
  total = 0

  base = float(base)
  exp = int(exp)
  total = float(total)

  total = base

  while exp != 1:
    total = total*base
    exp = exp - 1

  print(total)
