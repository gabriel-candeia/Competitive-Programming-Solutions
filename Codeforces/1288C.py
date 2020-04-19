from math import factorial as fact

def comb(n,k):
    return (fact(n)//(fact(k)*fact(n-k)))


n, m = [int(x) for x in input().split()]
M = 1000000007
print(comb(n+2*m-1,2*m)%M)