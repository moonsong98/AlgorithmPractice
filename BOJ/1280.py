import sys
import math

input = sys.stdin.readline


def query(tree, node, start, end, left, right):
    if left > end or right < start:
        return (0, 0)
    if left <= start and end <= right:
        return tree[node]
    l_result = query(tree, node * 2, start, (start + end) // 2, left, right)
    r_result = query(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right)
    return (l_result[0] + r_result[0], l_result[1] + r_result[1])


def update_tree(tree, node, start, end, pos):
    if pos < start or end < pos:
        return
    tree[node] = (tree[node][0] + 1, tree[node][1] + pos)
    if start != end:
        update_tree(tree, node * 2, start, (start + end) // 2, pos)
        update_tree(tree, node * 2 + 1, (start + end) // 2 + 1, end, pos)


def update(tree, pos):
    update_tree(tree, 1, 0, 2 * 10**6 - 1, pos)


max_N = 2 * 10**6
MOD = 1000000007
N = int(input())
pos = []
for _ in range(N):
    pos.append(int(input()))

h = math.ceil(math.log(max_N, 2))
tree_size = 1 << (h + 1)
tree = [(0, 0) for _ in range(tree_size)]

ans = 1
update(tree, pos[0])
for el in pos[1:]:
    l = query(tree, 1, 0, 2 * 10**6 - 1, 0, el - 1)
    r = query(tree, 1, 0, 2 * 10**6 - 1, el + 1, 2 * 10**6 - 1)
    ans *= (l[0] * el - l[1]) + (r[1] - r[0] * el)
    ans %= MOD
    update(tree, el)

print(ans)
