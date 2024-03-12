import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

T = int(input())

while T:
    T -= 1

    n, m, x = map(int, input().split())

    cmds = []
    for _ in range(m):
        cmds.append(input().split())

    def cw(pos, amt):
        newPos = (pos + amt) % n
        return newPos if newPos else n

    def ccw(pos, amt):
        newPos = (pos - amt) % n
        return newPos if newPos else n

    visited = [[0] * (n + 1) for _ in range(m + 1)]

    found = [False] * (n + 1)

    def solve(pos, cmd_num):
        if cmd_num == m:
            found[pos] = True
            return

        if visited[cmd_num][pos]:
            return

        visited[cmd_num][pos] = True
        cmd = cmds[cmd_num]
        r, c = cmd
        r = int(r)
        if c == "0":
            solve(cw(pos, r), cmd_num + 1)
        elif c == "1":
            solve(ccw(pos, r), cmd_num + 1)
        else:
            solve(cw(pos, r), cmd_num + 1)
            solve(ccw(pos, r), cmd_num + 1)

    solve(x, 0)
    cnt = 0
    for el in found:
        if el:
            cnt += 1

    print(cnt)
    for idx in range(len(found)):
        if found[idx]:
            print(idx, end=" ")
    print()
