class FenwickTree:
    def __init__(self, size):
        self.size = size
        self.data = [0 for _ in range(size)]

    def add(self, idx, val):
        while idx < self.size:
            self.data[idx] += val
            idx += idx & -idx

    def sum(self, idx):
        res = 0
        while idx > 0:
            res += self.data[idx]
            idx -= idx & -idx
        return res
