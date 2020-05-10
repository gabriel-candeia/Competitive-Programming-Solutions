from math import ceil

t = int(input())
for i in range(t):
    n, k = [int(x) for x in input().split()]
    i = ceil(k/(n-1))-1
    num = n*i+1
    answ = (n-1)*i+1
    print(num+k-answ)
