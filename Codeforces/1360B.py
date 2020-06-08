t = int(input())
while(t):
    n = int(input())
    s = [int(x) for x in input().split()]
    s.sort()
    answ = 10000
    for i in range(1,len(s)):
        answ = min(answ,s[i]-s[i-1])
    print(answ)
    t-=1