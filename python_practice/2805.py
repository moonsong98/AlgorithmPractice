import sys

input = sys.stdin.readline

n, m = list(map(int, input().split()))
arr = list(map(int, input().split()))
arr.sort()

l, r = 0, arr[n - 1]
ans = -1

while l <= r:
    mid = l + (r - l) // 2
    s = 0
    for el in arr:
        s += 0 if mid > el else el - mid
    if s >= m:
        ans = mid
        l = mid + 1
    else:
        r = mid - 1

print(ans)
