# @copyright 2011 Günter Kolousek

def sort1(a, b, c):
    if a <= b <= c:
        return a, b, c
    elif a <= c <= b:
        return a, c, b
    elif b <= a <= c:
        return b, a, c
    elif b <= c <= a:
        return b, c, a
    elif c <= a <= b:
        return c, a, b
    else:
        return c, b, a


def sort2(seq):
    if seq[0] <= seq[1]:
        if seq[1] <= seq[2]:
            return seq[0], seq[1], seq[2]
        else:
            return seq[0], seq[2], seq[1]
    elif seq[1] <= seq[0]:
        if seq[0] <= seq[2]:
            return seq[1], seq[0], seq[2]
        else:
            return seq[1], seq[2], seq[0]
    else:
        if seq[0] <= seq[1]:
            return seq[2], seq[0], seq[1]
        else:
            return seq[2], seq[1], seq[0]


def bubble1(lst):
    for x in range(len(lst) - 1):
        for y in range(len(lst) - 1):
            if lst[y] > lst[y + 1]:
                lst[y + 1], lst[y] = lst[y], lst[y + 1]
    return lst


def bubble2(lst):
    for top in range(len(lst) - 1, 0, -1):
        for y in range(0, top):
            if lst[y] > lst[y + 1]:
                lst[y + 1], lst[y] = lst[y], lst[y + 1]
    return lst


def bubble3(lst):
    for top in range(len(lst) - 1, 0, -1):
        changed = False
        for y in range(0, top):
            if lst[y] > lst[y + 1]:
                lst[y + 1], lst[y] = lst[y], lst[y + 1]
                changed = True
        if not changed:
            break
    return lst


def selection(lst):
    for start in range(len(lst) - 1):
        min = start
        for i in range(start + 1, len(lst)):
            if lst[i] < lst[min]:
                min = i
        if min != start:
            lst[min], lst[start] = lst[start], lst[min]
    return lst


def selection2(lst):
    res = []
    while lst:
        min = lst[0]
        min_idx = 0
        i = 1
        for x in lst[1:]:
            if x < min:
                min = x
                min_idx = i
            i += 1
        res.append(min)
        del lst[min_idx]
    return res


if __name__ == "__main__":
    import time
    import random
    import copy

    lst1 = [random.randint(0, 1000) for x in range(1000)]
    lst1_1 = copy.copy(lst1)
    lst1_2 = copy.copy(lst1)
    lst1_3 = copy.copy(lst1)
    lst1_4 = list(range(1000))
    lst1_5 = copy.copy(lst1)
    lst1_5a = copy.copy(lst1)
    lst1_6 = list(range(1000))

    t1_1 = time.time()
    bubble1(lst1_1)
    t1_2 = time.time()
    bubble2(lst1_2)
    t1_3 = time.time()
    bubble3(lst1_3)
    t1_4 = time.time()
    bubble3(lst1_4)
    t1_5 = time.time()
    selection(lst1_5)
    t1_5a = time.time()
    selection2(lst1_5a)
    t1_6 = time.time()
    selection(lst1_6)
    t1_7 = time.time()

    print("1000 Elemente")
    print("bubble1: {}s".format(t1_2 - t1_1))
    print("bubble2: {}s".format(t1_3 - t1_2))
    print("bubble3: {}s".format(t1_4 - t1_3))
    print("bubble3/sortiert: {}s".format(t1_5 - t1_4))
    print("selection: {}s".format(t1_5a - t1_5))
    print("selection2: {}s".format(t1_6 - t1_5a))
    print("selection/sortiert: {}s".format(t1_7 - t1_6))

    lst2 = [random.randint(0, 2000) for x in range(2000)]
    lst2_1 = copy.copy(lst2)
    lst2_2 = copy.copy(lst2)
    lst2_3 = copy.copy(lst2)
    lst2_4 = list(range(2000))
    lst2_5 = copy.copy(lst2)
    lst2_5a = copy.copy(lst2)
    lst2_6 = list(range(2000))

    t2_1 = time.time()
    bubble1(lst2_1)
    t2_2 = time.time()
    bubble2(lst2_2)
    t2_3 = time.time()
    bubble3(lst2_3)
    t2_4 = time.time()
    bubble3(lst2_4)
    t2_5 = time.time()
    selection(lst2_5)
    t2_5a = time.time()
    selection2(lst2_5a)
    t2_6 = time.time()
    selection(lst2_6)
    t2_7 = time.time()

    print()
    print("2000 Elemente")
    print("bubble1: {}s".format(t2_2 - t2_1))
    print("bubble2: {}s".format(t2_3 - t2_2))
    print("bubble3: {}s".format(t2_4 - t2_3))
    print("bubble3/sortiert: {}s".format(t2_5 - t2_4))
    print("selection: {}s".format(t2_5a - t2_5))
    print("selection2: {}s".format(t2_6 - t2_5a))
    print("selection/sortiert: {}s".format(t2_7 - t2_6))

    lst4 = [random.randint(0, 4000) for x in range(4000)]
    lst4_1 = copy.copy(lst4)
    lst4_2 = copy.copy(lst4)
    lst4_3 = copy.copy(lst4)
    lst4_4 = list(range(4000))
    lst4_5 = copy.copy(lst4)
    lst4_5a = copy.copy(lst4)
    lst4_6 = list(range(4000))

    t4_1 = time.time()
    bubble1(lst4_1)
    t4_2 = time.time()
    bubble2(lst4_2)
    t4_3 = time.time()
    bubble3(lst4_3)
    t4_4 = time.time()
    bubble3(lst4_4)
    t4_5 = time.time()
    selection(lst4_5)
    t4_5a = time.time()
    selection2(lst4_5a)
    t4_6 = time.time()
    selection(lst4_6)
    t4_7 = time.time()

    print()
    print("4000 Elemente")
    print("bubble1: {}s".format(t4_2 - t4_1))
    print("bubble2: {}s".format(t4_3 - t4_2))
    print("bubble3: {}s".format(t4_4 - t4_3))
    print("bubble3/sortiert: {}s".format(t4_5 - t4_4))
    print("selection: {}s".format(t4_5a - t4_5))
    print("selection2: {}s".format(t4_6 - t4_5a))
    print("selection/sortiert: {}s".format(t4_7 - t4_6))


#print(lst1)
#print(lst2)
#print(lst3)
#print(lst4)
#print(lst5)

#print(bubble3([1, 9, 2, 3, 4, 5]))
