n = []
max = 0
cnt = 0
for i in range(9):
    n.append(int(input()))
    if n[i] > max:
        max = n[i]
        cnt = i+1
print(max)
print(cnt)