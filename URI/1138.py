def conta_digitos(digits,a):
	while(a!=0):
		digits[a%10]+=1
		a//=10

while True:
	digits = [0]*10
	a, b = [int(x) for x in input().split()]
	if(a==0):
		break
	for i in range(a,b+1):
		a = i
		while(a!=0):
			digits[a%10]+=1
			a//=10
	print(digits)


