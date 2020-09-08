n = int(input())
arr = [int(x) for x in input().split()]

acm = 0
for i in range(1,n):
    acm += max(-arr[i]+arr[i-1],0)
    arr[i] = max(arr[i],arr[i-1])
    
print(acm)