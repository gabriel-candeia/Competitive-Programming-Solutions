from math import sqrt

t = int(input())
while(t):
    n, k = [int(x) for x in input().split()]
    
    lim = int(sqrt(n))+1
    answ = 1
    for i in range(1,lim):
        if(n%i==0):
            if(n//i<=k):
                answ = max(answ,n//i)
            elif(i<=k):
                answ = max(answ,i)

    print(n//answ)

    t-=1