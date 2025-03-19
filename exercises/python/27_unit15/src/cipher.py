# @copyright 2011 Günter Kolousek

def init_tab():
    t = [[chr(65+((i+j)%26)) for i in range(26)] for j in range(1,27)]
    return t

def print_tab():
    print("Klar | {}".format(" ".join([chr(97 + i) for i in range(26)])))
    i = 1
    for row in tab:
        print("{:4} | {}".format(i, " ".join(row)))
        i += 1


def decrypt(data, key):
    res = ""
    key_pos = 0
    data = data.upper()
    key = key.upper()
    for c in data:
        c_idx = ord(c) - 65
        key_idx = ord(key[key_pos]) - 66
        if key_idx < 0:
            key_idx += 26
        res += chr(tab[key_idx].index(c) + 65)
        key_pos = (key_pos + 1) % len(key)
    return res


def encrypt(data, key):
    res = ""
    key_pos = 0
    data = data.upper()
    key = key.upper()
    for c in data:
        if c.isalpha():
            c_idx = ord(c) - 65 # 0 <= c_idx <= 25
            key_idx = ord(key[key_pos]) - 66 # 66 ... beginnt mit B
            if key_idx < 0:
                key_idx += 26
            # 0 <= key_idx <= 25
            res += tab[key_idx][c_idx]
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

tab = init_tab()


if __name__ == "__main__":
    import sys

    print(sys.argv)
