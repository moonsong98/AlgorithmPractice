import sys

input = sys.stdin.readline

n = int(input())

arr = []

for _ in range(n):
    arr.append(tuple(map(int, input().split())))

arr.sort(key=lambda x: (x[1], x[0]))

cur_end = -1
ans = 0

for el in arr:
    if cur_end <= el[0]:
        ans += 1
        cur_end = el[1]

print(ans)
