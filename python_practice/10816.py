import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()
m = int(input())
cmp = list(map(int, input().split()))

def lb(num):
    l, r = 0, n-1
    ret = n
    while l <= r:
        mid = l + (r-l) // 2
        if arr[mid] >= num:
            ret = mid
            r = mid - 1
        else:
            l = mid + 1

    return ret

def ub(num):
    l, r = 0, n-1
    ret = n
    while l <= r:
        mid = l + (r-l) // 2
        if arr[mid] > num:
            ret = mid
            r = mid - 1
        else:
            l = mid + 1
    return ret

for el in cmp:
    lv, rv = lb(el), ub(el)

    print(rv - lv, end = " ")
