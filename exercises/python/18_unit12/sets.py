# @copyright 2011 Günter Kolousek

# -*- coding: utf-8 -*-

"""
author: Günter Kolousek
matnr:  ko
file:   sets.py
desc:   Dieses Modul enthält Funktionen zur Berechnung der Mengenoperationen
date:   2011-02-14
"""

def union(a, b):
    c = set()

    for e in a:
        c.add(e)

    for e in b:
        c.add(e)

    return c


def minus(a, b):
    for e in b:
        a.discard(e)

    return a
