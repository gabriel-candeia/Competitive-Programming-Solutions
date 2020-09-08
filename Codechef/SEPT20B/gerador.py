from random import randint

def resp(arr):
	acm = 0
	for i in arr:
		acm^=i
	return acm

def func(arr, x):
	acm=0
	for i in arr:
		acm+=i^x
	return acm


t = 2
answ = []
print(t)
while(t):
	n = randint(1,1000)
	arr = [randint(1,1000000) for i in range(n)]


	print(len(arr))
	print(func(arr,1))
	for i in range(1,20):
		print(func(arr,2**i+1))
	t-=1

	answ+=[resp(arr)]
print(answ)
'''
t = 1
answ = []
print(t)
while(t):
	n = randint(1,1000)
	arr = [1,2,3,4]


	print(len(arr))
	print(func(arr,1))
	for i in range(1,20):
		print(func(arr,2**i+1))

	t-=1

	answ+=[resp(arr)]
print(answ)
'''
