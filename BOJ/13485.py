import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
b, c = list(map(int, input().split()))

ans = 0

for el in a:
    ans += 1
    el -= b
    if el <= 0:
        continue
    ans += el // c + int(el % c > 0)

print(ans)
