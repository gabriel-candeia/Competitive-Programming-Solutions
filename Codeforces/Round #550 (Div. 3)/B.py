n = int(input())
num = [int(x) for x in input().split()]
even = [x for x in num if(x%2==0)]
odd = [x for x in num if(x%2==1)]

start = 1
if(len(even)>len(odd)):
	start = 0

odd.sort()
even.sort()

while(len(even) and len(odd)):
	if(start):
		odd.pop()
		start = 0
	else:
		even.pop()
		start = 1

if(start==1 and len(odd)):
	odd.pop()
if(start==0 and len(even)):
	even.pop()

soma=sum(even)+sum(odd)

print(soma)

