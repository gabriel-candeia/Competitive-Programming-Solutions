from math import pi
from math import sqrt
from math import cos
from math import sin

def alpha(M,H):
    return (M/H)*2*pi

def point(alpha,B):
    return [B*cos(alpha),B*sin(alpha)]

A, B, H, M  = [int(x) for x in input().split()]

a1 = alpha(M,60)
a2 = alpha(H,12)+alpha(M/60,12)

p1 = point(a1,B)
p2 = point(a2,A)

print(sqrt((p1[0]-p2[0])**2+(p1[1]-p2[1])**2))