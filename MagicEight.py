#Madeby:Tzu-Han,Hsu
#read a file that you want as reponses of 8 ball
with open("8_ball_responses.txt","r") as myFile:
    lines1 = []
    lines2 = []
    for i in myFile:
        lines = myFile.readlines()
        for i in lines:
            lines2.append(i.strip("\n"))

import random

while True:
    user = input("Ask a question")
    rannum = random.randint(0,len(lines)-1)
    print(lines2[rannum])
