import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()
x = int(input())

l, r, ans = 0, n-1, 0

while l <= r:
    s = arr[l] + arr[r]
    if s < x:
        l += 1
    elif s > x:
        r -= 1
    else:
        ans += 1
        l += 1

print(ans)
