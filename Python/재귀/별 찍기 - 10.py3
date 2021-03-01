n = int(input()) # n = 3^k (1 <= k < 8)
star = ["***", "* *", "***"]
cnt = 0

def get_stars(star):
    star_list = []
    for i in range(3 * len(star)):
        if i // len(star) == 1:
            star_list.append(star[i % len(star)] + " " * len(star) + star[i % len(star)])
        else:
            star_list.append(star[i % len(star)] * 3)
    return(list(star_list))

while n != 3:
    n = n // 3
    cnt += 1

for i in range(cnt):
    star = get_stars(star)
for j in star:
    print(j)