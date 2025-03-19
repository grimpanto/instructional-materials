# @copyright 2011 Günter Kolousek

# -*- coding: utf-8 -*-

"""
author: Günter Kolousek
matnr:  ko
file:   lists.py
desc:   Dieses Modul enthält verschiedene Funktionen, die sich mit Listen
        beschaffen.
date:   2010-02-14
"""


def concat(a, b):
    for e in b:
        a.append(e)

    return a


def insert(a, b, i):
    for e in reversed(b):
        a.insert(i, e)

    return a


def sort(a):
    a.sort()
    return a


def sort_descending(a):
    return reversed(sorted(a))


def minimum(seq):
    if seq:
        min_number = seq[0]

        for e in seq:
            if e < min_number:
                min_number = e

        return min_number
    else:
        return None


def maximum(seq):
    if seq:
        max_number = seq[0][1]

        for e in seq:
            if e[1] > max_number:
                max_number = e[1]

        return max_number


def find(seq, num):
    i = 0

    for e in seq:
        if e == num:
            break
        i += 1

    if i == len(seq):
        i = -1

    return i


def find2(seq, num):
    i = 0

    for e in seq:
        if e == num:
            break
        i += 1
    else:
        i = -1

    return i


if __name__ == "__main__":
    lst = []
    while True:
        try:
            nr = float(input("Bitte eine Zahl eingeben: "))
            lst.append(nr)
        except EOFError:
            break

    if lst:
        print("Das Minimum ist: ", minimum(lst))
    else:
        print("Es wurden keine Zahlen eingegeben!")
