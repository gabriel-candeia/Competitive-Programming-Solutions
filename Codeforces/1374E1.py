n, k = [int(x) for x in input().split()]

both = []
bob = []
alice = []

for i in range(n):
    t, a, b = [int(x) for x in input().split()]
    if(a==1 and b==1):
        both.append(t)
    elif(a==1):
        alice.append(t)
    elif(b==1):
        bob.append(t)

both.sort()
bob.sort()
alice.sort()
y = max(k-min(len(bob),len(alice)),0)

soma_both=0
sa = 0
sb = 0

poss = (len(both)+min(len(alice),len(bob))>=k)
if(poss):
    for i in range(y):
        soma_both+=both[i]

    for i in range(max(k-y,0)):
        sa += alice[i]

    for i in range(max(k-y,0)):
        sb += bob[i]

    ptr1 = k-y
    ptr2 = k-y

    resposta = sa+sb+soma_both
    for i in range(y,len(both)):
        ptr1-=1
        ptr2-=1
        if(ptr2==-1 or ptr1==-1):
            break
        soma_both+=both[i]
        sa-=alice[ptr1]
        sb-=bob[ptr2]
        if(soma_both+sa+sb>=0):
            resposta = min(resposta,soma_both+sa+sb)
    print(resposta)
else:
    print(-1)
