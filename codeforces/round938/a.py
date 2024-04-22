import sys

input = sys.stdin.readline


def solve():
    t = int(input())
    while t:
        t -= 1
        n, a, b = list(map(int, input().split()))
        if a * 2 <= b:
            print(n * a)
        else:
            n1, n2 = n // 2, n % 2
            print(n1 * b + n2 * a)

    pass


solve()
