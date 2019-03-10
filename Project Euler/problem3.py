import math as mt;

def rot(x):
	for y in range(2,x):
		if(x%y==0):
			print(y)
			while(x%y==0):
				x = x/y
		if(x==1): break

def rotOpt(x):
	while(x%2==0):
		x = x/2
	for y in range(3,mt.ceil(sqrt(x)),2):
		if(x%y==0):
			print(y)
			while(x%y==0):
				x = x/y
		if(x==1): break


rotOpt(int(input()))

