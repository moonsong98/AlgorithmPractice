import sys
from collections import deque

input = sys.stdin.readline


def solve():
    n = int(input())
    s = list(input().strip())
    ans = 1
    for l in range(2, n + 1):
        flipped = [False] * n
        num_flip = 0
        possible = True
        for i in range(n):
            if i >= l:
                num_flip -= flipped[i - l]
            if i + l > n:
                if (num_flip + int(s[i])) % 2 == 0:
                    possible = False
                    break
            else:
                if (int(s[i]) + num_flip) % 2 == 0:
                    num_flip += 1
                    flipped[i] = True
        if possible:
            ans = l
    # print("ANS:", ans)
    print(ans)


t = int(input())
while t:
    t -= 1
    solve()
