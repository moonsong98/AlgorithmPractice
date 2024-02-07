import sys

input = sys.stdin.readline

t = int(input())
arr = []

while t:
    num = int(input())
    arr.append(num) if num else arr.pop()
    t -= 1

print(sum(arr))
