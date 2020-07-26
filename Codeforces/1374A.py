t = int(input())
for caso in range(t):
    x, y, n = [int(x) for x in input().split()]
    res = -1
    if(n%x<y):
        n = (n-(n%x))-1
    if(n%x>=y):
        res = n - (n%x-y)
    print(res)