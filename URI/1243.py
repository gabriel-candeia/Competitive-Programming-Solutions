def ehpalavra(s):
	tam = 0
	n = len(s)
	for i in range(n):
		if(ord('a')<=ord(s[i])<=ord('z') or ord('A')<=ord(s[i])<=ord('Z')):
			tam+=1
		elif(i!=n-1 or s[i]!='.'):
			return 0;
	return tam;

while True:
	try:
		palavras = input().split()
		acm = 0
		count = 0
		for i in palavras:
			inc = ehpalavra(i)
			count += (inc!=0)
			acm += inc
		acm  = acm//count if (count!=0) else 0
		if(acm<=3):
			print(250)
		elif(acm<=5):
			print(500)
		else:
			print(1000)	
	except:
		break	
