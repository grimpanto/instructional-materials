def process(delta, z0, F, e):
    z = z0
    for e in e:
        z = delta(z, e)
        if not z:
            break  # kein Zustandsuebergang!
    else:  # Eingabewort zur Gaenze gelesen!
        if z in F:
            return True
    return False

def delta(z, e):
    if z == "A" and e == "a":
        z = "A"
    elif z == "A" and e == "b":
        z = "B"
    elif z == "B" and e == "b":
        z = "B"
    elif z == "B" and e == "a":
        z = "A"
    else:
        z = None     
    return z

print(process(delta, "A", {"B"}, "aab"))
print(process(delta, "A", {"B"}, "aa"))
print(process(delta, "A", {"B"}, "aac"))