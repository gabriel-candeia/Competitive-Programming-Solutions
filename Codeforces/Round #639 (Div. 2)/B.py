arr = [2]
h = 1

t = int(input())
for i in range(t):
    n = int(input())

    while(arr[-1] <= n):
        h+=1
        arr.append(arr[-1]+h*2+h-1)
    
    cnt = 0
    i = len(arr)-1
    while(i>=0):
        if(arr[i]<=n):
            cnt += n//arr[i]
            n = n%arr[i]
        i-=1
    print(cnt)
