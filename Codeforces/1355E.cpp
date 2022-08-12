#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, a, b, m, sum=0, acm=0, answ=0;
    vector<ll> arr;

    cin >> n >> a >> b >> m;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x, sum+=x;
    answ = b*(sum-n);
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-1;i++){
        acm += arr[i];
        sum -= arr[i];

        answ = min(answ,a*((i+1)*arr[i]-acm) + b*(sum - (n-i-1)*arr[i]));
        answ = min(answ,a*((i+1)*arr[i+1]-acm) + b*(sum - (n-i-1)*arr[i+1]));

        ll x1 = (acm+sum)/n;
        vector<ll> valor = {(acm+sum)/n,(acm+sum)/n+1,arr[i],arr[i+1]};
        for(auto x1:valor){
            if(x1>=arr[i] && x1<=arr[i+1]){
                ll k1 = ((i+1)*x1-acm), k2 = (sum - (n-i-1)*x1);
                ll y1 = min(k1,k2);
                answ = min(answ,m*y1 + a*(k1-y1) + b*(k2-y1));
            }
        }
    }

    if(n==1)
        answ = 0;

    cout << answ <<"\n";

    return 0;
}