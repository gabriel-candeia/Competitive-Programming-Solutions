t = int(input())

while(t):
	n, x, a, b = [int(x) for x in input().split()]
	print(min(n-1,abs(b-a)+x))
	t-=1