numeric = ['.','0','1','2','3','4','5','6','7','8','9']

def format(s):
    answ = "|"
    for i in s:
        if(i in numeric):
            answ+=i
        else:
            answ+="|"*1*(answ[-1]!='|')
    return answ

def toNumber(s):
    arr = s.split(".")
    answ = ""
    for i in arr[:-1]:
        answ += i
    if(len(arr[-1])==2 and len(arr)>=2):
        answ+= "."+arr[-1]
    else:
        answ += arr[-1]
    return(float(answ))

def toString(x):
    s = ""
    start = 4
    resto = str(x).split('.')
    if(len(resto)==2 and resto[1]!='0'):
        if(len(resto[1])==1):
            resto[1]+='0'
        s = resto[1][1] + resto[1][0] + '.'
    if(x<1):
        s+='0'
    x = int(x)
    i=1
    while(x):
        if(i==start):
            s+="."
            start+=3
        s += str(x%10)
        x//=10
        i+=1
    
    return s[::-1]

s = format(input()).split('|')[1:]
print(toString(sum([toNumber(x) for x in s])))
