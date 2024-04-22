import sys

input = sys.stdin.readline


def solve():
    a, b, c = list(map(int, input().split()))

    bin_c = str(bin(c))[-1:1:-1]
    num_ones_c = bin_c.count("1")
    ans_a, ans_b = "", ""

    for el in bin_c:
        if a == 0 and b == 0 and num_ones_c > 0:
            print(-1)
            return
        if el == "0":
            if a > 0 and b > 0 and a + b - 2 >= num_ones_c:
                ans_a += "1"
                ans_b += "1"
                a -= 1
                b -= 1
            else:
                ans_a += "0"
                ans_b += "0"
        else:
            ans_a += "1" if a > b else "0"
            ans_b += "0" if a > b else "1"
            if a > b:
                a -= 1
            else:
                b -= 1
            num_ones_c -= 1
    if a != b:
        print(-1)
        return

    while a:
        ans_a += "1"
        ans_b += "1"
        a -= 1

    ans_a, ans_b = int(ans_a[::-1], 2), int(ans_b[::-1], 2)

    if ans_a >= 2**60 or ans_b >= 2**60:
        print(-1)
    else:
        print(ans_a, ans_b)


solve()
