import sys
import math

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

T = int(input())

while T:
    T -= 1

    n, c = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    ans = (c + 1) * (c + 2) // 2
    n_even = 0
    n_odd = 0
    cnt1 = 0
    cnt2 = 0
    for el in arr:
        if el % 2 == 0:
            n_even += 1
        else:
            n_odd += 1

        ans -= 1 + el // 2
        ans -= (c - el) + 1

    if n_even:
        ans += n_even + math.comb(n_even, 2)
    if n_odd:
        ans += n_odd + math.comb(n_odd, 2)

    print(ans)
