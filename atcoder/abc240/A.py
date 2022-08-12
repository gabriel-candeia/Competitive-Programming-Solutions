a, b = [int(x) for x in input().split()]
if(a>b):
    c = a
    a = b
    b = c
if(b-a==1 or a==1 and b==10):
    print("Yes")
else:
    print("No")
