n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]


curr = 0
arr = []
visited = [False]*n
while(not visited[curr]):
    visited[curr] = True
    arr.append(curr)
    curr = a[curr]-1

visited = [False]*n
cycleSize = 0
while(not visited[curr]):
    visited[curr] = True
    cycleSize+=1
    curr = a[curr]-1

pathSize = len(arr) - cycleSize

if(pathSize>=k):
    print(arr[k]+1)
else:
    print(arr[(k-pathSize)%cycleSize+pathSize]+1)