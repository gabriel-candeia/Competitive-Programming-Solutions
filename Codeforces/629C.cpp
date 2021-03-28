#include<bits/stdc++.h>
#define maxn 2005
#define ll long long
using namespace std;

const ll mod = 1e9+7;
ll mn = 0, dp[maxn][maxn], n, m;
string s;

void solve(){
    dp[0][0] = 1;
    for(int i=1;i<maxn;i++){
        for(int j=0;j<=i;j++){
            if(j+1<maxn)
                dp[i][j] = dp[i-1][j+1];
            if(j-1>=0)
                dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod;
        }
    }
}

tuple<ll,ll> f(string s){
    vector<char> st;
    ll op=0, cl=0;

    for(auto c:s){
        if(st.size()==0 || c=='(' || st.back()==')')
            st.push_back(c);
        else
            st.pop_back();
    }

    for(auto c:st){
        if(c=='(')
            op++;
        else 
            cl++;
    }
    
    return {cl,op};
}

int main(){    
    cin >> n >> m >> s;
    solve();

    ll answ  = 0, cl, op;
    tie(cl, op) = f(s);

    for(int i=0;i<=n-m;i++){
        for(int j=cl;j<=i;j++){
            if(j-cl+op < maxn)
                answ = (answ + (dp[i][j]*dp[n-m-i][(j-cl)+(op)])%mod)%mod;
        }
    }
    
    cout << answ <<'\n';
    return 0;
}