n = int(input())

x = 1
qtd = 0
answ = 0
while(1000*x-1<=n):
    answ += qtd*(1000*x-x)
    qtd += 1
    x *= 1000

answ += qtd*(n-x+1)
print(answ)