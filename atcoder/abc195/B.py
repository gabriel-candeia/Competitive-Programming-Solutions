a, b, w = [int(x) for x in input().split()]
w *= 1000
mx = -1
mn = 1e10
for i in range(1,w+1):
    if(a<=w/i<=b):
        mn = min(mn,i)
        mx = i

if(mx==-1):
    print("UNSATISFIABLE")
else:
    print(mn, mx)