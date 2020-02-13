def converter(b):
	last = b[0]
	acm = ""
	a = []
	for i in b:
		if(i==last):
			acm += i
		else:
			a+=[acm]
			acm = i
	a+=[acm]
	return a

dic = {}
n, m =[int(x) for x in input().split()]

for i in range(m):
	a, b = input().split()
	dic[a] = converter(b)

st = ["A"]
for i in range(n):
	st1 = []
	for i in range(len(st)):
		st1 += dic[st[i]]
	st = [st1[0]]
	for i in st1[1:]:
		if(i[0]==st[-1][0]):
			st[-1]+=i
		else:
			st+=[i]
answ = ""
for i in st:
	answ +=	 i
cont = answ.count('A')
print(cont, len(answ)-cont)