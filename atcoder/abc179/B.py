answ = 0
cnt  = 0
n = int(input())
for i in range(n):
    a , b = [int(x) for x in input().split()]
    if(a==b):
        cnt+=1
    else:
        cnt=0
    answ = max(answ,cnt)

if(answ>=3):
    print("Yes")
else:
    print("No")
