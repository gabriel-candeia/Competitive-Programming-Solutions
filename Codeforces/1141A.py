n, m = [int(x) for x in input().split()]

if(m==n):
	print(0)
elif(m%n==0):
	aux = m//n
	cont = 0
	if(aux%2==0 or aux%3==0):
		while(aux%2==0):
			cont += 1
			aux = aux//2
		while(aux%3==0):
			cont += 1
			aux = aux//3
		if(aux!=1):
			print(-1)
		else:
			print(cont)
	else:
		print(-1)
else:
	print(-1)