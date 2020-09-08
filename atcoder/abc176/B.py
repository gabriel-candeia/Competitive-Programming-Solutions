s = input()
acm = 0

for i in s:
    acm = (acm + ord(i)-ord('0'))%9

if(acm):
    print("No")
else:
    print("Yes")