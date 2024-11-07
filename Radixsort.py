from typing import List

def counting_sort_for_radix(arr: List[int], exp: int) -> List[int]:
    n = len(arr)
    output = [0] * n  # Output array
    count = [0] * 10  # Count array for digits (0-9)

    # Count occurrences of digits in the current place value
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1

    # Cumulative count to determine positions
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Build the output array
    for i in range(n - 1, -1, -1):
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1

    return output

def radix_sort(arr: List[int]) -> List[int]:
    max_num = max(arr)
    exp = 1  # Start with the least significant digit
    while max_num // exp > 0:
        arr = counting_sort_for_radix(arr, exp)
        exp *= 10
    return arr

# Example usage
product_ids = [329, 457, 657, 839, 436, 720, 355]
sorted_product_ids = radix_sort(product_ids)
print(sorted_product_ids)
