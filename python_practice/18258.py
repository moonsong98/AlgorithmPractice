import sys
from collections import deque

input = sys.stdin.readline

T = int(input())
q = deque(maxlen=T)

while T:
    T -= 1
    commands = input().split()
    if len(commands) == 2:
        q.append(commands[1])
    elif commands[0] == "pop":
        if len(q) == 0:
            print(-1)
            continue
        print(q.popleft())
    elif commands[0] == "size":
        print(len(q))
    elif commands[0] == "empty":
        print(0 if len(q) else 1)
    elif commands[0] == "front":
        if len(q) == 0:
            print(-1)
            continue
        num = q.popleft()
        print(num)
        q.appendleft(num)
    elif commands[0] == "back":
        if len(q) == 0:
            print(-1)
            continue
        num = q.pop()
        print(num)
        q.append(num)
