t = int(input())
for i in range(t):
    k = int(input())
    n = int(input())
    z = 0
    a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]

    for j in range(k):
        for m in range(1, n):
            a[m] += a[m-1]
    print(a[n-1])