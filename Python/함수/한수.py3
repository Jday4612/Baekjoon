N = int(input())
numbers = []

for i in range(1, N+1):
    if 0 < i < 100:
        numbers.append(i)
    elif 100 <= i < 1000:
        w = [i // 100, (i // 10) % 10, i % 10]
        if w[0] - w[1] == w[1] - w[2]:
            numbers.append(i)
    elif i == 1000:
        break

print(len(numbers))