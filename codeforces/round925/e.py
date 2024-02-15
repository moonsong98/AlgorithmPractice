import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

T = int(input())

while T:
    n, m = list(map(int, input().split()))
    arr = list(input().rstrip().split())

    arr_num_zero = []

    for el in arr:
        el = el[::-1]
        cnt = 0
        for digit in el:
            if digit != '0':
                break
            cnt += 1
        arr_num_zero.append((len(el), cnt))
    
    arr_num_zero = sorted(arr_num_zero, key=lambda x: -x[1])
    s = 0
    for idx in range(n):
        s += arr_num_zero[idx][0]
        if idx % 2 == 0:
            s -= arr_num_zero[idx][1]
    
    print("Sasha" if s > m else "Anna")

    T -= 1