import sys

input = sys.stdin.readline
# sys.setrecursionlimit(int(1e9))

t = int(input())

for _ in range(t):
    s = input().strip()
    ans = 0
    for d in range(1, len(s) // 2 + 1):
        cnt = 0
        for i in range(0, len(s) - d):
            cnt += s[i] == s[i + d] or s[i] == "?" or s[i + d] == "?"
            if i >= d:
                cnt -= s[i - d] == s[i] or s[i - d] == "?" or s[i] == "?"
            if i + 1 >= d and cnt == d:
                ans = d * 2

    print(ans)
