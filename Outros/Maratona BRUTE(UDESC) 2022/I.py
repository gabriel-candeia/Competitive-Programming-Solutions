def max(x, y):
    if(x>y):
        return x
    return y

arr = input().split('&')
aux = []
for x in arr:
    novo = x.split('|')
    novo[0] = novo[0][1:]
    novo[-1] = novo[-1][:-1]
    aux.append(novo)
mx = len(aux[0])
for x in aux:
    mx = max(mx,len(x))
mx = min(mx,3)
print(mx,"-SAT",sep="")