import time
def bubble_sort(input_list:list) ->list:
    n = len(input_list)
    # Traverse through all array elements
    for i in range(n - 1):
        # Flag to optimize: if no swaps occur in a pass, the array is sorted
        swapped = False
        # Last i elements are already in place, so we don't need to check them
        for j in range(0, n - i - 1):
            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater than the next element
            if input_list[j] > input_list[j + 1]:
                input_list[j], input_list[j + 1] = input_list[j + 1], input_list[j]
                swapped = True
        # If no two elements were swapped by inner loop, then break
        if not swapped:
            break
    return None

if __name__ == "__main__":
    start_time = time.time()
    n = 1000
    data_tosort = [i for i in range(n,1,-1)]
    result  = bubble_sort(data_tosort)
    stop_time = time.time()
    print(f'sorting time for {n} records is {(stop_time - start_time) * 1000 :.2f} miniseconds')

    n = 2000
    data_tosort = [i for i in range(n,1,-1)]
    result  = bubble_sort(data_tosort)
    stop_time = time.time()
    print(f'sorting time for {n} records is {(stop_time - start_time) * 1000 :.2f} miniseconds')
    n = 4000
    data_tosort = [i for i in range(n,1,-1)]
    result  = bubble_sort(data_tosort)
    stop_time = time.time()
    print(f'sorting time for {n} records is {(stop_time - start_time) * 1000 :.2f} miniseconds')

    n = 8000
    data_tosort = [i for i in range(n,1,-1)]
    result  = bubble_sort(data_tosort)
    stop_time = time.time()
    print(f'sorting time for {n} records is {(stop_time - start_time) * 1000 :.2f} miniseconds')

    n = 16000
    data_tosort = [i for i in range(n,1,-1)]
    result  = bubble_sort(data_tosort)
    stop_time = time.time()
    print(f'sorting time for {n} records is {(stop_time - start_time) * 1000 :.2f} miniseconds')