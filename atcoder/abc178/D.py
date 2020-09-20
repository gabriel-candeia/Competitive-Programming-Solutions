mod = int(1e9+7)
dp = [-1]*(3000)
def cnt(n):
    if(n<3):
        return (n==0)
    if(dp[n]!=-1):
        return dp[n]
    dp[n]=0
    for i in range(3,n+1):
        dp[n]=(dp[n]+cnt(n-i))%mod
    return dp[n]

s = int(input())
print(int(cnt(s)))   
