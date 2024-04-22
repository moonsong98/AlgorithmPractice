import sys
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

t = int(input())

while t:
    t -= 1
    n = int(input())
    arr = list(map(int, input().split()))
    valid = True
    q = deque()
    for i in range(0, n - 1):
        if arr[i] > arr[i + 1]:
            if arr[i] < 10:
                valid = False
                break
            a, b = arr[i] // 10, arr[i] % 10
            if a > b:
                valid = False
                break
            if b > arr[i + 1]:
                valid = False
                break

            if not len(q):
                pass
            elif a < q[-1]:
                cur = a
                for _ in range(len(q)):
                    cmp = q.pop()
                    if cur < cmp:
                        if cmp < 10:
                            valid = False
                            break
                        y = cmp // 10
                        z = cmp % 10
                        if y > z:
                            valid = False
                            break
                        if cur < z:
                            valid = False
                            break

                        cur = y
                        q.appendleft(z)
                        q.appendleft(y)
                    else:
                        q.appendleft(cmp)
                        cur = cmp
                if not valid:
                    break

            q.append(a)
            q.append(b)

        else:
            q.append(arr[i])

    print("YES" if valid else "NO")
