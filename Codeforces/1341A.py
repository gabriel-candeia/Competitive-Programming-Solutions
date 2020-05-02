t = int(input())
while(t):
    x, y = [int(x) for x in input().split()]
    a, b = [int(x) for x in input().split()]

    print(min(a*x+a*y,b*(min(x,y)) + a*abs(y-x)))
    
    t-=1