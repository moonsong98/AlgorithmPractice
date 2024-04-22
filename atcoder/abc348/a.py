import sys

input = sys.stdin.readline

n = int(input())

for i in range(n):
    print("x" if i % 3 == 2 else "o", end="")
