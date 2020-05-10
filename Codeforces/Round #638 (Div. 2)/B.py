t = int(input())
while(t):
    n, k = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    
    diff = set(a)
    if(len(diff)<=k):
        m = k*n
        print(m)
        arr = list(diff)
        for i in range(n):
            for j in range(k):
                print(arr[j%len(diff)],end=' ')
        print()
    else:
        print(-1)

    t-=1
