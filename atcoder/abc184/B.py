n, x = [int(x) for x in input().split()]
s = input()

for c in s:
    if(c=='o'):
        x+=1
    else:
        x = max(x-1,0)

print(x)