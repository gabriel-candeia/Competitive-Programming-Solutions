t = int(input())
for caso in range(t):
    n = int(input())
    x = 0
    y = 0

    while(n%2==0):
        n/=2
        x+=1

    while(n%3==0):
        n/=3
        y+=1

    if(x<=y and n==1):
        print(y-x + y)
    else:
        print(-1)