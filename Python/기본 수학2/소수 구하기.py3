import math

M, N = map(int, input().split())

for i in range(M, N+1):
    tmp = 0
    if i > 1:
        for j in range(2, int(math.sqrt(i)) + 1):
            if i % j == 0:
                tmp = -1
                break
        if tmp == 0:
            print(i)