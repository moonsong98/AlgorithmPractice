import sys
import math

input = sys.stdin.readline

n = int(input())

equations = [list(map(int, input().split())) for _ in range(n)]

for i in range(n - 1):
    lcm = math.lcm(*[equation[i] for equation in equations[i:] if equation[i] != 0])
    if equations[i][i] == 0:
        for j in range(i + 1, n):
            if equations[j][i] != 0:
                equations[i], equations[j] = equations[j], equations[i]
                break
    for j in range(i, n):
        if equations[j][i] == 0:
            continue
        multiplier = lcm // equations[j][i]
        for k in range(n + 1):
            equations[j][k] *= multiplier

    for j in range(i + 1, n):
        if equations[j][i] == 0:
            continue
        for k in range(n + 1):
            equations[j][k] -= equations[i][k]

ans = [0 for _ in range(n)]

for idx in range(n - 1, -1, -1):
    rhs = equations[idx][-1]
    for i in range(idx + 1, n):
        rhs -= equations[idx][i] * ans[i]
    ans[idx] = rhs // equations[idx][idx]

print(*ans)
