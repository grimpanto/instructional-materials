# @copyright 2011 Günter Kolousek

# -*- coding: utf-8 -*-

"""
author: Günter Kolousek
matnr:  ko
file:   unit17.py
desc:   Dieses Modul enthält Funktionen zur Implementierung des Insertion-Sort
date:   2011-03-21
"""

def insertion(lst):
    # vom zweiten Element bis zum letzten Element
    for curr in range(1, len(lst)):
        val = lst[curr]
        i = curr
        while True:
            if i == 0:
                break
            if lst[i - 1] <= val:
                break
            lst[i] = lst[i - 1]
            i -= 1
        lst[i] = val
    return lst


def insertion2(lst):
    # vom zweiten Element bis zum letzten Element
    for curr in range(1, len(lst)):
        val = lst[curr]
        i = curr
        while True:
            if i == 0 or lst[i - 1] <= val:
                break
            lst[i] = lst[i - 1]
            i -= 1
        lst[i] = val
    return lst

import time
import random
import copy

lst1 = [random.randint(0, 1000) for x in range(1000)]
lst1_1 = copy.copy(lst1)
lst1_2 = list(range(1000))
lst2_1 = copy.copy(lst1)
lst2_2 = list(range(1000))

t1_1 = time.time()
insertion(lst1_1)
t1_2 = time.time()
insertion(lst1_2)
t1_3 = time.time()
insertion2(lst2_1)
t2_1 = time.time()
insertion2(lst2_2)
t2_2 = time.time()

print("1000 Elemente")
print("insertion: {}s".format(t1_2 - t1_1))
print("insertion/sortiert: {}s".format(t1_3 - t1_2))
print("insertion2: {}s".format(t2_1 - t1_3))
print("insertion2/sortiert: {}s".format(t2_2 - t2_1))


lst2 = [random.randint(0, 2000) for x in range(2000)]
lst2_1 = copy.copy(lst2)
lst2_2 = list(range(2000))

t2_1 = time.time()
insertion(lst2_1)
t2_2 = time.time()
insertion(lst2_2)
t2_3 = time.time()

print("2000 Elemente")
print("insertion: {}s".format(t2_2 - t2_1))
print("insertion/sortiert: {}s".format(t2_3 - t2_2))

lst4 = [random.randint(0, 4000) for x in range(4000)]
lst4_1 = copy.copy(lst4)
lst4_2 = list(range(1000))

t4_1 = time.time()
insertion(lst4_1)
t4_2 = time.time()
insertion(lst4_2)
t4_3 = time.time()

print("4000 Elemente")
print("insertion: {}s".format(t4_2 - t4_1))
print("insertion/sortiert: {}s".format(t4_3 - t4_2))
