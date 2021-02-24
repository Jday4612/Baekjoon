apb = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
n = input()

for i in apb:
    n = n.replace(i, '*')
print(len(n))