while True:
    a = list(map(int, input().split()))
    if sum(a) == 0:
        break
    max_a = max(a)
    a.remove(max_a)
    if max_a**2 == a[0]**2 + a[1]**2:
        print("right")
    else:
        print("wrong")