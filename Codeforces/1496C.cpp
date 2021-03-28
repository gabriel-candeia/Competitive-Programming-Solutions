#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;

    cin >> t;
    while(t--){
        ll n;
        vector<ll> x, y;
        cin >> n;

        for(ll i=0,a,b;i<2*n;i++){
            cin >> a >> b;
            if(a==0)
                y.push_back(abs(b));
            else
                x.push_back(abs(a));
        }

        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        double answ = 0;
        for(int i=0;i<n;i++){
            answ += sqrt(x[i]*x[i]+y[i]*y[i]);
        }
        cout << fixed << setprecision(10) << answ <<'\n';
    }

    return 0;
}