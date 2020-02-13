inc = []
dec = []

n = int(input())
num = [int(x) for x in input().split()]

pos = True

num.sort()
for i in num:
	if((len(inc)==0) or i>inc[-1]):
		inc.append(i)
	elif((len(dec)==0) or i>dec[-1]):
		dec.append(i)
	else:
		pos = False

if(pos):
	print("YES")
	print(len(inc))
	for i in inc:
		print(i,end=' ')
	if(len(inc)==0):
		print()
	else:
		print()
	dec.sort(reverse = True)
	print(len(dec))
	for i in dec:
		print(i,end=' ')
	if(len(dec)==0):
		print()
	else:
		print()
else:
	print("NO")