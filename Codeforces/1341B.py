t = int(input())

while(t):
    n, k = [int(x) for x in input().split()]
    arr = [int(x) for x in input().split()]

    picos = [0]*n
    for i in range(1,n):
        picos[i]+=picos[i-1]
        if(i<n-1 and arr[i]>arr[i-1] and arr[i]>arr[i+1]):
            picos[i+1]+=1
    #print(picos)

    mx = 0
    i = 0
    start =0
    while(i+k-1<n):
        if(picos[i+k-1]-picos[i+1] > mx):
            start = i
            mx = picos[i+k-1]-picos[i+1]
        i+=1
        
    print(mx+1,start+1)
    t-=1