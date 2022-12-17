#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1000000007;

int main(){
    int t, caso=0;
    cin >> t;
    while(t--){
        ll acmDot = 0, acmX = 0, acmY = 0;
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            ll x, y;
            cin >> x >> y;
            acmDot = (acmDot + x*x + y*y)%mod;
            acmX = (acmX + x)%mod;
            acmY = (acmY + y)%mod;
        }

        ll totalAnsw = 0;
        int q;
        cin >> q;
        while(q--){
            ll x, y;
            cin >> x >> y;
            ll answ = acmDot;
            answ = (answ + n*((x*x+y*y)%mod))%mod;
            answ = (answ -2*((x*acmX+y*acmY)%mod))%mod;
            totalAnsw = (totalAnsw+answ)%mod;
        }

        if(totalAnsw<0) totalAnsw += mod;

        cout << "Case #" << ++caso << ": " << totalAnsw << "\n";
    }

    return 0;
}