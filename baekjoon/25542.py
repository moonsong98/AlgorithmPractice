import sys
from collections import Counter

input = sys.stdin.readline

n, l = list(map(int, input().split()))
data = [input().strip() for _ in range(n)]

is_answer_found = False
for wrong_pos in range(l):
    has_multiple_wrong_poses = False
    wrong_poses = [-1 for _ in range(n)]
    for data_idx in range(1, n):
        for idx in range(l):
            if idx == wrong_pos:
                continue
            if data[0][idx] != data[data_idx][idx]:
                if wrong_poses[data_idx] != -1:
                    has_multiple_wrong_poses = True
                    break
                wrong_poses[data_idx] = idx
        if has_multiple_wrong_poses:
            break
    if has_multiple_wrong_poses:
        continue

    answer_found = True
    ch_in_wrong_pos = ""
    for data_idx in range(1, n):
        if wrong_poses[data_idx] == -1:
            continue
        if ch_in_wrong_pos != "" and data[data_idx][wrong_pos] != ch_in_wrong_pos:
            answer_found = False
            break
        ch_in_wrong_pos = data[data_idx][wrong_pos]

    if not answer_found:
        continue

    print(
        data[0][:wrong_pos]
        + (ch_in_wrong_pos if ch_in_wrong_pos != "" else data[0][wrong_pos])
        + data[0][wrong_pos + 1 :]
    )
    is_answer_found = True
    break

if not is_answer_found:
    print("CALL FRIEND")
