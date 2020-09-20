mod = int(1e9+7)
def pot(a, b):
    result = 1
    while(b):
        if(b%2):
            result=(result*a)%mod
        a=(a*a)%mod
        b//=2
    return result

n = int(input())
print((2*(pot(10,n)-pot(9,n))-(pot(10,n)-pot(8,n)))%(mod))