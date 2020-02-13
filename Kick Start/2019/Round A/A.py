t = int(input())
while(t):
	a, b = [int(x) for x in input().split()]
	n = int(input())
	l, r = [a,b]
	s = ""
	while(s!="CORRECT"):
		mid = l + (r-l)//2
		print(mid)
		s = input()
		if(s=="TOO_SMALL"):
			l = mid+1
		elif(s=="TOO_BIG"):
			r = mid
	t-=1
