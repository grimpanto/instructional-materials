
import random
import copy
import time


def partition(lst, left, right): 
    pivot = lst[right]
    i = left - 1
    for j in range(left, right):
        if lst[j] <= pivot:
            i = i + 1
            lst[i], lst[j] = lst[j], lst[i]
    lst[i + 1], lst[right] = lst[right], lst[i + 1]
    return i + 1

# [1, 15, 2, 49, 43, 17, 4, 8, 47, 42]
# i = 2, j = 8
# [1, 15, 2, 47, 43, 17, 4, 8, 49, 42]
# i = 3, j = 7


def partition2(lst, left, right):
    pivot = lst[left]
    i = left
    j = right + 1
    while True:
        i += 1
        while i <= right and lst[i] < pivot:
            i += 1
        j -= 1
        while j >= left and lst[j] > pivot:
            j -= 1
        if i < j:
            lst[i], lst[j] = lst[j], lst[i]
        else:
            break
    lst[j], lst[left] = lst[left], lst[j]
    return j



def partition3(lst, left, right):
    pivot = lst[right]
    i = left - 1
    j = right
    while True:
        i += 1
        while i <= right and lst[i] < pivot:
            i += 1
        j -= 1
        while j >= left and lst[j] > pivot:
            j -= 1
        if i < j:
            lst[i], lst[j] = lst[j], lst[i]
        else:
            break
    lst[i], lst[right] = lst[right], lst[i]
    return i



def quicksort_(lst, left, right):
    if left < right:
        p = part(lst, left, right)
#        print(lst[left:p], lst[p], lst[p+1:right+1])
        quicksort_(lst, left, p - 1)
        quicksort_(lst, p + 1, right)


def quicksort(lst):
    quicksort_(lst, 0, len(lst) - 1)


def is_sorted(lst):
    min = -1
    for e in lst:
        if e < min:
            return False
        min = e
    return True

# import sys
# print(sys.setrecursionlimit(5000))


if True:
    lst = [1, 15, 2, 49, 43, 17, 4, 8, 47, 42, 49]
    lst = [1, 15, 2, 43, 17, 4, 8, 47, 49, 42]
    lst = [1, 2]
    lst = [1]
    lst = []
    part = partition3
    quicksort(lst)
    print(lst)
    print(is_sorted(lst))
else:
    import time
     
    for cnt in range(10):
        lst = [random.randint(0, 10000) for x in range(100000)]
        lst2 = lst[:]
        lst3 = lst[:]
        t1 = time.time()
        part = partition
        quicksort(lst)
        t2 = time.time()
        part = partition2
        quicksort(lst2)
        t3 = time.time()
        part = partition3
        quicksort(lst3)
        t4 = time.time()

        #print(is_sorted(lst))
        print(t2 - t1, t3 - t2, t4 - t3)


# lst1 = [random.randint(0, 1000) for x in range(1000)]
# lst1_1 = copy.copy(lst1)
# lst1_2 = list(range(1000))
# lst2_1 = copy.copy(lst1)
# lst2_2 = list(range(1000))

# t1_1 = time.time()
# quicksort(lst1_1)
# t1_2 = time.time()
# quicksort(lst1_2)
# t1_3 = time.time()

# print("1000 Elemente")
# print("quicksort: {}s".format(t1_2 - t1_1))
# print("quicksort/sortiert: {}s".format(t1_3 - t1_2))

# lst2 = [random.randint(0, 2000) for x in range(2000)]
# lst2_1 = copy.copy(lst2)
# lst2_2 = list(range(2000))

# t2_1 = time.time()
# quicksort(lst2_1)
# t2_2 = time.time()
# quicksort(lst2_2)
# t2_3 = time.time()

# print("2000 Elemente")
# print("quicksort: {}s".format(t2_2 - t2_1))
# print("quicksort/sortiert: {}s".format(t2_3 - t2_2))

# lst4 = [random.randint(0, 4000) for x in range(4000)]
# lst4_1 = copy.copy(lst4)
# lst4_2 = list(range(4000))

# t4_1 = time.time()
# quicksort(lst4_1)
# t4_2 = time.time()
# quicksort(lst4_2)
# t4_3 = time.time()

# print("4000 Elemente")
# print("quicksort: {}s".format(t4_2 - t4_1))
# print("quicksort/sortiert: {}s".format(t4_3 - t4_2))

