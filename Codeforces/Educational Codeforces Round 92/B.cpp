#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t, n, k, z;

    cin >> t;
    while(t--){
        cin >> n >> k >> z;
        vector<ll> a(n+1,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        if(k==1)
            cout << a[0]+a[1] <<'\n';
        else{
            ll best = 0, answ = a[0], prox;
            pair<ll,ll> mx = {0,0};
            for(int i=1;i<=k;i++){
                if(a[i]+a[i-1]>mx.first+mx.second){
                    mx.first = a[i-1];
                    mx.second = a[i];
                    prox = i+1;
                }
                answ+=a[i];
                best = max(best,answ+(mx.first+mx.second)*min(z,(k-i)/2) + max(mx.first,a[prox]*(prox<=i))*(min(z,(k-i)/2)<z && (k-i)%2));
            }
            cout << best <<'\n';
        }
    }

    return 0;
}