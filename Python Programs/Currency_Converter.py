import tkinter as tk
from tkinter import *
import tkinter.messagebox
import urllib.parse
import requests

root = tk.Tk() 

root.title("Currency Conversion")

Tops = Frame(root,bg = '#663300',pady = 2, width =1850, height = 100, relief = "ridge")
Tops.grid(row=0,column=0)

headlabel = tk.Label(Tops,font=('lato black', 19,'bold'), text = '      Real-Time   ', bg= '#0352fc',fg='white') 
headlabel.grid(row=1, column=0,sticky=W,)
headlabel = tk.Label(Tops,font=('lato black', 19,'bold'), text = '      Currency   ', bg= '#0352fc',fg='white') 
headlabel.grid(row=1, column=1,sticky=W)
headlabel = tk.Label(Tops,font=('lato black', 19,'bold'), text = '      Converter  ',padx=4, bg= '#0352fc',fg='white') 
headlabel.grid(row=1, column=2,sticky=W)
headlabel = tk.Label(Tops,font=('lato black', 19,'bold'), text = '          ', bg='#0352fc')
headlabel.grid(row=1, column=3, sticky=W)
variable1 = tk.StringVar(root) 
variable2 = tk.StringVar(root) 
 
variable1.set("currency") 
variable2.set("currency") 
def RealTimeCurrencyConversion(): 
    
    from_currency = variable1.get() 
    to_currency = variable2.get()

    main_url='https://www.alphavantage.co/query?function=CURRENCY_EXCHANGE_RATE'
    url=main_url+"&from_currency="+from_currency+"&to_currency="+to_currency+"&apikey=ZOPMN0ZOLCHC2LJ7"
    json_data=requests.get(url).json()
    
    if (Amount1_field.get()==""):
        tkinter.messagebox.showinfo("Error !!","Amount Not Entered.\n Please enter a valid amount.")
        
    elif (from_currency=="currency" or to_currency=="currency"):
        tkinter.messagebox.showinfo("Error !!","Currency Not Selected.\n Please select FROM and TO Currency from menu.")
        
    else:
        Exchange_Rate=float(json_data['Realtime Currency Exchange Rate']['5. Exchange Rate'])
        new_amt=Exchange_Rate*float(Amount1_field.get())
        new_amount=float("{:.2f}".format(new_amt))
        Amount2_field.insert(0, str(new_amount)) 

def clear_all() : 
	Amount1_field.delete(0, tk.END) 
	Amount2_field.delete(0, tk.END)

CurrenyCode_list = ["INR", "USD", "CAD", "CNY", "DKK", "EUR"]


root.configure(background = '#e6e5e5') 
root.geometry("640x400") 

Label_1 =Label(root, font=('lato black', 27,'bold'), text="",padx=2,pady=2, bg="#e6e5e5",fg ="black")
Label_1.grid(row=1, column=0,sticky=W)


label1 = tk.Label(root,font=('lato black', 15,'bold'), text = "\t    Amount  :  ", bg="#e6e5e5",fg = "black") 
label1.grid(row=2, column=0,sticky=W)

label1 = tk.Label(root,font=('lato black', 15,'bold'), text = "\t    From Currency  :  ", bg="#e6e5e5",fg = "black") 
label1.grid(row=3, column=0,sticky=W)

label1 = tk.Label(root,font=('lato black', 15,'bold'), text = "\t    To Currency  :  ", bg="#e6e5e5",fg = "black") 
label1.grid(row=4, column=0,sticky=W)

label1 = tk.Label(root,font=('lato black', 15,'bold'), text = "\t    Converted Amount  :  ", bg="#e6e5e5",fg = "black") 
label1.grid(row=8, column=0,sticky=W)


Label_1 =Label(root, font=('lato black', 7,'bold'), text="",padx=2,pady=2, bg="#e6e5e5",fg ="black")
Label_1.grid(row=5, column=0,sticky=W)

Label_1 =Label(root, font=('lato black', 7,'bold'), text="",padx=2,pady=2, bg="#e6e5e5",fg ="black")
Label_1.grid(row=7, column=0,sticky=W)



FromCurrency_option = tk.OptionMenu(root, variable1, *CurrenyCode_list) 
ToCurrency_option = tk.OptionMenu(root, variable2, *CurrenyCode_list) 

FromCurrency_option.grid(row = 3, column = 0, ipadx = 45,sticky=E) 
ToCurrency_option.grid(row = 4, column = 0, ipadx = 45,sticky=E) 




Amount1_field = tk.Entry(root) 
Amount1_field.grid(row=2,column=0,ipadx =28,sticky=E)

Amount2_field = tk.Entry(root)
Amount2_field.grid(row=8,column=0,ipadx =31,sticky=E) 




Label_9 =Button(root, font=('arial', 15,'bold'), text="   Convert  ",padx=2,pady=2, bg="blue",fg = "white",command=RealTimeCurrencyConversion)
Label_9.grid(row=6, column=0)

Label_1 =Label(root, font=('lato black', 7,'bold'), text="",padx=2,pady=2, bg="#e6e5e5",fg ="black")
Label_1.grid(row=9, column=0,sticky=W)

Label_9 =Button(root, font=('arial', 15,'bold'), text="   Clear All  ",padx=2,pady=2, bg="white",fg = "red",command=clear_all)
Label_9.grid(row=10, column=0)


root.mainloop()
