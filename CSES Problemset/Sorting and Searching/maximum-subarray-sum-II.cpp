#include<bits/stdc++.h>
#define ll long long
#define D(x) cout << #x << "=" << x << '\n'
using namespace std;

ll max(ll a, ll b){
    return (a<b) ? b : a;
}

int main(){
    ll n, a, b, answ = 0, temp=0, acm = 0;
    vector<ll> x, sum, best;

    cin >> n >> a >> b;
    x.assign(n,0);
    best.push_back(0);
    for(int i=0;i<n;i++){
        cin >> x[i];
        if(i<=a-1){
            temp+=x[i];
        }
        else if(i<b){
            acm+=x[i];
            best[0] = max(best[0],acm);
        }
    }

    sum.push_back(temp);
    answ = sum[0]+best[0];
    for(int i=1;i+a-1<n;i++){
        sum.push_back(sum[i-1]+x[i+a-1]-x[i-1]);
        acm -= x[i+a-1];
        if(i+b-1<n){
            acm += x[i+b-1];
        }
        best.push_back(max(best[i-1]-x[i+a-1]*1ll*(best[i-1]!=0),acm));
        best[i] = max(best[i],0);
        answ = max(answ,sum[i]+best[i]);
        D(best[i]);
        D(sum[i]);  
    }

    cout << answ <<'\n';

    return 0;
}