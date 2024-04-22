import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

t = int(input())

while t:
    t -= 1
    n = int(input())
    if n % 2 == 1:
        print("NO")
        continue
    print("YES")
    nxt = "A"
    s = ""
    for i in range(0, n, 2):
        s += nxt * 2
        nxt = "A" if nxt == "B" else "B"

    print(s)
