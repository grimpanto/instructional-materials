
import time

bars = [[], [], []]
stop = False
    
# src ... von (source)
# dst ... nach (destination)
# aux ... ueber (auxiliary)
def hanoi(n, src, dst, aux):
    """Loese Tuerme von Hanoi mit n Tuermen von src nach dst ueber aux"""
    print("enter hanoi: n =", n)
    if n > 1:
        hanoi(n-1, src, aux, dst)
    print("Scheibe von", src, "nach", dst)
    if n > 1:
        hanoi(n-1, aux, dst, src)
    print("leave hanoi: n =", n)
        

def hanoi2(n, src=1, dst=2, aux=3, stopflag = False):
    global stop
    stop = stopflag
    bars[0] = range(n, 0, -1)
    bars[1] = []
    bars[2] = []
    print_towers()
    do_hanoi2(n, src, dst, aux)
    
def do_hanoi2(n, src, dst, aux):
    if n > 1:
        do_hanoi2(n-1, src, aux, dst)
    if stop:
        input("")
    print("Scheibe von %s nach %s:" % (src, dst))
    bars[dst-1].append(bars[src-1].pop())
    print_towers()
    if n > 1:
        do_hanoi2(n-1, aux, dst, src)
        
def print_towers():
    max_len = max(len(bars[0]), len(bars[1]), len(bars[2]))
    i = max_len
    while i > 0:
        if len(bars[0]) >= i:
            print(bars[0][i-1], end="")
        else:
            print(" ", end="")
        if len(bars[1]) >= i:
            print(bars[1][i-1], end="")
        else:
            print(" ", end="")
        if len(bars[2]) >= i:
            print(bars[2][i-1])
        else:
            print(" ")
        i-=1
    print
    
