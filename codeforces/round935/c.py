import sys
import math

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

t = int(input())


def round(x):
    frac = x - math.floor(x)
    if frac < 0.5:
        return math.floor(x)
    return math.ceil(x)


while t:
    t -= 1
    n = int(input())
    s = input().strip()
    psuml = [0]
    psumr = [0]
    for ch in s:
        if ch == "0":
            psuml.append(psuml[-1] + 1)
        else:
            psuml.append(psuml[-1])
        if ch == "1":
            psumr.append(psumr[-1] + 1)
        else:
            psumr.append(psumr[-1])

    ansl = -1
    for i in range(n // 2 + 1):
        if psuml[i] - psuml[0] >= round(i / 2) and psumr[n] - psumr[i] >= round(
            (n - i) / 2
        ):
            ansl = i
    ansr = -1
    for i in range(n, n // 2, -1):
        if psuml[i] - psuml[0] >= round(i / 2) and psumr[n] - psumr[i] >= round(
            (n - i) / 2
        ):
            ansr = i

    # print(psuml)
    # print(psumr)
    # print("cand", ansl, ansr)
    if ansl == -1:
        print(ansr)
        # print("ans", ansr)
    elif ansr == -1:
        print(ansl)
        # print("ans", ansl)
    else:
        print(ansl if n / 2 - ansl <= ansr - n / 2 else ansr)
        # print("ans", ansl if n / 2 - ansl <= ansr - n / 2 else ansr)
