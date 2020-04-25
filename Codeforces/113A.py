def classification(s):
    isWord = False
    gender = 0
    tipo = 0
    
    feminino = ["liala","etra","inites"]
    masculino = ["lios","etr","initis"]

    for i in range(3):
        if(s.endswith(feminino[i])):
            gender = 1
            tipo = i
            isWord = True
        elif(s.endswith(masculino[i])):
            tipo = i
            isWord = True
    return [isWord,gender,tipo]

words = [classification(s) for s in input().split()]
areWords = [x[0] for x in words]
gender = [x[1] for x in words]
tipo = [x[2] for x in words]

poss = True
for i in areWords:
    if(i==0):
        poss = False

if(poss):
    last = gender[0]
    for i in gender[1:]:
        if(i!=last):
            poss = False
            break
        last = i

if(poss):
    last = tipo[0]
    for i in tipo[1:]:
        if(i<last):
            poss = False
            break
        last = i

if(poss):
    cnt1 = 0
    for i in tipo:
        if(i==1):
            cnt1+=1
    if(cnt1!=1):
        poss = False

if(len(words)==1 and areWords[0]==True):
    poss = True

if(poss):
    print("YES")
else:
    print("NO")