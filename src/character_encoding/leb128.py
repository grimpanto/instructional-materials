
def encode_leb128(data):
    res = []
    while True:
        encoded_byte = data % 128
        data = data // 128
        if data > 0:
            encoded_byte = encoded_byte | 128
        res.append(encoded_byte)
        if data == 0:
            break
    return res

print("encode_leb128(0):", encode_leb128(0))
print("encode_leb128(1):", encode_leb128(1))
print("encode_leb128(2):", encode_leb128(2))
print("encode_leb128(127):", encode_leb128(127))
print("encode_leb128(128):", encode_leb128(128))
print("encode_leb128(129):", encode_leb128(129))
print("encode_leb128(255):", encode_leb128(255))
print("encode_leb128(256):", encode_leb128(256))
print("encode_leb128(257):", encode_leb128(257))
print("encode_leb128(16383):", encode_leb128(16383))
print("encode_leb128(16384):", encode_leb128(16384))
print("encode_leb128(2_097_151):", encode_leb128(2_097_151))
print("encode_leb128(2_097_152):", encode_leb128(2_097_152))
print("encode_leb128(268_435_455):", encode_leb128(268_435_455))

print("encode_leb128(123456):", encode_leb128(123456))



# def decode_leb128(data):
#     multiplier = 1
#     res = 0
#     for encoded_byte in data:
#         res += (encoded_byte & 127) * multiplier
#         multiplier *= 128
#     return res


def decode_leb128(data):
    shift = 0
    res = 0
    for encoded_byte in data:
        res = res | ((encoded_byte & 127) << shift)
        shift += 7
    return res

print("decode_leb128([0]):", decode_leb128([0]))
print("decode_leb128([1]):", decode_leb128([1]))
print("decode_leb128([2]):", decode_leb128([2]))
print("decode_leb128([127]):", decode_leb128([127]))
print("decode_leb128([128, 1]):", decode_leb128([128, 1]))
print("decode_leb128([255, 1]):", decode_leb128([255, 1]))
print("decode_leb128([128, 2]):", decode_leb128([128, 2]))
print("decode_leb128([129, 2]):", decode_leb128([129, 2]))
print("decode_leb128([255, 255, 127]):", decode_leb128([255, 255, 127]))
print("decode_leb128([128, 128, 128, 1]):", decode_leb128([128, 128, 128, 1]))
print("decode_leb128([255, 255, 255, 127]):", decode_leb128([255, 255, 255, 127]))
