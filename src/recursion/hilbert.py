
from turtle import left, right, forward, getscreen
from turtle import speed, tracer, hideturtle, update, reset, pensize
   
def hilbert(level, angle=90):
    if level:
        right(angle)
        hilbert(level - 1, -angle)
        forward(size)
        left(angle)
        hilbert(level - 1, angle)
        forward(size)
        hilbert(level - 1, angle)
        left(angle)
        forward(size)
        hilbert(level - 1, -angle)
        right(angle)
  
speed(0)
tracer(1000,0)
hideturtle()
pensize(5)

size = 128
hilbert(1)
update()
getscreen().getcanvas().postscript(file="hilbert1.ps")

reset()
hideturtle()
pensize(4)
size = 64
hilbert(2)
update()
getscreen().getcanvas().postscript(file="hilbert2.ps")

reset()
hideturtle()
pensize(3)
size = 32
hilbert(3)
update()
getscreen().getcanvas().postscript(file="hilbert3.ps")

reset()
hideturtle()
pensize(2)
size = 16
hilbert(4)
update()
getscreen().getcanvas().postscript(file="hilbert4.ps")

reset()
hideturtle()
pensize(1)
size = 8
hilbert(5)
update()
getscreen().getcanvas().postscript(file="hilbert5.ps")



