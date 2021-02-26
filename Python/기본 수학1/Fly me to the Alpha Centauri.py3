t = int(input())
for i in range(t):
    x, y = map(int, input().split())
    z = y - x
    a = 1
    b = 1

    while z > 0:
        z -= a
        a += 1
        if z >= b:
            z -= b
            b += 1
    print(a + b - 2)
