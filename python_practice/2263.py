import sys

sys.setrecursionlimit(int(1e9))
input = sys.stdin.readline

n = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))

inorder_idx = {}

for idx, el in enumerate(inorder):
    inorder_idx[el] = idx

def get_pre(l_in, r_in, l_post, r_post):
    if l_in == r_in:
        print(inorder[l_in], end = ' ')
        return
    root = postorder[r_post]
    print(root, end = ' ')
    l_in_1 = l_in
    idx_in_root = inorder_idx[root]
    r_in_1 = idx_in_root - 1
    l_in_2 = idx_in_root + 1
    r_in_2 = r_in

    l_post_1 = l_post
    r_post_1 = l_post + (r_in_1 - l_in_1)
    l_post_2 = r_post_1 + 1
    r_post_2 = r_post - 1

    if r_in_1 >= l_in:
        get_pre(l_in_1, r_in_1, l_post_1, r_post_1)
    if l_in_2 <= r_in:
        get_pre(l_in_2, r_in_2, l_post_2, r_post_2)

get_pre(0, n-1, 0, n-1)
