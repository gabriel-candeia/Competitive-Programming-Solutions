arr = []
for i in range(3):
    s = input()
    arr += [s]

resposta = ["ABC","ARC","AGC","AHC"]
for x in resposta:
    if(x not in arr):
        print(x)