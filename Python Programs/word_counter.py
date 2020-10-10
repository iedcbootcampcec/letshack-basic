file_name=input("Enter the name of text file: ")
try:
     text=open(file_name,"rt")
     word=text.read()
     word=word.split()
     print("Number of words in text file :", len(word))
except:
     print("Please enter the correct name of text file in the directory")     
