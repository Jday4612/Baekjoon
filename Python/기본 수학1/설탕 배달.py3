n = int(input())
i = 0

while True:
    if n < 0:
        print(-1)
        break
    if n % 5 == 0:
        i += n//5
        print(i)
        break
    n -= 3
    i += 1