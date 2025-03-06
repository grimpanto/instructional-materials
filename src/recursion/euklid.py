
def slow_euklid(a, b):
    while a != b:
        if a > b:
            a = a - b
        else:
            b = b - a
    return a


def fast_euklid(a, b):
    if a < b:
        a, b = b, a
    while b > 0:
        r = a % b
        a = b
        b = r
    return a


def fast_euklid2(a, b):
    while b > 0:  # oder b != 0
        r = a % b
        a = b
        b = r
        # a, b = b, r
    return a


def fast_euklid3(a, b):
    while b:
        a, b = b, a % b
    return a


def euklid1(a, b):
    if a == b:
        return a
    elif a > b:
        return euklid1(a - b, b)
    else:
        return euklid1(b - a, a)
    

def euklid2(a, b):
    if a == 0:
        return b
    elif b == 0:
        return a
    elif a > b:
        return euklid1(a - b, b)
    else:
        return euklid1(b - a, a)


def euklid3(a, b):
    if b == 0:
        return a
    else:
        return euklid3(b, a % b)