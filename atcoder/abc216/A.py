arr = input().split('.')

x = ord(arr[-1])-ord('0')
if(x<=2):
    print(arr[0],'-',sep='')
elif(x<=6):
    print(arr[0],sep='')
else:
    print(arr[0],'+',sep='')