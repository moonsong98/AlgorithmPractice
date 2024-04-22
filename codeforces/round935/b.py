import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

t = int(input())

while t:
    t -= 1
    a, b, m = list(map(int, input().split()))

    ans = 0
    c = a * b
    ans += (m + c) // a - (c - 1) // a
    ans += (m + c) // b - (c - 1) // b

    print(ans)
