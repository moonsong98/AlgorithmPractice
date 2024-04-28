import sys

input = sys.stdin.readline

n = int(input())
arr = sorted(list(map(int, input().split())))

m = int(input())
for el in list(map(int, input().split())):
    l, r = 0, len(arr) - 1
    found = False
    while l <= r:
        mid = l + (r - l) // 2
        if arr[mid] < el:
            l = mid + 1
        elif arr[mid] > el:
            r = mid - 1
        if arr[mid] == el:
            found = True
            break
    print(1 if found else 0, end=" ")
