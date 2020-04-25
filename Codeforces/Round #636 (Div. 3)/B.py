t = int(input())
while(t):
    n = int(input())
    if((n//2)%2==0):
        print("YES")
        arr = []
        for i in range(2,n+1,2):
            arr.append(i)
        for i in range(1,n+1,2):
            arr.append(i)
        arr[-1]+=n//2
        for i in arr:
            print(i,end=" ")
        print()
    else:
        print("NO")
    t-=1