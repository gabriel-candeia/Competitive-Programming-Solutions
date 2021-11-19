n = int(input())
arr = [int(x) for x in input().split()]
answ = 0
for x in arr:
    answ += max(x-10,0)
print(answ)