#Madeby:Tzu-Han,Hsu
myFile = open("myAwesomeFile.html",'w')
myFile.write("<html>")
myFile.write("<head>")
myFile.write("</head>")

#Ask their Name
name = input("Name: ")

myFile.write("<body>")
myFile.write("  <center>")

#Disply their Name
myFile.write("  <h1>"+name+"</h1>")

myFile.write("  </center>")
myFile.write("  I am taking the following classes:<hr/")
myFile.write("  </body>")

#Ask the Number of Classes
while True:
    try:
        numOfclass = int(input("Number of Classes: "))
        break
    except:
        True

#Show the Classes
for i in range(1,numOfclass+1):
    x = input("Class Name " + str(i) +": ")#Class Name 1~...
    myFile.write("  "+x+"<hr />")
    
myFile.write("</body>")
myFile.write("</html>")
myFile.close()

