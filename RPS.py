#Made by:Tzu-Han, Hsu
import turtle
import time
import random

def DrawGUI():   #FINe     
    WIDTH  = turtle.window_width()
    HEIGHT = turtle.window_height()
    LABEL_HEIGHT = int(HEIGHT*0.25)
    COMP_X = int(WIDTH*0.25)
    PLAYER_X = int(-WIDTH*0.25)
    SCORE_HEIGHT = int(HEIGHT*0.15)
    TIES_HEIGHT  = int(HEIGHT*0.35)

    #line
    turtle.pencolor('black')
    turtle.pensize(5)
    turtle.goto(0,TIES_HEIGHT)
    turtle.pendown()
    turtle.goto(0,-HEIGHT/2)
    turtle.penup()

    #turtle.pencolor('deep pink')
    #turtle.goto(0,TIES_HEIGHT)
    #turtle.write("TIES:", align="center", font=("Arial", 25, "bold"))
    
    #computer
    turtle.pencolor("red")
    turtle.goto(COMP_X,LABEL_HEIGHT)
    turtle.write("Computer", align="center", font=("Arial", 30, "bold underline"))

    #turtle.goto(COMP_X,SCORE_HEIGHT)
    #turtle.write("Score:", align="center", font=("Arial", 25, "bold"))

    #player
    turtle.pencolor("blue")
    turtle.goto(PLAYER_X,LABEL_HEIGHT)
    turtle.write("Player", align="center", font=("Arial", 30, "bold underline"))

    #turtle.goto(PLAYER_X,SCORE_HEIGHT)
    #turtle.write("Score:", align="center", font=("Arial", 25, "bold"))

    turtle.penup()
def DrawScores(playerwins,computerwins,ties):    #FINe   
    WIDTH  = turtle.window_width()
    HEIGHT = turtle.window_height()
    LABEL_HEIGHT = int(HEIGHT*0.25)
    COMP_X = int(WIDTH*0.25)
    PLAYER_X = int(-WIDTH*0.25)
    SCORE_HEIGHT = int(HEIGHT*0.15)
    TIES_HEIGHT  = int(HEIGHT*0.35)
    #Tie
    turtle.pencolor('deep pink')
    turtle.goto(0,TIES_HEIGHT)
    turtle.write("TIES:"+ties, align="center", font=("Arial", 25, "bold"))
    #playerscore
    turtle.pencolor("black")
    turtle.goto(PLAYER_X,SCORE_HEIGHT)
    turtle.write("Score:"+playerwins, align="center", font=("Arial", 25, "bold"))
    #computerscore
    turtle.pencolor("black")
    turtle.goto(COMP_X,SCORE_HEIGHT)
    turtle.write("Score:"+computerwins, align="center", font=("Arial", 25, "bold"))
    turtle.penup()
    turtle.hideturtle()
    
def DrawHand(playerhand,computerhand):
    WIDTH  = turtle.window_width()
    HEIGHT = turtle.window_height()
    LABEL_HEIGHT = int(HEIGHT*0.25)
    COMP_X = int(WIDTH*0.25)
    PLAYER_X = int(-WIDTH*0.25)
    SCORE_HEIGHT = int(HEIGHT*0.15)
    TIES_HEIGHT  = int(HEIGHT*0.35)
    turtle.penup()
    turtle.goto(PLAYER_X,SCORE_HEIGHT*-1)

    if(playerhand == 'r'): 
        turtle.pencolor('brown')
        turtle.write("ROCK", align="center", font=("Arial", 30))
    elif(playerhand == 'p'):
        turtle.pencolor('orange')
        turtle.write("PAPER", align="center", font=("Arial", 30))
    elif(playerhand == 's'):
        turtle.pencolor('medium purple')
        turtle.write("SCICCORS", align="center", font=("Arial", 30))

    turtle.goto(COMP_X,SCORE_HEIGHT*-1)
    if(computerhand == 'r'):
        turtle.pencolor('brown')
        turtle.write("ROCK", align="center", font=("Arial", 30))
    elif(computerhand == 'p'):
        turtle.pencolor('orange')
        turtle.write("PAPER", align="center", font=("Arial", 30))
    else:
        turtle.pencolor('medium purple')
        turtle.write("SCICCORS", align="center", font=("Arial", 30))

def GetplayerHand():
    playerhand = input("Enter r, p ,s: ").lower()
    legal = 0
    if (playerhand == 'r' or playerhand == 'p' or playerhand == 's'):
        legal = 1 
    while (legal == 0):
        playerhand = input("Please enter r, p ,s: ").lower()
        if (playerhand == 'r' or playerhand == 'p' or playerhand == 's'):
            legal = 1 
    return playerhand

def GetComHand():
    computerhand = random.randint(1,3)
    if (computerhand == 1):
        computerhand = 'r'
        return computerhand
    elif (computerhand == 2):
        computerhand = 'p'
        return computerhand
    else:
        computerhand = 's'
        return computerhand
    
    
    
def deter(ch, ph, tie):  #ties = 0, pw = 1, cw = 2
    if tie == 1 :
        return 0
    elif ch == 'r' and ph == 'p':
       return 1
    elif ch == 'r' and ph == 's':
        return 2
    elif ch == 'p' and ph == 'r':
        return 2
    elif ch == 'p' and ph == 's':
        return 1
    elif ch == 's' and ph == 'r':
        return 1
    elif ch == 's' and ph == 'p':
        return 2

def show():
    WIDTH  = turtle.window_width()
    HEIGHT = turtle.window_height()
    LABEL_HEIGHT = int(HEIGHT*0.25)
    COMP_X = int(WIDTH*0.25)
    PLAYER_X = int(-WIDTH*0.25)
    SCORE_HEIGHT = int(HEIGHT*0.15)
    TIES_HEIGHT  = int(HEIGHT*0.35)

    #line
    turtle.pencolor('black')
    turtle.pensize(5)
    turtle.goto(0,TIES_HEIGHT)
    turtle.pendown()
    turtle.goto(0,-HEIGHT/2)
    turtle.penup()

    turtle.pencolor('deep pink')
    turtle.goto(0,TIES_HEIGHT)
    turtle.write("TIES:0", align="center", font=("Arial", 25, "bold"))
    
    #computer
    turtle.pencolor("red")
    turtle.goto(COMP_X,LABEL_HEIGHT)
    turtle.write("Computer", align="center", font=("Arial", 30, "bold underline"))

    turtle.pencolor('black')
    turtle.goto(COMP_X,SCORE_HEIGHT)
    turtle.write("Score:0", align="center", font=("Arial", 25, "bold"))

    #player
    turtle.pencolor("blue")
    turtle.goto(PLAYER_X,LABEL_HEIGHT)
    turtle.write("Player", align="center", font=("Arial", 30, "bold underline"))

    turtle.pencolor('black')
    turtle.goto(PLAYER_X,SCORE_HEIGHT)
    turtle.write("Score:0", align="center", font=("Arial", 25, "bold"))

    turtle.penup()

def main():
    turtle.ht()
    turtle.setup(width=600, height=400, startx=0, starty=0)
    turtle.speed(0)
    ties = 0
    computerwins = 0
    playerwins = 0
    playerhand = 0
    computerhand = 0
    show()
    while True:
        ch = GetComHand()
        ph = GetplayerHand()
        if (ch == ph):
            tie = 1
        else:
            tie = 0
        dt = deter(ch, ph, tie)
        if (dt == 1):
            playerwins += 1
        elif (dt == 2):
            computerwins += 1
        else:
            ties += 1
        strT = str(ties)
        strC = str(computerwins)
        strP = str(playerwins)
        turtle.clear()
        DrawGUI()        
        DrawScores(strP,strC,strT)
        DrawHand(ph,ch)
        #keeptrack
        #updatescore
        turtle.hideturtle()



main()
