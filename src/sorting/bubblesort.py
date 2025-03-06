
import copy
import random


def is_sorted(lst):
    min = -1
    for e in lst:
        if e < min:
            return False
        min = e
    return True


def bubble_sort1(lst):
    for x in lst[:-1]:
        for i in range(len(lst) - 1):
            if lst[i] > lst[i + 1]:
                lst[i], lst[i + 1] = lst[i + 1], lst[i]
    return lst


# def bubble_sort1(lst):
#     for x in lst[:-1]:
#         for i, y in enumerate(lst[:-1]):
#             if y > lst[i + 1]:
#                 lst[i], lst[i + 1] = lst[i + 1], lst[i]
#     return lst


def bubble_sort2(lst):
    for i_top in range(len(lst)-1, 0, -1):
        for j in range(i_top):
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
    return lst


def bubble_sort3(lst):
    for top in range(len(lst)-1, 0, -1):
        changed = False
        for y in range(top):
            if lst[y] > lst[y + 1]:
                lst[y], lst[y + 1] = lst[y + 1], lst[y]
                changed = True
                print("changed")
        if not changed:
            print("break performed")
            break
    return lst


def bubble_sort4(lst):
    n = len(lst)
    while True:
        new_n = 1
        for y in range(n - 1):
            if lst[y] > lst[y + 1]:
                lst[y], lst[y + 1] = lst[y + 1], lst[y]
                new_n = y + 1
        n = new_n
        if n == 1:
            break
    return lst


lst_orig = [3, 1, 5, 4, 7, 6, 2]

# lst = copy.copy(lst_orig)
# print(bubble_sort1(lst))

lst = copy.copy(lst_orig)
print(bubble_sort4(lst))

# #lst = copy.copy(lst_orig)
# print(bubble_sort3(lst))

import time

lst4 = [random.randint(0, 4000) for x in range(4000)]
lst4_1 = copy.copy(lst4)
lst4_2 = list(range(4000))

t4_1 = time.time()
bubble_sort1(lst4_1)
t4_2 = time.time()
bubble_sort1(lst4_2)
t4_3 = time.time()

print("4000 Elemente")
print("bubble_sort1: {}s".format(t4_2 - t4_1))
print("bubble_sort1/sortiert: {}s".format(t4_3 - t4_2))

#lst4 = [random.randint(0, 4000) for x in range(4000)]
#lst4_1 = copy.copy(lst4)
#lst4_2 = list(range(4000))

t4_1 = time.time()
bubble_sort3(lst4_1)
t4_2 = time.time()
bubble_sort3(lst4_2)
t4_3 = time.time()

print("4000 Elemente")
print("bubble_sort3: {}s".format(t4_2 - t4_1))
print("bubble_sort3/sortiert: {}s".format(t4_3 - t4_2))

