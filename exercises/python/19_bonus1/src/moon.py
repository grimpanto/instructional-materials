# @copyright 2011 Günter Kolousek

import time
import math
import os
from turtle import *


def output_state(v, s, a, t, fuel, thrust):
    clear()
    write("Geschwindigkeit: {:7}m/s\nHöhe: {:7}m\nTreibstoffvorrat: {:3}L\n"
          "Schub: {}".format (round(v), round(s), round(fuel), thrust))


def switchon_thrust():
    global thrust
    global fuel

    if fuel < 0.1:
        fuel = 0
        thrust = 0
    elif fuel < 100:
        thrust = fuel / 100
    else:
        thrust = 1


def switchoff_thrust():
    global thrust

    thrust = 0


def quit():
    print("exit")
    os.abort()


def init_turtle():
    screen = getscreen()
    penup()
    hideturtle()
    fillcolor("white")
    tracer(0)

    screen.onkey(switchon_thrust, "1")
    screen.onkey(switchoff_thrust, "0")
    screen.onkey(quit, "q")
    screen.listen()


init_turtle()

v0 = 1000
s0 = 50000

t = 0
thrust = 0
fuel = 10000

delta_t = 0.1

while True:
    time.sleep(delta_t)

    a = 1.63 - thrust * 13.63
    fuel = fuel - thrust * 100 * delta_t
    v = v0 + a * delta_t
    s = s0 - v0 * delta_t - a / 2 * delta_t ** 2

    if s <= 0:
        t1_1 = -v0 / a + math.sqrt((v0 / a) ** 2 + 2 * s0 / a)
        t1_2 = -v0 / a - math.sqrt((v0 / a) ** 2 + 2 * s0 / a)

        if t1_1 <= delta_t:
            t1 = t1_1
        else:
            t1 = t1_2

        v1 = v0 + t1 * a

        print("t1:", t1)
        print("v1:", v1)

        if v1 >= 10:
            print("s: 0")
            print("v: {} => Booom!".format(v1))
        else:
            print("Ship landed")
        break

    output_state(v, s, a, t, fuel, thrust)

    v0 = v
    s0 = s
    t = t + delta_t
