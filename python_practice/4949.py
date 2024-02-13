import sys

input = sys.stdin.readline

while True:
    s = input().rstrip()

    if len(s) == 1:
        break

    arr = []

    flag = 0

    for c in s:
        if c == "[" or c == "(":
            arr.append(c)
        elif c == "]" or c == ")":
            if len(arr) == 0:
                print("no")
                flag = 1
                break
            elif (
                c == ")"
                and arr[len(arr) - 1] != "("
                or c == "]"
                and arr[len(arr) - 1] != "["
            ):
                print("no")
                flag = 1
                break
            arr.pop()

    if flag:
        continue
    print("no" if len(arr) else "yes")
