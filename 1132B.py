n = int(input())
a = [int(x) for x in input().split()]
m = int(input())
q = [int(x) for x in input().split()]

soma = sum(a)
a.sort()

for i in q:
	print(soma-a[-i])