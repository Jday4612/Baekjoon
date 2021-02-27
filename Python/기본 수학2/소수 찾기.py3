N = int(input())
num_list = list(map(int, input().split()))
cnt = 0

for i in num_list:
    tmp = 0

    if i == 1:
        continue
    else:
        for j in range(2, i):
            if i % j == 0:
                tmp = -1
                break

    if tmp == 0:
        cnt += 1
print(cnt)