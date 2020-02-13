def solve(i):
	if(rotina[i]=='0'):
		valor[i] = 0
		solved[i] = True
	else:
		solve((i+1)%n)
		valor[i] = valor[(i+1)%n]+1
		solved[i] = True

n = int(input())
s = input().split()

rotina = ''
solved = [False]*n
valor = [0]*n

for i in s:
	rotina+=i

#print(rotina)

max1 = 0

for i in range(n):
	if(rotina[i]=='0'):
		valor[i]=0
		solved = True
	if(solved[i]==False):
					
	if(valor[i]>max1):
		max1 = valor[i]
print(max1)
