
dic = {'P':1,'M':2,'G':3,1:'P',2:'M',3:'G'}
a = True	
while(True):
	n = int(input())
	if(n==0):
		break
	if(a==False):
		print()
	a = False
	names = []
	for i in range(n):
		nome = input()
		cor, tam = input().split()
		names+= [(cor,dic[tam],nome)]
	names.sort()
	s = ''
	for i in names:
		s+=i[0]+' '+dic[i[1]]+' '+i[2]+'\n'
	print(s,end='')

