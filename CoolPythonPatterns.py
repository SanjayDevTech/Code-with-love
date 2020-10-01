# What comes after the # is not seen by python. These are comments. :)

from turtle import * # imports the module turtle,
                    #* stands for all, which makes things easier

speed(0) # sets the speed of drawing to 0, which is the fastest
pencolor('white') # sets the color of the pen/lines to white
bgcolor('black') # sets the color of the background/canvas to black

x = 0 # creates a variable x with value 0
up() # lifts up the pen, so no lines are drawn

#note fd() means move forward, bk() means move back
# rt() or lt() means tilt right by a certain angle

rt(45) 
fd(90) 
rt(135) 

down() # sets down the pen, so that turtle can draw
while x < 120: # while the value of x is lesser than 120,
                #continuously do this:
    fd(200)     
    rt(61)
    fd(200)
    rt(61)
    fd(200)
    rt(61)
    fd(200)
    rt(61)
    fd(200)
    rt(61)
    fd(200)
    rt(61)

    rt(11.1111) 
    x = x+1 # adds 1 to the value of x,
            # so that it is closer to 120 after every loop

exitonclick() # When you click, turtle exits.






#code 2




from turtle import *

from random import randint # from the random module import the function randint
#like turtle it is a module, read ahead for use

speed(0)

bgcolor('black')

x = 1

while x < 400:

    r = randint(0,255) #makes variables r,g,b whose value is an integer,
    g = randint(0,255) # which is between 0 and 255. It is random, and
    b = randint(0,255) # changes every time the loop runs

    colormode(255) # this is something that is irrelevant at this point
               # check the pythondocs link at the end for more info


    pencolor(r,g,b) # changes the color of the pen to the rgb coordinates
                    # obtained by the variables r, g, b changing each time

    fd(50 + x)
    rt(90.911)


    x = x+1 

exitonclick() 






#code 3




import turtle
turtle.setup(width=600, height=500)
turtle.reset()
turtle.hideturtle()
turtle.speed(0)

turtle.bgcolor('black')

c = 0
x = 0

colors = [
#reddish colors
(1.00, 0.00, 0.00),(1.00, 0.03, 0.00),(1.00, 0.05, 0.00),(1.00, 0.07, 0.00),(1.00, 0.10, 0.00),(1.00, 0.12, 0.00),(1.00, 0.15, 0.00),(1.00, 0.17, 0.00),(1.00, 0.20, 0.00),(1.00, 0.23, 0.00),(1.00, 0.25, 0.00),(1.00, 0.28, 0.00),(1.00, 0.30, 0.00),(1.00, 0.33, 0.00),(1.00, 0.35, 0.00),(1.00, 0.38, 0.00),(1.00, 0.40, 0.00),(1.00, 0.42, 0.00),(1.00, 0.45, 0.00),(1.00, 0.47, 0.00),
#orangey colors
(1.00, 0.50, 0.00),(1.00, 0.53, 0.00),(1.00, 0.55, 0.00),(1.00, 0.57, 0.00),(1.00, 0.60, 0.00),(1.00, 0.62, 0.00),(1.00, 0.65, 0.00),(1.00, 0.68, 0.00),(1.00, 0.70, 0.00),(1.00, 0.72, 0.00),(1.00, 0.75, 0.00),(1.00, 0.78, 0.00),(1.00, 0.80, 0.00),(1.00, 0.82, 0.00),(1.00, 0.85, 0.00),(1.00, 0.88, 0.00),(1.00, 0.90, 0.00),(1.00, 0.93, 0.00),(1.00, 0.95, 0.00),(1.00, 0.97, 0.00),
#yellowy colors
(1.00, 1.00, 0.00),(0.95, 1.00, 0.00),(0.90, 1.00, 0.00),(0.85, 1.00, 0.00),(0.80, 1.00, 0.00),(0.75, 1.00, 0.00),(0.70, 1.00, 0.00),(0.65, 1.00, 0.00),(0.60, 1.00, 0.00),(0.55, 1.00, 0.00),(0.50, 1.00, 0.00),(0.45, 1.00, 0.00),(0.40, 1.00, 0.00),(0.35, 1.00, 0.00),(0.30, 1.00, 0.00),(0.25, 1.00, 0.00),(0.20, 1.00, 0.00),(0.15, 1.00, 0.00),(0.10, 1.00, 0.00),(0.05, 1.00, 0.00),
#greenish colors
(0.00, 1.00, 0.00),(0.00, 0.95, 0.05),(0.00, 0.90, 0.10),(0.00, 0.85, 0.15),(0.00, 0.80, 0.20),(0.00, 0.75, 0.25),(0.00, 0.70, 0.30),(0.00, 0.65, 0.35),(0.00, 0.60, 0.40),(0.00, 0.55, 0.45),(0.00, 0.50, 0.50),(0.00, 0.45, 0.55),(0.00, 0.40, 0.60),(0.00, 0.35, 0.65),(0.00, 0.30, 0.70),(0.00, 0.25, 0.75),(0.00, 0.20, 0.80),(0.00, 0.15, 0.85),(0.00, 0.10, 0.90),(0.00, 0.05, 0.95),
#blueish colors
(0.00, 0.00, 1.00),(0.05, 0.00, 1.00),(0.10, 0.00, 1.00),(0.15, 0.00, 1.00),(0.20, 0.00, 1.00),(0.25, 0.00, 1.00),(0.30, 0.00, 1.00),(0.35, 0.00, 1.00),(0.40, 0.00, 1.00),(0.45, 0.00, 1.00),(0.50, 0.00, 1.00),(0.55, 0.00, 1.00),(0.60, 0.00, 1.00),(0.65, 0.00, 1.00),(0.70, 0.00, 1.00),(0.75, 0.00, 1.00),(0.80, 0.00, 1.00),(0.85, 0.00, 1.00),(0.90, 0.00, 1.00),(0.95, 0.00, 1.00)
]

while x < 1000:
    idx = int(c)
    color = colors[idx]
    turtle.color(color)
    turtle.forward(x)
    turtle.right(98)
    x = x + 1
    c = c + 0.1

turtle.exitonclick()



#feel free to add your turtle codes here
