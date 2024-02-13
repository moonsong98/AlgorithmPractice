import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
lis = []

for el in arr:
    if len(lis) == 0 or lis[-1] < el:
        lis.append(el)
    else:
        l, r = 0, len(lis) - 1

        replace_idx = 0
        while l <= r:
            mid = l + (r - l) // 2
            if el <= lis[mid]:
                replace_idx = mid
                r = mid - 1
            else:
                l = mid + 1
        lis[replace_idx] = el

print(len(lis))
