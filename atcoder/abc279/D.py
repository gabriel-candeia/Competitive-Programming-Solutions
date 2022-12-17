import math as mt
A, B = [int(x) for x in input().split()]
x = (A/(2*B))**(2/3)

piso = max(mt.floor(x),1)
teto = max(mt.ceil(x),1)

def f(x):
    return A/((x)**(1/2)) + B*(x-1)

answ = min(f(teto),f(piso))
print("%.10f" % answ)

