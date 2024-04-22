import sys

input = sys.stdin.readline


def solve():
    n, q = list(map(int, input().split()))
    queries = list(map(int, input().split()))

    s = set()
    added = dict()  # Save step when added
    size_s = [0]  # Save cumulative sum after each step
    ans = [0 for _ in range(n + 1)]
    for i, x in enumerate(queries):
        if x in s:
            s.remove(x)
            ans[x] += size_s[i] - size_s[added[x]]
            size_s.append(size_s[-1] + len(s))
        else:
            added[x] = i
            s.add(x)
            size_s.append(size_s[-1] + len(s))

    for el in s:
        ans[el] += size_s[q] - size_s[added[el]]

    print(*ans[1:])


solve()
