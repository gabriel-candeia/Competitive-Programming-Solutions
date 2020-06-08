#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = int(1e9)+7;

int x, n;
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

    for(auto cost : c){
        //with repetitions
        for(int i=1;i<=x;i++){
            if(i>=cost){
                cnt[i] = (cnt[i] + cnt[i-cost])%mod;
            }
        }
        //without repetitions
        /*for(int i=x;i>=1;i--){
            if(i>=cost){
                cnt[i] = (cnt[i] + cnt[i-cost])%mod;
            }
        }*/
    }

    return cnt[x];
}

int main(){

    read();
    cout << solve() << '\n';

    return 0;
}