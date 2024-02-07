import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

ans = sum(arr)

for i in range(len(arr)):
    ans += arr[i] * (len(arr) - i - 1)

print(ans)
