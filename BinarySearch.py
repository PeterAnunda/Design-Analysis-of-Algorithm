import time
from random import randint

def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def measure_search_time(arr, target):
    start_time = time.time()
    binary_search(arr, target)
    end_time = time.time()
    return end_time - start_time

# Simulate best, worst, and average-case scenarios
arr = sorted([randint(0, 1000000) for _ in range(1000000)])

# Best case: target is in the middle
print("Best case time:", measure_search_time(arr, arr[len(arr)//2]))

# Worst case: target is not present
print("Worst case time:", measure_search_time(arr, -1))

# Average case: target is somewhere random
print("Average case time:", measure_search_time(arr, arr[randint(0, len(arr) - 1)]))
