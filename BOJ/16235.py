import sys
from collections import deque
import heapq

input = sys.stdin.readline


def solution():
    n, m, k = list(map(int, input().split()))
    a = [list(map(int, input().split())) for _ in range(n)]
    trees = [[deque() for _ in range(n)] for _ in range(n)]
    dead_trees = [[deque() for _ in range(n)] for _ in range(n)]
    energy = [[5] * n for _ in range(n)]

    for _ in range(m):
        y, x, age = list(map(int, input().split()))
        y -= 1
        x -= 1
        trees[y][x].append(age)

    dy = [0, 0, 1, 1, 1, -1, -1, -1]
    dx = [-1, 1, -1, 0, 1, -1, 0, 1]
    for yy in range(k):
        # spring
        for i in range(n):
            for j in range(n):
                if len(trees[i][j]) == 0:
                    continue
                alive_trees = []
                for _ in range(len(trees[i][j])):
                    tree = trees[i][j].popleft()
                    if energy[i][j] >= tree:
                        alive_trees.append(tree + 1)
                        energy[i][j] -= tree
                    else:
                        dead_trees[i][j].append(tree)

                if len(alive_trees) > 0:
                    trees[i][j] = deque(alive_trees)

        # summer
        for i in range(n):
            for j in range(n):
                if dead_trees[i][j] == False:
                    continue
                while len(dead_trees[i][j]):
                    tree = dead_trees[i][j].popleft()
                    energy[i][j] += tree // 2

        # fall
        for i in range(n):
            for j in range(n):
                if trees[i][j] == False:
                    continue
                for tree in trees[i][j]:
                    if tree % 5 == 0:
                        for d in range(8):
                            ny, nx = i + dy[d], j + dx[d]
                            if not (0 <= ny and ny < n and 0 <= nx and nx < n):
                                continue
                            trees[ny][nx].appendleft(1)

        # winter
        for i in range(n):
            for j in range(n):
                energy[i][j] += a[i][j]

    answer = 0
    for i in range(n):
        for j in range(n):
            if trees[i][j] == False:
                continue
            answer += len(trees[i][j])

    print(answer)


solution()
