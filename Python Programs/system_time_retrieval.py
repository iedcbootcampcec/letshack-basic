#System time retrieval

from tkinter import *

from time import *

window=Tk()
window.title("System time")
window.geometry('150x70')

def time():
    str=strftime('%H:%M:%S %p')
    label.config(text=str)
    label.after(1000,time)

label=Label(window,background='#599AC0',padx=10,pady=10,height=50,width=50)

label.pack(anchor="center")
time()

window.mainloop()