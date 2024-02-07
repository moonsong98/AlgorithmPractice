import sys

input = sys.stdin.readline

t = int(input())


def func():
    arr = []
    s = input().rstrip()
    for c in s:
        if c == "(":
            arr.append(c)
        elif len(arr):
            arr.pop()
        else:
            print("NO")
            return
    print("YES" if len(arr) == 0 else "NO")


while t:
    func()
    t -= 1
