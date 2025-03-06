
a = (2, 1, -1, -2, -2, -1, 1, 2)
b = (1, 2, 2, 1, -1, -2, -2, -1)
n = 5
h = [[0] * n for i in range(n)]
n2 = n ** 2

cnt = 0

def print_solution(h):
    global cnt
    cnt += 1
    print("Lösung", cnt)
    for i in range(n):
        for j in range(n):
            print("{:2}".format(h[i][j]), end=" ")
        print()
    print()

    
# finde eine Lösung
def try_next(i, x, y):
    k = 0
    res = False
    # solange nicht (erfolgreich oder alle Kandidaten)
    while not res and k != 8:
        u = x + a[k]
        v = y + b[k]
        if 1 <= u <= n and 1 <= v <= n:  # zug annehmbar? - 1
            u1 = u - 1
            v1 = v - 1
            if h[u1][v1] == 0:  # zug annehmbar? - 2
                h[u1][v1] = i
                if i < n2:  # brett nicht voll
                    res = try_next(i + 1, u, v)
                    if not res:
                        h[u1][v1] = 0  # nicht erfolgreich: loeschen
                else:  # fertig => erfolgreich
                    res = True 
        k += 1
    return res


# finde alle Lösungen
def try_next(i, x, y):
    k = 0
    while k != 8: # nicht alle Kandidaten
        u = x + a[k]
        v = y + b[k]
        if 1 <= u <= n and 1 <= v <= n:  # zug annehmbar 1
            u1 = u - 1
            v1 = v - 1
            if h[u1][v1] == 0:  # zug annehmbar 2
                h[u1][v1] = i
                if i < n2:  # brett nicht voll
                    try_next(i + 1, u, v)
                else:  # eine Lösung gefunden
                    print_solution(h)
                h[u1][v1] = 0  # loeschen
        k += 1


h[0][0] = 1  # 1. Zug
res = try_next(2, 1, 1)

# Wenn nur eine Lösung gesucht wird:
if res:
    print_solution(h)
elif res == False:
    print("Keine Loesung")
