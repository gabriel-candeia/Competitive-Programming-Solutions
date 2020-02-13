n, k = [int(i) for i in input().split()]
arr = [int(i) for i in input().split()]
dic = {}
calls = []
qtd = 0
for i in range(n):
	x = arr[i]
	if(x not in dic or dic[x]<qtd-k):
		dic[x] = qtd
		calls+=[x]
		qtd+=1
st = ""		
for i in range(min(qtd,k)):
	st+=str(calls[qtd-i-1])+' '
print(min(qtd,k))
print(st)


