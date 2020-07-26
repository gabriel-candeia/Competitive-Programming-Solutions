def converter(s,n):
    pilha = []
    for c in s:
        if(c=='(' or len(pilha)==0):
            pilha.append(c)
        elif(pilha[-1]=='(' and c==')' ):
            pilha.pop()
        else:
            pilha.append(c)
    return len(pilha)//2

t = int(input())
for caso in range(t):
    n = int(input())
    s = input()
    print(converter(s,n))

