# sort.py
"""All types of Sort"""


# Functions
def bbl(lst):
    """Bubble Sort"""
    n = len(lst)

    # Traverse through all array elements
    for i in range(n - 1):
        # range(n) also work but outer loop will repeat one time more than needed.

        # Last i elements are already in place
        for j in range(0, n - i - 1):

            # traverse the array from 0 to n-i-1
            # Swap if the element found is greater
            # than the next element
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
    return lst


def sel(lst):
    for i in range(len(lst)):
        a = i
        for j in range(i + 1, len(lst)):
            if lst[a] > lst[j]:
                a = j
        lst[i], lst[a] = lst[a], lst[i]
    return lst


def ins(lst):
    for i in range(1, len(lst)):
        a = lst[i]
        j = i - 1
        while j >= 0 and a < lst[j]:
            lst[j + 1] = lst[j]
            j -= 1
        lst[j + 1] = a
    return lst


"""Drive Code"""
a = [77, 33, 66, 1, 0, 345, 754]
print(ins(a))
print(bbl(a))
print(sel(a))

# ~~~~~~~~~~~~~~~~~~ AR group ~~~~~~~~~~~~~~
