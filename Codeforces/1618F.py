def reverse(a):
    acm = 0
    while(a!=0):
        acm = 2*acm + a%2
        a = a//2
    return acm

a, b = [int(x) for x in input().split()]

q = [a]
i = 0
d = {}
d[a] = 1

while(i<len(q) and i<5000):
    x = q[i]
    if(x==b):
        break
    if(reverse(x) not in d):
        d[reverse(x)] = 1
        q.append(reverse(x))

    if((2*x+1 <=b or reverse(2*x+1)<=b) and reverse(2*x+1) not in d):
        d[reverse(2*x+1)] = 1
        q.append(reverse(2*x+1))

    i = i+1
#print(i)
if(b in d):
    print("YES")
else:
    print("NO")

