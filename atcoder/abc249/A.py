a, b, c, d, e, f, x = [int(x) for x in input().split()]

d1 = (x//(a+c))*b*a + min(x%(a+c),a)*b
d2 = (x//(d+f))*e*d + min(x%(d+f),d)*e

if(d1>d2):
    print("Takahashi")
elif(d1<d2):
    print("Aoki")
else:
    print("Draw")