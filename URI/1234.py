while True:
	try:
		x = input()
		y = True
		for i in x:
			if(i==' '):
				print(i,end='')
				continue
			if(y):
				print(i.upper(),end='')
				y = False
			else:
				print(i.lower(),end='')
				y = True
		print()
	except:
		break
