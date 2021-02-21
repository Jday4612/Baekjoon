import sys

X = int(input())
A = sys.stdin.readline().split()
min, max = int(A[0]), int(A[X-1])
for i in range(X):
    A[i] = int(A[i])
    if A[i] > max:
        max = A[i]
    if A[i] < min:
        min = A[i]
print(str(min) + " " + str(max))