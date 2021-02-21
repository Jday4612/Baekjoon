N = int(input())
for i in range(N):
    a = list(input())
    cnt = 0
    add = 1
    k = 0
    for j in a:
        if j == 'O':
            if k == 1:
                add += 1
            else:
                add = 1
            k = 1
            cnt += add
        else:
            k = 0
    print(cnt)