#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = int(1e9)+7;

int n, x;
vector<ll> c;

void read(){
    cin >> n >> x;
    c.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
}

int solve(){
    vector<ll> cnt(x+1,0);
    cnt[0] = 1;

    for(int i=1;i<=x;i++){
        for(auto val:c){
            if(i>=val){
                cnt[i] = (cnt[i] + cnt[i-val])%mod;
            }
        }
    }

    return cnt[x];
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    cout << solve() << '\n';
    return 0;
}
