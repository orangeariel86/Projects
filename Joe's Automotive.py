import tkinter
import tkinter.messagebox

class GUI:

    def __init__(self):
        self.main_window = tkinter.Tk()
        
        self.cb_var1 = tkinter.IntVar()
        self.cb_var1.set(0)
        self.cb_var2 = tkinter.IntVar()
        self.cb_var2.set(0)
        self.cb_var3 = tkinter.IntVar()
        self.cb_var3.set(0)
        self.cb_var4 = tkinter.IntVar()
        self.cb_var4.set(0)
        self.cb_var5 = tkinter.IntVar()
        self.cb_var5.set(0)
        self.cb_var6 = tkinter.IntVar()
        self.cb_var6.set(0)
        self.cb_var7 = tkinter.IntVar()
        self.cb_var7.set(0)

        # Check box
        self.cb1 = tkinter.Checkbutton(self.main_window,
                                      text="Oil change—$30.00",
                                      variable=self.cb_var1)
        self.cb2 = tkinter.Checkbutton(self.main_window,
                                      text="Lube job—$20.00",
                                      variable=self.cb_var2)
        self.cb3 = tkinter.Checkbutton(self.main_window,
                                      text="Radiator flush—$40.00",
                                      variable=self.cb_var3)
        self.cb4 = tkinter.Checkbutton(self.main_window,
                                      text="Transmission flush—$100.00",
                                      variable=self.cb_var4)
        self.cb5 = tkinter.Checkbutton(self.main_window,
                                      text="Inspection—$35.00",
                                      variable=self.cb_var5)
        self.cb6 = tkinter.Checkbutton(self.main_window,
                                      text="Muffler replacement—$200.00",
                                      variable=self.cb_var6)
        self.cb7 = tkinter.Checkbutton(self.main_window,
                                      text="Tire rotation—$20.00",
                                      variable=self.cb_var7)
        
        # Ok botton
        self.ok_Btn = tkinter.Button(self.main_window,
                                     text="ok",
                                     command=self.printChk)
        self.cb1.pack()
        self.cb2.pack()
        self.cb3.pack()
        self.cb4.pack()
        self.cb5.pack()
        self.cb6.pack()
        self.cb7.pack()
        self.ok_Btn.pack()


        tkinter.mainloop()

    def printChk(self):
        myVal= self.cb_var1.get()*30 + self.cb_var2.get()*20 + self.cb_var3.get()*40 + self.cb_var4.get()*100 + self.cb_var5.get()*35 + self.cb_var6.get()*200 + self.cb_var7.get()*20
        msg = "Total: $"+ str(myVal)
        tkinter.messagebox.showinfo('Results',msg)

GUI()

