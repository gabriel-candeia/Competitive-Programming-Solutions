t = int(input())
while(t):
    a, b = [int(x) for x in input().split()]
    if(2*min(a,b)>=max(a,b)):
        print((2*min(a,b))**2)
    else:
        print((max(a,b))**2)
    t-=1