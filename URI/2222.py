T = int(input())
while(T):
	T-=1
	n = int(input())
	sets = [0]*n
	for i in range(n):
		ent = [int(x) for x in input().split()]
		for j in ent[1:]:
			sets[i] += 2**(j-1)
	Q = int(input())
	for i in range(Q):
		op, x, y = [int(x) for x in input().split()]
		if(op==1):
			print(str(bin(sets[x-1]&sets[y-1])).count('1'))
		else:
			print(str(bin(sets[x-1]|sets[y-1])).count('1'))
