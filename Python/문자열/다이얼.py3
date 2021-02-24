apb = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ']
n = input()
time = 0

for i in apb:
    for j in i:
        for k in n:
            if j == k:
                time += apb.index(i) + 3

print(time)