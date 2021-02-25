k = int(input())
for i in range(k):
    h, w, n = map(int, input().split())
    j = 1
    while 0 < n:
        if n - h <= 0:
            break
        n -= h
        j += 1
    print(100 * n + j)