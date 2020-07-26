t = int(input())

for casos in range(t):
    n, k = [int(x) for x in input().split()]
    a = [k-int(i)%k for i in input().split() if(int(i)%k!=0)]
    a.sort()
    n = len(a)

    if(n==0):
        print(0)
    else:
        cnt = 1
        mxfreq = 1
        mxval = a[0]
        for i in range(1,len(a)):
            if(a[i]==0):
                continue
            if(a[i]!=a[i-1]):
                if(cnt>=mxfreq):
                    mxval = a[i-1]
                    mxfreq = cnt
                cnt = 1
            else:
                cnt+=1

        if(cnt>=mxfreq):
            mxval = a[n-1]
            mxfreq = cnt

        #print(mxfreq, mxval)
        print((mxfreq-1)*k+mxval+1)