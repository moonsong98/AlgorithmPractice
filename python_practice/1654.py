import sys

input = sys.stdin.readline

n, k = list(map(int, input().split()))

arr = []
for _ in range(n):
    arr.append(int(input()))

arr.sort()

l, r = 1, arr[n-1]

ans = 0

while(l <= r):
    mid = l + (r - l) // 2
    cnt = 0
    for el in arr:
        cnt += el // mid
    if cnt >= k:
        ans = mid
        l = mid + 1
    else:
        r = mid - 1

print(ans)
