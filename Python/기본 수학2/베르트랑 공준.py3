import math

num_list = [True] * (123456 * 2 + 2)
for i in range(1, 123456 * 2 + 1):
    tmp = 0
    if i > 1:
        for j in range(2, int(math.sqrt(i)) + 1):
            if i % j == 0:
                num_list[i] = False
                break

while True:
    N = int(input())

    if N == 0:
        break

    print(sum(num_list[N + 1:2*N +1]))