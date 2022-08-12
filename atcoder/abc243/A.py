v, a, b, c = [int(x) for x in input().split()]
v = v%(a+b+c)
if(v<a):
    print("F")
elif(a<=v and v<a+b):
    print("M")
else:
    print("T")