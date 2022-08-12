a, b, c = [int(x) for x in input().split()]

if(b<=c and b>=a or b<=a and b>=c):
    print("Yes")
else:
    print("No")