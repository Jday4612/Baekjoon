k = int(input())
for i in range(1, k+1):
    for j in range(k-i):
        print(" ", end="")
    for t in range(i):
        print("*", end="")
    print("")