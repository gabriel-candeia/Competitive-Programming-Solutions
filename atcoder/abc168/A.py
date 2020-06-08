n = int(input())

if(n%10==3):
    print("bon")
elif(n%10 in [0, 1, 6, 8]):
    print("pon")
else:
    print("hon")
