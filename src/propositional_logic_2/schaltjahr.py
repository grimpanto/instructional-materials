def schaltjahr1(jahr):
    if jahr % 4 == 0:
        if jahr % 100 == 0: 
            if jahr % 400 == 0:
                return True
            else:
                return False
        else:
            return True
    else:
        return False


def schaltjahr2(jahr):
    if jahr % 4:
        return False
    elif jahr % 100:
        return True
    elif jahr % 400:
        return False
    else:
        return True

def schaltjahr3(jahr):
    return False if jahr % 4 else (True if jahr % 100 else (False if jahr % 400 else True))


def schaltjahr4(jahr):
    return not jahr % 4 and \
           (jahr % 100 or not jahr % 400)

for j in (3, 100, 400, 200, 800, 1000, 1001, 1200):
    print(schaltjahr1(j) == schaltjahr2(j) == schaltjahr3(j) == schaltjahr4(j))


def f(p, q):
    if p:
        if q: return p
        else: return False
    else:
        if not q: return False
        else: return True
