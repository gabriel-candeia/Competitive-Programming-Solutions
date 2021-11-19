n = int(input())
arr = [int(x)-1 for x in input().split()]
resposta = [0]*n

for i in range(n):
    resposta[arr[i]] = i+1

for i in range(n):
    print(resposta[i]," ",sep="",end="")
print()