#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    vector<ll> a;
    vector<ll> cnt;

    cin >> n;
    a.assign(n,0);
    cnt.assign(32,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    for(int i=0;i<n;i++){
        int ptr = 0;
        while(a[i]){
            cnt[ptr++] += a[i]%2;
            a[i] = a[i]>>1;
        }
    }

    ll asnw=0, acm, pot;
    for(int i=0;i<n;i++){
        acm = 0;
        pot = 1;
        for(int i=0;i<25;i++){
            if(cnt[i]){
                cnt[i]--;
                acm+=pot;
            }
            pot = pot<<1;
        }
        asnw += acm*acm;
    }

    cout << asnw << '\n';

    return 0;
}