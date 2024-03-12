import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

T = int(input())

while T:
    T -= 1
    n = int(input())
    arr = list(map(int, input().split()))

    if 0 not in arr or arr == [0] * n:
        print(n)
        for i in range(1, n + 1):
            print(i, i)
        continue

    cnt = {0: 0}
    for i in range(n):
        if arr[i] in cnt:
            cnt[arr[i]] += 1
        else:
            cnt[arr[i]] = 1

    check_num = 0
    has_one = False
    for i in range(0, n):
        if i not in cnt:
            break
        if cnt[i] == 1:
            has_one = True
            break

        check_num = i

    if has_one:
        print(-1)
        continue

    l, r = 0, -1
    has_check_num = False
    check2 = [False] * (check_num + 1)
    cnt_in = 0
    for idx in range(n):
        if arr[idx] <= check_num:
            if check2[arr[idx]] == False:
                cnt_in += 1
                check2[arr[idx]] = True
        if cnt_in == check_num + 1:
            r = idx
            break

    sub_arr = arr[r + 1 : n]
    check2 = [False] * (check_num + 1)
    for el in sub_arr:
        if el <= check_num:
            check2[el] = True

    valid = True
    for el in check2:
        if el == False:
            valid = False
            break

    if not valid:
        print(-1)
    else:
        print(2)
        print(1, r + 1)
        print(r + 2, n)
