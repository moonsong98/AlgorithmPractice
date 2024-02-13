import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

l, r = 0, n-1
ans1, ans2 = -1, -1
min_s = 1e9 * 2

while l < r:
    s = arr[l] + arr[r]
    if min_s > (s if s > 0 else -s):
        min_s = (s if s > 0 else -s)
        ans1, ans2 = arr[l], arr[r]
    if s > 0:
        r -= 1
    else:
        l += 1

print(ans1, ans2)
