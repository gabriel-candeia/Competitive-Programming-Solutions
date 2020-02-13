from math import ceil
v, n = [int(i) for i in input().split()]
string = ''
for i in range(1,10):
	string += ' '+str(ceil(v*n*i/10))
print(string[1:])