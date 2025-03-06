def binary_search(seq, key, left, right):
    while left <= right:
        mid = (left + right) // 2
        if seq[mid] == key:
            return mid
        elif seq[mid] > key:
            right = mid - 1
        else:
            left = mid + 1
    return None