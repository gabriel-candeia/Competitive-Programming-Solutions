#include<bits/stdc++.h>
#define maxn int(3005)
#define ll long long
using namespace std;

string s, t;
ll dp[maxn][maxn], n, m;
char answ[maxn][maxn];

string solve(ll n, ll m){
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s[i]==t[j]){
                dp[i][j] = dp[i+1][j+1]+1;
                answ[i][j] = '\\';
            }
            else if(dp[i+1][j]>dp[i][j+1]){
                dp[i][j] = dp[i+1][j];    
                answ[i][j] = 'V';
            }
            else{
                dp[i][j] = dp[i][j+1];    
                answ[i][j] = '-';
            }
        }
    }

    string resp = "";
    for(int i=0,j=0;i<n && j<m;){
        if(answ[i][j]=='\\'){
            resp+=s[i];
            i++; j++;
        }
        else if(answ[i][j]=='V')
            i++;
        else
            j++;
    }

    return resp;
}

int main(){
    cin >> s >> t;
    n = s.size(); m = t.size();

    cout << solve(n,m) <<'\n';
    return 0;
}