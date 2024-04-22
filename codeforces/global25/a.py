import sys

input = sys.stdin.readline

t = int(input())

while t:
    t -= 1
    n = int(input())
    seq = list(input().strip())
    pos = []
    cnt1 = 0

    for i, el in enumerate(seq):
        if el == "1":
            cnt1 += 1
            pos.append(i)

    if cnt1 % 2 == 1:
        print("NO")
    elif cnt1 == 2 and abs(pos[1] - pos[0]) == 1:
        print("NO")
    else:
        print("YES")
