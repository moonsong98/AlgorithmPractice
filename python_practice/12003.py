import sys

input = sys.stdin.readline

n, k = list(map(int, input().split()))

arr = []
for _ in range(n):
    arr.append(int(input()))
arr.sort()

r = 0
right = []
for l in range(n):
    while True:
        if r >= n or arr[r] - arr[l] > k:
            break
        r += 1
    right.append(r - l)

maxRightValue = [0] * (n + 1)
for idx in range(n - 1, -1, -1):
    maxRightValue[idx] = max(maxRightValue[idx + 1], right[idx])

ans = 0

for idx in range(n):
    ans = max(ans, right[idx] + maxRightValue[idx + right[idx]])

print(ans)
