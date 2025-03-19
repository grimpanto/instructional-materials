# @copyright 2011 Günter Kolousek

def invert_dict(d):
    return {v : k for k, v in d.items()}


def encrypt1(msg):
    res = ""
    for c in msg:
        c = c.upper()
        if not c.isspace():
            num = ord(c) + 3
            if num > ord("Z"):
                num -= 26
            res += chr(num)
        else:
            res += " "
    return res


def decrypt1(msg):
    res = ""
    for c in msg:
        c = c.upper()
        if not c.isspace():
            num = ord(c) - 3
            if num < ord("A"):
                num += 26
            res += chr(num)
        else:
            res += " "
    return res


def encrypt2(msg, k=3):
    res = ""
    msg = msg.upper()
    for c in msg:
        if not c.isspace():
            num = ord(c) + k
            if num > ord("Z"):
                num -= 26
            res += chr(num)
        else:
            res += " "
    return res


def decrypt2(msg, k=3):
    res = ""
    for c in msg:
        if not c.isspace():
            num = ord(c) - k
            if num < ord("A"):
                num += 26
            res += chr(num)
        else:
            res += " "
    return res


def encrypt3(msg, k=3):
    res = ""
    for c in msg:
        if not c.isspace():
            num = ord(c) + k
            if c.isupper():
                if num > ord("Z"):
                    num -= 26
            elif c.islower():
                if num > ord("z"):
                    num -= 26
            res += chr(num)
        else:
            res += " "
    return res


def decrypt3(msg, k=3):
    res = ""
    for c in msg:
        if not c.isspace():
            num = ord(c) - k
            if c.isupper():
                if num < ord("A"):
                    num += 26
            elif c.islower():
                if num < ord("a"):
                    num += 26
            res += chr(num)
        else:
            res += " "
    return res


def translate_msg(mode, msg, k):
    res = ""
    for c in msg:
        if not c.isspace():
            num = ord(c) + mode * k
            if c.isupper():
                if num > ord("Z"):
                    num -= 26
                elif num < ord("A"):
                    num += 26
            elif c.islower():
                if num > ord("z"):
                    num -= 26
                elif num < ord("a"):
                    num += 26
            res += chr(num)
        else:
            res += " "
    return res


def brute_force(msg):
    for k in range(1,27):
        print(translate_msg(-1, msg, k))
