p = []
c = []

n, k = [int(x) for x in input().split()]
p = [int(x)-1 for x in input().split()]
c = [int(x) for x in input().split()]
best = [c[x] for x in p]

i = 0
while(i<n):
    d = [0]*n
    visited = [0]*n
    cnt = 0
    j=i
    answ=0
    last=i
    while(cnt<k and visited[j]==False):
        cnt+=1
        visited[j] = cnt
        d[j] = answ
        last = j
        j = p[j]
        answ+=c[j]
        best[i] = max(best[i],answ)
    
    k1 = max(k-cnt,0)
    cycle = visited[last]-visited[j]+1
    answ += (answ-d[j])*(k1//cycle)
    best[i] = max(best[i],answ)
    k1 = k1%cycle
    while(k1>0):
        j = p[j]
        answ+=c[j]
        best[i] = max(best[i],answ)
        k1-=1
    i+=1

x = max(best)

print(max(best))



