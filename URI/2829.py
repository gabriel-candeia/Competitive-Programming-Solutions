def comp1(a):
	return a[1]

n = int(input())
words = []

for i in range(n):
	temp = input()
	words.append((temp,temp.lower()))

words.sort(key=comp1)

for i in range(1,n):
	j=i
	while(j and (words[j][1]==words[j-1][1]) and (words[j][0]<words[j-1][0])):
		temp = words[j]
		words[j] = words[j-1]
		words[j-1] = temp
		j-=1

for i in range(n):
	print(words[i][0])
	