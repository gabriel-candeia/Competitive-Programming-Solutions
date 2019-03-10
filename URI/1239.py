while True:
	try:
		x = input()
		a = False
		b = False
		for i in x:
			if(i=='*'):
				print("</b>",end='') if(a) else print("<b>",end='')
				a = not a
			elif(i=='_'):
				print("</i>",end='') if(b) else print("<i>",end='')
				b = not b
			else:
				print(i,end='')
		print()
	except:
		break
