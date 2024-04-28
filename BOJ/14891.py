import sys
from collections import deque

input = sys.stdin.readline

q = [deque(input().strip()) for _ in range(4)]


def spin(q, dir):
    if dir == 1:
        q.appendleft(q.pop())
    else:
        q.append(q.popleft())


n = int(input())
cmds = [list(map(int, input().split())) for _ in range(n)]

for cmd in cmds:
    move, dir = cmd
    move -= 1
    interfacel = q[move][6]
    interfacer = q[move][2]
    spin(q[move], dir)

    nxt_dir = dir * -1
    for i in range(move - 1, -1, -1):
        if interfacel != q[i][2]:
            interfacel = q[i][6]
            spin(q[i], nxt_dir)
            nxt_dir *= -1
        else:
            break

    nxt_dir = dir * -1
    for i in range(move + 1, 4):
        if interfacer != q[i][6]:
            interfacer = q[i][2]
            spin(q[i], nxt_dir)
            nxt_dir *= -1
        else:
            break


ans = 0

for i in range(4):
    ans += 2**i * int(q[i][0])

print(ans)
