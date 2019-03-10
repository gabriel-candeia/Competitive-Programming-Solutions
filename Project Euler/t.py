def rot(x):
	for y in range(2,x):
		if(x%y==0):
			print(y)
			while(x%y==0):
				x = x/y
		if(x==1): break


rot(int(input()))