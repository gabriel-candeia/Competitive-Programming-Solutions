n = int(input())
for i in range(n):
    s = input().split()
    s.sort()
    answ = ""
    last = "-1"
    for i in s:
        if(i!=last):
            answ += i+" "
        last = i
    print(answ[:-1])

