import sys
a, b = map(int, sys.stdin.readline().split())

while True:
    print(a+b)
    a, b = map(int, sys.stdin.readline().split())
    if a == 0 and b == 0:
        break