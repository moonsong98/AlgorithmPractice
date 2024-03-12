import sys

input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

after = {}
before = {}

for i in range(N):
    after[arr[i]] = -1 if i == N - 1 else arr[i + 1]
    before[arr[i]] = -1 if i == 0 else arr[i - 1]

Q = int(input())
for _ in range(Q):
    cmds = list(map(int, input().split()))

    if cmds[0] == 1:
        a, b = cmds[1:]

        if after[a] != -1:
            before[after[a]] = b
        before[b] = a
        after[b] = after[a]
        after[a] = b

    if cmds[0] == 2:
        a = cmds[1]
        if before[a] != -1:
            after[before[a]] = after[a]
        if after[a] != -1:
            before[after[a]] = before[a]
        del after[a]
        del before[a]

if len(after) == 1:
    print(list(after.keys())[0])

else:
    head = -1
    for k, v in after.items():
        if v != -1 and before[k] == -1:
            head = k

    cur = head
    while True:
        print(cur, end=" ")
        if after[cur] == -1:
            break
        cur = after[cur]
