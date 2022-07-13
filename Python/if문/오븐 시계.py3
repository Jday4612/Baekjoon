h, m = map(int, input().split())
a = int(input())

if m+a >= 60:
    m = m + a
    while m >= 60:
        h += 1
        m -= 60
else:
    m += a

if h >= 24:
    h -= 24

print(str(h) + " " + str(m))