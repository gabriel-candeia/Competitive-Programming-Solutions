n = int(input())
ent = input()

minA=-1
for i in range(n):
	minC=-1
	for j in range(i+1,n):
		minT=-1
		for k in range(j+1,n):
			minG = -1
			for u in range(k+1,n):
				if((ord(ent[u])-ord('G'))%26<minG or minG==-1):
					minG = (ord(ent[u])-ord('G'))%26
			if((ord(ent[k])-ord('T'))%26+minG<minT or minT==-1):
				minT = (ord(ent[k])-ord('T'))%26+minG
		if((ord(ent[j])-ord('C'))%26+minT<minC or minC==-1):
			minC = (ord(ent[j])-ord('C'))%26+minT
	if((ord(ent[i])-ord('A'))%26+minC<minA or minA==-1):
		minA = (ord(ent[i])-ord('A'))%26+minC
print(minA)

