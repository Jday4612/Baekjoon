N = input().upper()
a = list(set(N))
b = []
for i in a:
    tmp = N.count(i)
    b.append(tmp)

if b.count(max(b)) > 1:
    print("?")
else:
    print(a[b.index(max(b))])