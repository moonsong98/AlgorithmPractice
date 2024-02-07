import sys

input = sys.stdin.readline

n = int(input())
e = list(map(int, input().split()))
v = list(map(int, input().split()))
c = v[0]
v = v[1:]

ans = 0

for i in range(len(v)):
    ans += c * e[i]
    if c > v[i]:
        c = v[i]

print(ans)
