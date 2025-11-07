import bisect

def bin_search(l, x):
    i = bisect.bisect_left(l, x)
    if l[i] == x:
        return i
    return -1


print(bin_search([1, 5, 8, 12], 9))
