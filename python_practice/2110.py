import sys

input = sys.stdin.readline

n, c = list(map(int, input().split()))
arr = [int(input()) for _ in range(n)]
arr.sort()
d = []
for idx in range(n-1):
    d.append(arr[idx+1] - arr[idx])

l, r = 1, arr[n-1] - arr[0]

ans = -1

while l <= r:
    mid = l + (r-l) // 2
    cnt = 1
    s = 0
    for el in d:
        s += el
        if s >= mid:
            cnt += 1
            s = 0
    if cnt >= c:
        ans = mid
        l = mid + 1
    else:
        r = mid - 1

print(ans)
