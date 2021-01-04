def bb(x):
    l=1
    r=x
    answ =0
    med = 0
    while(l<=r):
        med = l+(r-l)//2
        if((med*(med+1))//2<=x+1):
            answ = med
            l = med+1
        else:
            r = med-1
    return answ


n = int(input())
k = bb(n)
print(n-k+1)