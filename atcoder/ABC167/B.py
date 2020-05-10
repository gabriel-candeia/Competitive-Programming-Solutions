a, b, c, k = [int(x) for x in input().split()]

if(a+b>=k):
    print(min(a,k))
else:
    print(a-(k-(a+b)))