N = int(input())
a = input().split()

max = 0
for i in range(N):
    a[i] = int(a[i])
    if a[i] > max:
        max = a[i]

sum = 0
for j in range(N):
    a[j] = a[j] / max * 100
    sum += a[j]
print(sum / N)