import sys
k = int(input())
for i in range(k):
    a, b = map(int, sys.stdin.readline().split())
    print(a + b)