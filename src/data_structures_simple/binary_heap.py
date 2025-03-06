
class Heap:
    def __init__(self, data=[]):
        self.data = [0]
        self.size = 0
        self.build_heap(data)

    def insert(self, key):
        self.data.append(key)
        self.size += 1
        self.percolate_up(self.size)

    def extract(self):
        val = self.data[1]
        self.data[1] = self.data[self.size]
        self.size -= 1
        self.data.pop()
        self.percolate_down(1)
        return val

    def percolate_up(self, i):
        while i // 2 > 0:
            if self.data[i] > self.data[i // 2]:
                self.data[i // 2], self.data[i] = self.data[i], self.data[i // 2]
            i = i // 2

    def percolate_down(self, i):
        while (i * 2) <= self.size:
            mc = self.min_child(i)
            if self.data[i] < self.data[mc]:
                self.data[i], self.data[mc] = self.data[mc], self.data[i]
            i = mc

    def min_child(self, i):
        if 2 * i + 1 > self.size:
            return 2 * i
        else:
            if self.data[2 * i] > self.data[2 * i + 1]:
                return 2 * i
            else:
                return 2 * i + 1

    def build_heap(self, lst):
        i = len(lst) // 2
        self.size = len(lst)
        self.data = [0] + lst[:]
        while (i > 0):
            self.percolate_down(i)
            i -= 1

h = Heap([9,5,6,2,3])
h.insert(7)
print(h.extract())
print(h.extract())
print(h.extract())
print(h.extract())
print(h.extract())
print(h.extract())
h.build_heap([])
h.insert(7)
print(h.extract())
