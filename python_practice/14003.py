import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

lis = []
lis_idx = []

for el in arr:
    if len(lis) == 0 or lis[-1] < el:
        lis_idx.append(len(lis))
        lis.append(el)
    else:
        l, r = 0, len(lis) - 1

        replaced_idx = 0
        while l <= r:
            mid = l + (r - l) // 2
            if el <= lis[mid]:
                replaced_idx = mid
                r = mid - 1
            else:
                l = mid + 1
        lis_idx.append(replaced_idx)
        lis[replaced_idx] = el

print(len(lis))

cur_idx = len(lis) - 1
real_lis = []

for idx in range(n - 1, -1, -1):
    if cur_idx == -1:
        break
    if lis_idx[idx] == cur_idx:
        real_lis.append(arr[idx])
        cur_idx -= 1

real_lis.reverse()

for el in real_lis:
    print(el, end=" ")
