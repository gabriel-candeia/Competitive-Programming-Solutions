from math import ceil

n = int(input())
blocos = ceil((2*n-2)/n)
print(2*4*3**(blocos-1))