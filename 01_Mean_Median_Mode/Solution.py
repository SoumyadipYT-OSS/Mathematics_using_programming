class Solution:
    def bubble_sort(self, arr):
        n = len(arr)
        for i in range(n-1):
            for j in range(n-i-1):
                if arr[j] > arr[j+1]:
                    arr[j], arr[j+1] = arr[j+1], arr[j]
        return arr

    def sum_value(self, ar):
        return sum(ar)

    def mean(self, ar):
        return self.sum_value(ar) / len(ar)

    def median(self, ar):
        ar = self.bubble_sort(ar)
        n = len(ar)
        if n % 2 == 0:
            return (ar[n // 2] + ar[n // 2 - 1]) / 2
        return ar[n // 2]

    def mode(self, ar):
        frequency = {}
        for item in ar:
            frequency[item] = frequency.get(item, 0) + 1
        max_count = max(frequency.values())
        for key, value in frequency.items():
            if value == max_count:
                return key, max_count