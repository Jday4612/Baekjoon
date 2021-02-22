def solve(n):
    for x in list(str(n)):
        n += int(x)
    return n

checklist = []

for i in range(1, 10001):
    checklist.append(solve(i))

for j in range(1, 10001):
    if j in checklist:
        pass
    else:
        print(j)