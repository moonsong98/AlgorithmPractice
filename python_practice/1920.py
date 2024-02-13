import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

m = int(input())
cmp = list(map(int, input().split()))

def bs(num):
    l, r = 0, n-1
    while l <= r:
        mid = l + (r - l) // 2

        if arr[mid] == num:
            return 1
        if arr[mid] > num:
            r = mid - 1
        else:
            l = mid + 1

    return 0

for el in cmp:
    l, r = 0, n

    print(bs(el))
