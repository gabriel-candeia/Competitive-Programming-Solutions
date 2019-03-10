f = [0]*26
d = []
x = input()

for i in x:
	f[ord(i)-97]+=1
for i in f:
	if(i):
		d.append(i)		
#
d.sort(reverse=True)
print(d)
tam = len(d)
qtd = sum(d)

#
acm = qtd;
for i in range(d[0]+1,qtd):
	acm *= i
	acm %= 1000000007
print(acm)
#dividir
