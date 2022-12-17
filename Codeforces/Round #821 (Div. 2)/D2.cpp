#include<bits/stdc++.h>
#define maxn int(5005)
#define ll long long
using namespace std;

int n;
string s, t;
ll dp[2][maxn][2][2], x, y;
ll inf = 1e16;

ll solve(){
    for(int credit=0, row = n%2;credit<n;credit++){
        for(int block=0;block<2;block++){
            for(int inv=0;inv<2;inv++){
                if(inv)
                    dp[row][credit][block][inv] = inf;
                else if(credit%2)
                    dp[row][credit][block][inv] = inf;
                else
                    dp[row][credit][block][inv] = 0;
            }
        }
    }
    
    for(int i=n-1;i>=0;i--){
        bool curr = i%2, nxt = 1-curr;
        for(int credit=0;credit<n;credit++){
            for(int block=0;block<2;block++){
                for(int inv=0;inv<2;inv++){
                    auto &val = dp[curr][credit][block][inv];
                    if((s[i]==t[i]) != inv){
                        val = dp[nxt][credit][0][0];
                    }
                    else{
                        val = dp[nxt][credit+1][1][0] + y;
                        if(credit-block>0)
                        val = min(val,dp[nxt][credit-1][0][0]);
                        if(i+1<n)
                            val = min(val,dp[nxt][credit][0][1]+x);
                    }
                }
            }
        }
    }
    return dp[0][0][0][0];
}



int main(){
    int caso;
    cin >> caso;
    while(caso--){
        cin >> n >> x >> y;
        cin >> s >> t;


        int diff = 0;
        for(int i=0;i<n;i++){
            diff += (s[i]!=t[i]);
        }

        if(diff&1){
            cout << -1 <<"\n";
        }
        else{
            cout << solve() <<"\n";
        }
    }

    return 0;
}