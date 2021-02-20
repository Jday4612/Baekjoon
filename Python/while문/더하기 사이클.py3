N = int(input())
cnt = 0
A = N
K = 0
while True:
    K = A // 10 + A % 10
    A = (A % 10) * 10 + (K % 10)
    cnt += 1
    if A == N:
        break
print(cnt)