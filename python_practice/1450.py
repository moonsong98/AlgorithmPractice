import sys

input = sys.stdin.readline

n, c = list(map(int, input().split()))
arr = list(map(int, input().split()))

par_sum_1, par_sum_2 = [], []
arr_1, arr_2 = arr[: n // 2], arr[n // 2 :]


def get_par_sum(in_box, is_one, idx):
    end_idx = len(arr_1) if is_one else len(arr_2)
    if idx == end_idx:
        s = sum(in_box)
        par_sum_1.append(s) if is_one else par_sum_2.append(s)
        return
    get_par_sum(in_box, is_one, idx + 1)
    in_box.append(arr_1[idx] if is_one else arr_2[idx])
    get_par_sum(in_box, is_one, idx + 1)
    in_box.pop()

get_par_sum([], True, 0)
get_par_sum([], False, 0)

par_sum_1.sort()
par_sum_2.sort()

l, r = 0, len(par_sum_2) - 1
ans = 0

while True:
    s = par_sum_1[l] + par_sum_2[r]
    if s > c:
        r -= 1
        if r == -1:
            break
    else:
        ans += (r+1)
        l += 1
        if l == len(par_sum_1):
            break
print(ans)
'''
ans = 0
    
for el in par_sum_1:
    if el > c:
        continue
    l, r = 0, len(par_sum_2) - 1
    left = c - el
    amount = 0
    while l <= r:
        mid = l + (r-l)//2
        if par_sum_2[mid] <= left:
            amount = mid
            l = mid + 1
        else:
            r = mid - 1
    ans += (amount+1)
        
print(ans)
'''