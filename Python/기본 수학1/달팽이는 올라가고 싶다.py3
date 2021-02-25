a, b, v = map(int,input().split())

if (v - a) % (a - b) == 0:
    i = int((v - a) / (a - b))
else:
    i = int((v-a) / (a - b) + 1)
print(i + 1)