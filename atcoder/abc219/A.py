x = int(input())

arr = [40,70,90]
for y in arr:
    if(y>x):
        print(y-x)
        break
if(x>=90):
    print("expert")
