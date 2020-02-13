n = int(input())
arr = []
for i in range(n):
	arr+=[int(input())]

if(max(arr)==arr[0]):
	print("S")
else:
	print("N")