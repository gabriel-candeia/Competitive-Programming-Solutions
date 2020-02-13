while True:
	try:
		c, n = [int(x) for x in input().split()]
		s1 = input()
		s2 = input()
		dic = {}

		for i in range(c):
			dic[s2[i]]=s1[i]
			dic[s2[i].lower()]=s1[i].lower()
			dic[s1[i]]=s2[i]
			dic[s1[i].lower()]=s2[i].lower()

		#print(dic)

		for i in range(n):
			ent = input()
			for j in ent:
				if(j in dic):
					print(dic[j],end='')
				else:
					print(j,end='')
			print()
		print()
	except:
		break

