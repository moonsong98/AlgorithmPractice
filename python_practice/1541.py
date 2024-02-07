import sys

input = sys.stdin.readline

eq = input().rstrip().split("-")
sum_arr = []

for el in eq:
    sub_eq = list(map(int, el.split("+")))
    sum_arr.append(sum(sub_eq))

print(sum_arr[0] if len(sum_arr) == 1 else sum_arr[0] - sum(sum_arr[1:]))
