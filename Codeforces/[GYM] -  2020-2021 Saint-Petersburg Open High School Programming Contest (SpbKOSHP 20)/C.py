k, n = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]

score = n
qtd = 0
for x in arr:
    if(score==0):
        qtd+=1
        score = n
    if(x<=score):
         score-=x

qtd+=(score==0)
print(qtd)
print(score)