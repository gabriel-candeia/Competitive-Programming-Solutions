v = input().split()
n = int(v[0])
m = int(v[1])
p = 1
b = []
soma = 0

pr = input().split()

for k in pr:
  p *= int(k)

dict = {}

for k in pr:
  b.append(p/int(k))
  dict[int(k)] = b[-1]
  soma += b[-1]

t = input().split()
p2 = 1
vis = {}

for k in t:
  p2 *= int(k)

for k in pr:
  if p2%int(k) == 0:
    soma -= p/int(k)

if soma == p2:
  print('S')
else:
  print('N')


