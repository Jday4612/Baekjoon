n = int(input())
for i in range(n):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    d = ((x2 - x1)**2 + (y2 - y1)**2)**0.5
    r_1 = r1 + r2
    r_2 = abs(r1 - r2)

    if d == 0:
        if r1 == r2:
            print(-1)
        else:
            print(0)
    else:
        if d == r_1 or d == r_2:
            print(1)
        elif d < r_1 and d > r_2:
            print(2)
        else:
            print(0)