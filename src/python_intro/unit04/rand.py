
next_rand = 1

def rand():
    global next_rand
    next_rand = next_rand * 1103515245 + 12345
    return (next_rand // 65535) % 32768

def srand(seed):
    next_rand = seed

a = 5
b = 1
m = 16
    
def lin_rand():
    global next_rand
    next_rand = (a * next_rand + b) % m
    return next_rand

