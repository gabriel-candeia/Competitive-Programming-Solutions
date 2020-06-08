from math import tan
from math import pi

t = int(input())
while(t):
    n = int(input())

    alpha = pi*2/(2*n)
    l = tan((pi-alpha)/2)
    print("%.10lf"%l)
    t-=1