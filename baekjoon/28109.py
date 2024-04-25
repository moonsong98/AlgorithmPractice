import sys

input = sys.stdin.readline


def solve():
    n, k = list(map(int, input().split()))
    s = list(input().strip())

    if len(s) * 25 + 1 < k:
        print(-1)
    else:
        for i, ch in enumerate(s):
            diff = ord(ch) - ord("A")
            if diff >= k:
                s[i] = chr(ord("A") + k - 1)
                for el in s:
                    print(el, end="")
                return
            else:
                k -= diff

        if k == 1:
            for el in s:
                print(el, end="")
            return

        k -= 1

        for i in range(len(s) - 1, -1, -1):
            diff = ord("Z") - ord(s[i])
            if diff >= k:
                s[i] = chr(ord(s[i]) + k)
                for el in s:
                    print(el, end="")
                return
            else:
                k -= diff


solve()
