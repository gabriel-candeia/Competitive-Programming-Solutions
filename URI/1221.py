from math import ceil

def ehprimo(a):
	for i in range(2,ceil((a)**1/2)+1):
		if(a%i==0):
			return False
	return True

a = int(input())
arr = [0]*214748364
print(arr)
while(a):
	n = int(input())
	if(ehprimo(n)):
		print("Prime")
	else:
		print("Not Prime")
	a-=1