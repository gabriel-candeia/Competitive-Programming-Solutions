def compare(a):
	return -a[0], a[1] 

t = int(input())
while(t):
	n, k = [int(x) for x in input().split()]
	volumes = []
	for i in range(n):
		dim = [int(x) for x in input().split()]
		volumes.append((dim[1]*dim[2]*dim[3],dim[0]))
	#tem que ordenar decrescente pelo primeiro elemento e crescente pelo segundo
	volumes.sort(key = compare)
	#print(volumes)
	aux = []
	for i in range(k):
		aux.append(volumes[i][1])
	aux.sort()
	for i in range(k):
		print(aux[i],end='')
		if(i!=k-1):
			print(end=' ')
	print()
	t-=1