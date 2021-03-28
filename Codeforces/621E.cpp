#include<bits/stdc++.h>
#define ll long long
#define maxn 105
using namespace std;

const ll mod = 1e9+7;
ll n, b, k, x, temp;
vector<ll> cnt;

ll solve(){
    ll pot = 10;
    vector<ll> result(maxn,0), temp(maxn,0); b--;

    for(int i=0;i<x;i++)
        result[i] = cnt[i];
    
    while(b){
        if(b%2){
            temp.assign(maxn,0);
            for(int i=0;i<x;i++)
                for(int j=0;j<x;j++)
                    temp[(i*pot+j)%x] = (temp[(i*pot+j)%x]+(result[i]*cnt[j])%mod)%mod;
            result = temp;
        }
        temp.assign(maxn,0);
        for(int i=0;i<x;i++)
            for(int j=0;j<x;j++)
                temp[(i*pot+j)%x] = (temp[(i*pot+j)%x]+ (cnt[i]*cnt[j])%mod)%mod;
        pot = (pot*pot)%x;
        
        cnt = temp;
        b/=2;  
    }
    return result[k];
}

int main(){
    cin >>  n >> b >> k >> x;
    cnt.assign(maxn,0);
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        cnt[t%x]++;
    }
    cout << solve() <<'\n';
}