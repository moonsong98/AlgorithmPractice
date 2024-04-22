import sys
from collections import deque

input = sys.stdin.readline


def solve():
    n, k = list(map(int, input().split()))
    q = deque(list(map(int, input().split())))
    ls, rs = 0, 0
    ans = 0
    while len(q):
        if len(q) > 1:
            if q[0] <= q[-1]:
                atk = q[0] * 2 - 1
                if atk > k:
                    break
                q[-1] -= q[0]
                q.popleft()
                k -= atk + 1
                if q[-1] == 0 and k >= 0:
                    q.pop()
                    ans += 1
            else:
                atk = q[-1] * 2
                if atk > k:
                    break
                q[0] -= q[-1]
                q.pop()
                k -= atk
            ans += 1
        else:
            atk = q[0]
            if atk > k:
                break
            ans += 1
            q.pop()

    print(ans)


t = int(input())
while t:
    t -= 1
    solve()
