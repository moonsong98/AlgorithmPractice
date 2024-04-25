import sys

input = sys.stdin.readline

n = int(input())
arr = sorted(list(map(int, input().split())))

ans = -1

max_diff = -1

for i in range(n - 1):
    diff = arr[i + 1] - arr[i]
    if diff == 1:
        continue

    if diff % 2:
        if (diff - 1) // 2 > max_diff:
            ans = arr[i] + (diff - 1) // 2
            max_diff = (diff - 1) // 2
    else:
        if diff // 2 > max_diff:
            ans = arr[i] + diff // 2
            max_diff = diff // 2

print(ans)
