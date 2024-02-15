import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

T = int(input())

while T:
    n, x, y = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    ans = 0

    d = {}

    for el in arr:
        a, b = el%x, el%y
        if ((x-a)%x, b) in d:
            ans += d[((x - a)%x,b)]
        if (a, b) in d:
            d[(a, b)] += 1
        else:
            d[(a, b)] = 1
    
    print(ans)

    T -= 1