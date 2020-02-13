from math import ceil
t = int(input())
while(t):
	n = int(input())
	num = [int(i) for i in input().split()]
	print(ceil(sum(num)/n))
	t-=1