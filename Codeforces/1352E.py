import collections  
t = int(input())

while(t):
    n = int(input())
    a = [0]
    a.extend([int(x) for x in input().split()])

    dic = collections.OrderedDict()
    for i in range(1,n+1):
        if(a[i] in dic):
            dic[a[i]]+=1
        else:
            dic[a[i]]=1

    for i in range(1,n+1):
        a[i] += a[i-1]

    cnt = 0
    for l in range(0,n+1):
        for r in range(l+1,n+1):
            if(a[r]-a[l-1] in dic):
                cnt+=dic[a[r]-a[l-1]]
                dic.pop(a[r]-a[l-1])

    print(cnt)
    t-=1
