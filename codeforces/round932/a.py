import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

T = int(input())

while T:
    T -= 1
    n = int(input())
    str = input().strip()
    rev_str = str[::-1]

    if str <= rev_str:
        print(str)
    else:
        print(rev_str + str)
