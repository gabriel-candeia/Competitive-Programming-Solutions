import math as mt

def gcd(a,b):
	if(b==0):
		return a
	return gcd(b,a%b)

acm = 0
n = int(input())
for i in range(1,n//2+1):
	print(i)
	if(gcd(n,i)==1):
		acm+=1
print(acm)