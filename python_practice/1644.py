import math

n = int(input())

if n == 1:
    print(0)

else:
    is_prime = [True] * (n + 1)

    for i in range(2, int(math.sqrt(n)) + 1):
        if not is_prime[i]:
            continue
        j = 2
        while i * j <= n:
            is_prime[i * j] = False
            j += 1

    prime = []
    for i in range(2, n + 1):
        if is_prime[i]:
            prime.append(i)

    l, r, cur_sum = 0, 0, prime[0]
    num_prime = len(prime)
    ans = 0

    while True:
        if cur_sum < n:
            r += 1
            if r == num_prime:
                break
            cur_sum += prime[r]

        if cur_sum >= n:
            if cur_sum == n:
                ans += 1
            cur_sum -= prime[l]
            l += 1
            if l == num_prime:
                break
            if l > r:
                r += 1
                cur_sum += prime[r]

    print(ans)
