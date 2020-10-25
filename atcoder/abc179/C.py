n = int(input())

answ = 0
for i in range(1,n):
    answ += (n-1)//i
print(answ)