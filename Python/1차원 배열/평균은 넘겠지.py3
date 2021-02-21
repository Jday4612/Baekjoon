N = int(input())
for i in range(N):
    s = 0
    cnt = 0
    a = list(map(int, input().split()))
    for j in range(1, a[0] + 1):
        s += a[j]
    s /= a[0]
    for k in range(1, a[0] + 1):
        if a[k] > s:
            cnt += 1
    cnt = cnt / a[0] * 100
    print(str("%.3f" % cnt) + "%")