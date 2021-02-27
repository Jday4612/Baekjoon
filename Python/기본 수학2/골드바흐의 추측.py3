import math

num_list = [True] * (10000 + 2)
for i in range(1, 10000 + 1):
    tmp = 0
    if i > 1:
        for j in range(2, int(math.sqrt(i)) + 1):
            if i % j == 0:
                num_list[i] = False
                break

T = int(input())
for k in range(T):
    N = int(input())
    a = N // 2
    b = N // 2
    while True:
        if num_list[a] == True and num_list[b] == True:
            break
        a -= 1
        b += 1
    print(str(a) + " " + str(b))