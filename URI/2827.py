tokens = {}
i = input().lower()


for j in range(len(i)-1):
	if(i[j]+i[j+1] in tokens):
		tokens[i[j]+i[j+1]] += 1
	else:
		tokens[i[j]+i[j+1]] = 1

#print(tokens)

maior = 0
for i in tokens:
	if(tokens[i]>maior):
		maior = tokens[i]
		maiorT = i
	if(tokens[i]==maior):
		if(i<maiorT):
			maiorT=i

print(maiorT,":",maior,sep='')
