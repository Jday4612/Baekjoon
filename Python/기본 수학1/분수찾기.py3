n = int(input())
i = 1

while n > i:
    n -= i
    i += 1

if i % 2 == 0:
    a = n
    b = i - n + 1
else:
    a = i - n + 1
    b = n

print(a, '/', b, sep='')