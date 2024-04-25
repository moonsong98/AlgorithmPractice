import sys

input = sys.stdin.readline

N = int(input())
num_list = list(map(int, input().split()))

# max: 10**18 ~ 2**60
rank = 0
for x in range(60, -1, -1):
    if rank == N:
        break
    if ~num_list[rank] & (1 << x):
        found = False
        for alternate_num in range(rank + 1, N):
            if num_list[alternate_num] & (1 << x):
                num_list[rank], num_list[alternate_num] = (
                    num_list[alternate_num],
                    num_list[rank],
                )
                found = True
        if not found:
            continue
    for i in range(N):
        if i == rank:
            continue
        if num_list[i] & (1 << x):
            num_list[i] ^= num_list[rank]
    rank += 1

ans = 0
for el in num_list:
    ans ^= el

print(ans)
