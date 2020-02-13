n, k = [int(x) for x in input().split()]
horas = [int(x) for x in input().split()]

cont = 0
for i in range(n):
	cont+=(horas[i]<=0)

if(cont>=k):
	print("YES")
else:
	print("NO")
