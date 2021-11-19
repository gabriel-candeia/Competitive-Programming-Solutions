arr = [""]*3
for i in range(3):
    arr[i] = input()
t = input()
for c in t:
    ind = ord(c)-ord('0')-1
    print(arr[ind],sep='',end='')
print()