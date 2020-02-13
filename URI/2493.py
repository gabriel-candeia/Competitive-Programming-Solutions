while True:
	try:
		n = int(input())
		expressions = []
		for i in range(n):
			expressions+=[input().split("=")]
			expressions[i]=[int(x) for x in expressions[i][0].split()]+[int(expressions[i][1])]
		#print(expressions)
		respostas = []
		jogadores = {}
		perdedores = []
		for i in range(n):
			respostas+=[input().split(" ")]
			jogadores[respostas[i][0]]=0
		#print(respostas)
		#teste
		for i in respostas:
			jogador = i[0]
			op = i[2]
			item = int(i[1])-1
			poss = False
			if(expressions[item][0]+expressions[item][1]==expressions[item][2] or expressions[item][0]*expressions[item][1]==expressions[item][2] or expressions[item][0]-expressions[item][1]==expressions[item][2]):
				poss = True
			if(op=='+'and expressions[item][0]+expressions[item][1]==expressions[item][2]):
				poss = True
			elif(op=='*'and expressions[item][0]*expressions[item][1]==expressions[item][2]):
				poss = True
			elif(op=='-'and expressions[item][0]-expressions[item][1]==expressions[item][2]):
				poss = True
			elif(op=='I' and poss==False):
				pass
			else:
				perdedores+=[jogador]
		perdedores.sort()

		if(len(perdedores)==len(jogadores)):
			print("None Shall Pass!")
		elif(len(perdedores)):
			for i in perdedores:
				print(i,end='')
				if(i!=perdedores[-1]): print(" ",end='')
			print()
		else:
			print("You Shall All Pass!")
	except:
		break
