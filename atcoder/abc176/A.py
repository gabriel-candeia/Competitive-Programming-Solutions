n, x, t = [int(i) for i in input().split()]

print((n//x + (n%x!=0))*t)