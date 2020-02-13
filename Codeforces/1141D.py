qm1 = []
qm2 = []

dic = {}

rm1 = []
rm2 = []

pairs = []

n = int(input())
temp = input()
s1 = []
for i in temp:
	if(i!=' '):
		s1+=i
temp = input()
s2 = []
for i in temp:
	if(i!=' '):
		s2+=i

for i in range(n):
	if(s1[i]=='?'):
		qm1.append(i)
	elif(s1[i] not in dic):
		dic[s1[i]]=[i]
	else:
		dic[s1[i]].append(i)
	if(s2[i]=='?'):
		qm2.append(i)

for i in range(n):
	if((s2[i] in dic) and len(dic[s2[i]])):
		pairs.append((dic[s2[i]].pop(),i))
	else:
		if(s2[i]!='?'):
			rm2.append(i)

for i in dic:
	rm1+=dic[i]

while(len(qm1)and len(rm2)):
	pairs.append((qm1.pop(),rm2.pop()))
while(len(qm2)and len(rm1)):
	pairs.append((rm1.pop(),qm2.pop()))
while(len(qm2)and len(qm1)):
	pairs.append((qm1.pop(),qm2.pop()))

print(len(pairs))
for a, b in pairs:
	print(a+1,b+1)