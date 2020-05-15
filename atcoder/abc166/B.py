n ,k = [int(x) for x in input().split()]
dg = [0]*(n+1)
while(k):
    di = int(input())
    a = [int(x) for x in input().split()]
    for i in a:
        dg[i]+=1
    k-=1

cnt = -1
for i in dg:
    cnt+=(i==0)
print(cnt)
