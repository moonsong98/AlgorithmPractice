import sys

input = sys.stdin.readline

n = int(input())

d = dict()

for _ in range(n):
    a, c = list(map(int, input().split()))

    if c in d:
        d[c] = min(d[c], a)
    else:
        d[c] = a

ans = -1
for v in d.values():
    ans = max(ans, v)

print(ans)
