'''
    (y2-0)/(x2-x0) = d
    (y1-0)/(x1-x0) = -(y2-0)/(x2-x0)
    y1*x2-y1*x0 = x0*y2-x1*y2
    y1*x2+x1*y2 = x0(y1+y2)
    x0 = (y1*x2+x1*y2)/((y1+y2))
'''
x1, y1, x2, y2 = [int(x) for x in input().split()]
print((y1*x2+x1*y2)/(y1+y2))