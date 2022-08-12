a, b, c, d = [int(x) for x in input().split()]

if(a<c or (a==c and b<=d)):
    print("Takahashi")
else:
    print("Aoki")
