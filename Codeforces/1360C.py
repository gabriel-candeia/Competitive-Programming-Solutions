t = int(input())
while(t):
    n = int(input())
    a = [int(x) for x in input().split()]

    cntPar = 0
    for x in a:
        cntPar += (x%2==0)
    cntImpar = n - cntPar

    if(cntPar%2==0):
        print("YES")
    else:
        cnt = [0]*110

        poss = False
        for x in a:
            cnt[x] = True
            if(cnt[x-1] or cnt[x+1]):
                poss = True

        if(poss):
            print("YES")
        else:
            print("NO")
    t-=1