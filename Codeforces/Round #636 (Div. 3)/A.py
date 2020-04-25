def find(n):
    for k in range(2,32):
        if(n%(2**k-1)==0):
            return n//(2**k-1)

t = int(input())
while(t):
    n = int(input())
    print(find(n))
    t-=1