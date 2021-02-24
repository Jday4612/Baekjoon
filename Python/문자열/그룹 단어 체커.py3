answer = 0

for i in range(int(input())):
    word = input()
    answer += list(word) == sorted(word, key = word.find)

print(answer)