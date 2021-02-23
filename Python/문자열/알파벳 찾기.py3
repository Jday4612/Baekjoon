N = list(input())
wordlist = []
wordnum = []
alb = "abcdefghijklmnopqrstuvwxyz"

for i in N:
    wordlist.append(i)

for c in alb:
    for j in range(len(wordlist)):
        if c == wordlist[j]:
            wordnum.append(j)
            break
        elif j < len(wordlist) - 1:
            continue
        else:
            wordnum.append(-1)
for k in wordnum:
    print(k, end=" ")