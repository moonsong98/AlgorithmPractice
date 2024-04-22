import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

t = int(input())

while t:
    t -= 1
    a, b, c = list(map(int, input().split()))
    if b % 3 and c < 3 - b % 3:
        print(-1)
        continue
    if b % 3:
        c -= 3 - b % 3
        b += 3 - b % 3
    print(a + b // 3 + c // 3 + int(c % 3 > 0))
