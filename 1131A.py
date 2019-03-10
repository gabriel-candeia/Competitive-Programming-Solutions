w1, h1, w2, h2 = [int(x) for x in input().split()]

area = 2*(w1+h1+w2+h2) - 2*min(w1,w2) + 4

print(area)