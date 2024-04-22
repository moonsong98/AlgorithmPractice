import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

t = int(input())

for _ in range(t):
    n, k = list(map(int, input().split()))
    if n == 1:
        print(1)
    else:
        if k < n - 1:
            print(n)
        else:
            print(1)
