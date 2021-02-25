a = int(input())
i = 1
d = 6
cnt = 1

while a > i:
    i += d
    cnt += 1
    d += 6
print(cnt)