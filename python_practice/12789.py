import sys

input = sys.stdin.readline

wl = []
out = 1
_ = int(input())
seq = list(map(int, input().split()))

for n in seq:
    while True:
        if len(wl) == 0 or wl[len(wl) - 1] != out:
            break
        wl.pop()
        out += 1

    if n == out:
        out += 1
    else:
        wl.append(n)

while True:
    if len(wl) == 0 or wl[len(wl) - 1] != out:
        break
    wl.pop()
    out += 1


print("Sad" if len(wl) else "Nice")
