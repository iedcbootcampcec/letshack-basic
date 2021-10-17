import tkinter
from math import sqrt

class standardDeviation():
    def __init__(self):
        self.root = tkinter.Tk()
        self.root.geometry('398x562')
        self.root.resizable(False, False)
        self.root.title('Standard Deviation Calculator')
        self.root.config(bg='#2c3e50')
        self.root.wm_attributes('-toolwindow', True)

        # text box for user input
        self.text = tkinter.Text(self.root, border=0, height=3, width=47, insertbackground='#1abc9c')
        self.text.grid(row=2, column=2, padx=10, pady=10)
        self.text.configure(font=('Helvetica', 11))

        # calculate button
        self.button = tkinter.Button(self.root, text='Calculate', height=2, width=10, bg='#ec6051', fg='#ffffff', border=0, command=self.standardDeviation)
        self.button.grid(row=4, column=2, pady=10)

        # label for printing steps
        self.steps = tkinter.Label(self.root, bg='#2c3e50', fg='#ffffff')
        self.steps.grid(row=6, column=2, pady=10)
        self.steps.configure(font=('Helvetica', 11))

        # label for printing result
        self.result = tkinter.Label(self.root, bg='#1abc9c', fg='#2c3e50')
        self.result.configure(font=('Helvetica', 14))

        self.root.mainloop()

    def standardDeviation(self):
        self.result.grid_forget()

        # comma seperated entry to list of float
        X = [float(i) for i in self.text.get('1.0', 'end').split(",")]

        mean = sum(X) / len(X)
        sigma = 0
        
        for i in X:
            sigma += (i - mean) * (i - mean)
        
        SD = sqrt(sigma / len(X))

        # equations and steps
        equation1 = '\nσ² = ' + 'Σ(xᵢ - μ)²\n'
        equation2 = '     N\n\n'
        step1 = '= ' + '\u0332'.join('(' + str(X[0]) + ' - ' + str(round(mean, 3)) + ')² + ... + (' + str(X[-1]) + ' - ' + str(round(mean, 3)) + ')²\n')
        division1 = '  ' + str(len(X)) + '\n\n'
        step2 = '= ' + '\u0332'.join(str(round(sigma, 2))) + '\n'
        division2 = '  ' + str(len(X)) + '\n\n'
        step3 = '= ' + str(round(SD * SD, 3)) + '\n\n\n'
        step4 = 'σ = √' + str(round(SD * SD, 3)) + '\n\n'
        step5 = '= ' + str(round(SD, 3)) + '\n\n\n'

        # print equations, steps and result
        self.steps['text'] = equation1 + equation2 + step1 + division1 + step2 + division2 + step3 + step4 + step5
        self.result.grid(row=7, column=2)
        self.result['text'] = 'Standard Deviation = ' + str(round(SD, 3))

app = standardDeviation()
