from math import ceil
t = int(input())
while(t):
    n, k = [int(x) for x in input().split()]
    s = input()
    s = list(s)
    s.sort()

    if(s[0]!=s[k-1] or k==n):
        print(s[k-1])
    else:
        poss = True
        for i in range(k+1,len(s)):
            if(s[k]!=s[i]):
                poss = False
        if(poss):
            print(str(s[0])+"".join(s[k]*ceil((n-k)/k)))
        else:
            print(str(s[0])+"".join((s[k:]) ))
    t-=1