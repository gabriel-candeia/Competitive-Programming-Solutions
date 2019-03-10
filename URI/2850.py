while True:
	try:
		ent = input()
		if(ent=="esquerda"):
			print("ingles")
		elif(ent=="direita"):
			print("frances")
		elif(ent=="nenhuma"):
			print("portugues")
		else:
			print("caiu")
	except:
		break