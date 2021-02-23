N = int(input())

for i in range(N):
    X = input().split()
    k = int(X[0])
    tmp = ""
    for j in list(X[1]):
        tmp += j * k
    print(tmp)