k1 = int(input())
k2 = int(input())
tmp = []
tmp.append(k2 % 10)
tmp.append((k2 % 100 - tmp[0]) // 10)
tmp.append(k2 // 100)

p1 = k1 * tmp[0]
p2 = k1 * tmp[1]
p3 = k1 * tmp[2]
p4 = p1 + p2 * 10 + p3 * 100

print(p1)
print(p2)
print(p3)
print(p4)