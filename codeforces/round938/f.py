import sys

input = sys.stdin.readline

t = int(input())
while t > 0:
    t -= 1
    ans = 0
    a, b, c, d = list(map(int, input().split()))
    ans += d // 2

    ans += a // 2 + b // 2 + c // 2

    if a > 0 and b > 0 and c > 0 and a % 2 and b % 2 and c % 2:
        ans += 1

    print(ans)
