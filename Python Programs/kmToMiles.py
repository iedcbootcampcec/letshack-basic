def kmToMiles():
  #taking input from user
  kilometres=float(input("Enter the distance in kilometres:"))

  #conversion factor
  con_fact=0.621371

  miles=con_fact*kilometres

  print("%0.2f kilometres is equal to %0.2f miles"%(kilometres,miles))
