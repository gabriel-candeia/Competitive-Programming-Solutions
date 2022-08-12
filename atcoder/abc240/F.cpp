#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        vector<ll> x, y;
        ll answ, acm = 0, completo = 0;

        cin >> n >> m;
        x.assign(n,0), y.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> x[i] >> y[i];
        }

        answ = x[0];
        for(int i=0;i<n;i++){
            if(completo>0 && completo+x[i]*y[i]<0){
                ll k = completo/(-x[i]);
                //cout << "fock" << " " << completo << " "  << k <<"\n";
                answ = max(answ,acm + completo*k + x[i]*(k*(k+1))/2);
            }
            acm += completo*y[i] + x[i]*(y[i]*(y[i]+1))/2;
            //cout << acm << "\n";
            answ = max(answ,acm);
            completo += x[i]*y[i];
        }
        cout << answ <<"\n";

    }

    return 0;
}