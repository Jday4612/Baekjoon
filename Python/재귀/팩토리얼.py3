n=int(input())

def facto(n):
    if n <= 1:
        return 1
    else:
        return facto(n-1)*n

print(facto(n))