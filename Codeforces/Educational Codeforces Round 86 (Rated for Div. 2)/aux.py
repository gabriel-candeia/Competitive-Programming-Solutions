def mod(x,a,b):
    return ((x%a)%b)

a, b = [int(x) for x in input().split()]
l, r = [int(x) for x in input().split()]

arr = [mod(i,a,b)!=mod(i,b,a) for i in range(l,r+1)]
print(arr)
print(sum(arr))
    