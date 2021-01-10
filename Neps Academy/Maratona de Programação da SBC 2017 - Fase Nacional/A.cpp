#include<bits/stdc++.h>
#define maxn int(1e3+5)
using namespace std;

string s;
int dp[maxn][maxn], path[maxn][maxn], n, answ[maxn];
int solve(int i, int j){
    if(i==s.size())
        return !j;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j] = 0;
    if(s[i]!='?'){
        answ[i] = s[i]-'0';
        dp[i][j] = solve(i+1,(j*10 + s[i]-'0')%n);
    }
    else{
        for(int k=(i==0) ? 1 : 0;k<10;k++){
            int temp = solve(i+1,(j*10 + k)%n);
            if(temp==1){
                dp[i][j] = temp;
                answ[i] = k;
                break;
            }
        }
    }
    return dp[i][j];
}

int main(){
    cin >> s >> n;
    memset(dp,-1,sizeof(dp));
    if(solve(0,0)){
        for(int i=0;i<s.size();i++)
            cout << answ[i];
        cout<<'\n';
    }
    else{
        cout << "*" <<'\n';
    }
    return 0;
}