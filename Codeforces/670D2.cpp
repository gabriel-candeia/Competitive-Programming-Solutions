#include<bits/stdc++.h>
#define N int(1e5+3)
#define ll long long
using namespace std;

ll a[N], b[N], n, k, j;

ll max(ll a, ll b){
    return (a<b) ? b : a;
}

bool isOk(ll x, ll k){
    ll acm=0;
    for(int i=0;i<n;i++){
        acm += max(0,a[i]*x - b[i]);
        if(acm>k){
            return false;
        }
    }
    if(acm<0){
        cout << "not stonks\n";
    }
    return acm<=k;
}

int main(){
    vector<pair<int,int>> arr;
    int cnt=0, lim=0, acm=0;
    ll l=0, r=0, med, answ=0;

    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        r = max(r,(b[i]+k)/a[i]);
    }

    while(l<=r){
        med = l + (r-l)/2;
        if(isOk(med,k)){
            answ = med;
            l  = med+1;
        }
        else{
            r = med-1;
        }
    }

    cout << answ  <<'\n';

    return 0;
}