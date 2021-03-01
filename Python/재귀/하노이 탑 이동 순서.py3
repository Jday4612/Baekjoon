def hanoi(start, stop, end, N):
    if N >= 1:
        hanoi(start, end, stop, N - 1)
        print(start, end)
        hanoi(stop, start, end, N - 1)

N = int(input())
print(2**N - 1)

if 1 <= N <= 20:
    hanoi(1, 2, 3, N)