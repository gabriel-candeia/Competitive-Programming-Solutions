while True:
    try:
        n = int(input())
        for i in range(n):
            s = input().split()
            letra = 3*(len(s)-1)+len(s[0])-1+ord('a')
            print(chr(letra))
    except:
        break

