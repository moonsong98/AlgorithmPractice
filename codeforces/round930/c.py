import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))


def check(a, b, c, d):
    print(f"? {a} {b} {c} {d}")
    sys.stdout.flush()
    return input().strip()


def answer(a, b):
    print(f"! {a} {b}")
    sys.stdout.flush()


def solve():
    n = int(input())

    if n == 2:
        answer(0, 1)
        return

    # debug

    max_index = 0

    for i in range(0, n):
        res = check(0, max_index, 0, i)
        if res == "<":
            max_index = i

    min_indices = [max_index]
    for i in range(0, n):
        res = check(max_index, min_indices[0], max_index, i)
        if res == "<":
            min_indices = [i]
        elif res == "=":
            min_indices.append(i)

    min_index = min_indices[0]
    for i in min_indices:
        if i == max_index:
            continue
        res = check(min_index, min_index, min_index, i)
        if res == "=":
            min_index = i

    answer(max_index, min_index)


T = int(input())

for _ in range(T):
    solve()
