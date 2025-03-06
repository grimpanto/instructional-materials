

def hash_str_simple(s, m):
    val = 0
    for i in range(len(s)):
        j = len(s) - 1 - i
        val += ord(s[j]) << (8 * i)
    return val % m

print(hash_str_simple("KEY", 163), end=", ")
print(hash_str_simple("KEY", 7), end=", ")
print(hash_str_simple("KEY", 11), end=", ")

print(hash_str_simple("value", 163), end=", ")
print(hash_str_simple("value", 7), end=", ")
print(hash_str_simple("value", 9))


def hash_str_horner(s, m):
    val = 0
    for i in range(len(s)):
        val = (val << 8) + ord(s[i])
    return val % m

print(hash_str_horner("KEY", 163), end=", ")
print(hash_str_horner("KEY", 7), end=", ")
print(hash_str_horner("KEY", 11), end=", ")

print(hash_str_horner("value", 163), end=", ")
print(hash_str_horner("value", 7), end=", ")
print(hash_str_horner("value", 11))

def hash_str_horner(s, m):
    val = 0
    for i in range(len(s)):
        val = (val << 8) + ord(s[i])
    print(val)
    return val % m

print(hash_str_horner("value_or_not_value?", 163))


def hash_str_horner(s, m):
    val = 0
    for i in range(len(s)):
        val = ((val << 8) % m + ord(s[i]) % m) % m
        print(val, end=",")
    return val

print(hash_str_horner("value_or_not_value?", 163))


def c_mul(a, b):
    #return int(hex((a * b) & 0xFFFFFFFF), 16)
    return (a * b) & 0xFFFFFFFF

def hash_str_python(s, m):
    if not s:
        return 0
    val = ord(s[0]) << 7
    for c in s:
        val = c_mul(1000003, val) ^ ord(c)
    return (val ^ len(s)) & (2 ^ m - 1)

print(hash_str_python("value_or_not_value?", 4))
