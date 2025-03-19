# @copyright 2011 Günter Kolousek

t=[[chr(65+((i+j)%26)) for i in range(26)] for j in range(1,27)]

def decrypt(data, key):
    res = ""
    key_pos = 0
    data = data.upper()
    key = key.upper()
    for c in data:
        c_idx = ord(c) - 65
        key_idx = ord(key[key_pos]) - 65
        if key_idx <= 0:
            key_idx += 25
        print(key_idx, c_idx)
        res += chr(t[key_idx].index(c) + 65)
        key_pos = (key_pos + 1) % len(key)
    return res


def encrypt(data, key):
    res = ""
    key_pos = 0
    data = data.upper()
    key = key.upper()
    for c in data:
        c_idx = ord(c) - 65
        key_idx = ord(key[key_pos]) - 65
        if key_idx <= 0:
            key_idx += 25
        print(key_idx, c_idx)
        res += t[key_idx][c_idx]
        key_pos = (key_pos + 1) % len(key)
    return res

    # res = ""
    # key_pos = 0
    # data = data.upper()
    # key = key.upper()
    # for c in data:
    #     c_idx = ord(c) - 64
    #     key_idx = ord(key[key_pos]) - 64 - 1
    #     if key_idx <= 0:
    #         key_idx += 26
    #     print(c_idx, key_idx)

    #     tmp = ord(c) - (26 - key_idx)
    #     if tmp < ord("A"):
    #         tmp += 26
    #     res = res + chr(tmp)

    #     key_pos = (key_pos + 1) % len(key)
    #     print(key_pos)
    # return res
