def sort_select(seq):
    n = len(seq)
    for i in range(n-1): # i durchlaeuft die Werte 0 bis n-2
        min = i
        for j in range(i+1,n): # j durchlaeuft die Werte i+1 bis n-1
            if seq[j] < seq[min]:
                min = j
        seq[min],seq[i] = seq[i], seq[min]
    return seq

print sort_select([15,2,43,17,4,8,47])

def sort_insert(seq):
    n = len(seq)
    for i in range(1,n): # i durchlaeuft 1 bis n-1
        j = i
        tmp = seq[i]
        while j > 0 and seq[j - 1] > tmp: # nach rechts verschieben
            seq[j] = seq[j - 1]
            j -= 1
        seq[j] = tmp # und an neuer Position einfügen
    return seq

print sort_insert([15,2,43,17,4,8,47])

def sort_shell(seq):
    n = len(seq)
    for h in [5,3,1]:
        # stelle h-sortierte Folge her
        for i in range(h, n): # i durchläuft h bis n-1
            j = i
            tmp = seq[i]
            cont = True
            while (seq[j-h] > tmp) and cont:
                seq[j] = seq[j-h] # h - Sprung nach rechts
                j -= h
                cont = j > h
            seq[j] = tmp
    return seq

print sort_shell([15,2,43,17,4,8,47])

def sort_bubble(seq):
    n = len(seq)
    while True:
        changed = False
        for i in range(n-1): # i durchläuft 0 bis n-2
            if seq[i] > seq[i+1]:
                seq[i], seq[i+1] = seq[i+1], seq[i]
                changed = True
        if not changed:
            break
    return seq

print sort_bubble([15,2,43,17,4,8,47])