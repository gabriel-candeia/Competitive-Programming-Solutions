t = int(input())
for i in range(t):
    n = int(input())
    a = [int(x) for x in input().split()] 
    entradas = [0]*n
    for i in range(len(a)):
        entradas[(i+a[i])%n]+=1
    poss = True
    for x in entradas:
        if(x!=1):
            poss = False
    if(poss):
        print("YES")
    else:
        print("NO")