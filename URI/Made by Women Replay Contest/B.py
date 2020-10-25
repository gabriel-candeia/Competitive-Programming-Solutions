while True:
    try:
        s = input().lower().split('-')
        cobol = "cobol"
        poss=True
        for i in range(5):
            if(s[i][0]!=cobol[i] and s[i][-1]!=cobol[i]):
                poss = False
        if(poss==True):
            print("GRACE HOPPER")
        else:
            print("BUG")
    except:
        break