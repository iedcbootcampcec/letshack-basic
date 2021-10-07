import turtle       #this module is used to implement graphics like drawing shapes 

                    
t=turtle.Turtle()
      
wd =turtle.Screen()         #used to create a screen
  
t.color("pink")               #set the colour in which you wanna see the design

t.width(3)                      #set the width of the pen

  



t.right(90)
t.forward(150)
t.back(75)

t.right(-112)
t.forward(100) 

t.right(113)
t.back(75)
t.forward(150)

#above code is the logic for drawing 'H'......

turtle.exitonclick()      #click on the screen and it will close exitonclick func is used for that purpose


