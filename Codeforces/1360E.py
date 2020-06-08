t = int(input())
while(t):
    mat  = []

    n = int(input())
    for i in range(n):
        mat.append([])
        mat[i].extend(input())

    poss = True 
    for i in range(n-1):
        for j in range(n-1):
            if(mat[i][j]=='1' and mat[i+1][j]=='0' and mat[i][j+1]=='0'):
                poss = False
    
    if(poss):
        print("YES")
    else:
        print("NO")

    t-=1