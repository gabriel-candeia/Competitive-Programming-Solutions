def sign(x):
    return (x>0)

t = int(input())

while(t):
    n = int(input())
    
    #leitura do array em uma linha
    arr = [int(x) for x in input().split()]

    sum=0
    maiorAtual = arr[0]
    ultimo = arr[0]

    for i in arr[1:]:
        if(sign(i)==sign(ultimo)):
            maiorAtual = max(maiorAtual,i)
        else:
            sum+=maiorAtual
            maiorAtual = i
        ultimo = i

    sum+=maiorAtual
    print(sum)
    t-=1