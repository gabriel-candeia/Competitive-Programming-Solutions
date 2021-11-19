a, b, c = [int(x) for x in input().split()]
x = b-b%c
if(x>=a):
    print(x)
else:
    print(-1)
