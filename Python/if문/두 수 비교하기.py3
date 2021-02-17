c = input().split()
a = int(c[0])
b = int(c[1])
if a > b:
    print(">")
elif a < b:
    print("<")
elif a == b:
    print("==")