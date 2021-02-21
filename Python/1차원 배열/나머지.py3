a = []
for j in range(10):
    a.append(int(input()) % 42)

b = []
for i in range(43):
    b.append(a.count(i))
    
cnt = 0
for i in range(43):
    if b[i] >= 1:
        cnt +=1
print(cnt)