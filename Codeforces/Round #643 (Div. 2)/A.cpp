#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll max(ll a,ll b){
    return (a<b) ? b : a;
}

ll min(ll a,ll b){
    return (a<b) ? a : b;
}

int maximalDigit(ll n){
    int mx = 0;
    while(n!=0){
        mx = max(mx,n%10);
        n/=10;
    }
    return mx;
}

int minimalDigit(ll n){
    int mx = 9;
    while(n!=0){
        mx = min(mx,n%10);
        n/=10;
    }
    return mx;
}

int main(){
    ll  t, n, k;
    ll answ=0;

    cin >> t;
    while(t--){
        cin >> n >> k;
        answ = n;
        ll mn=0, mx=0;
        for(int i=0;i<k-1;i++){
            mn = minimalDigit(answ);
            mx = maximalDigit(answ);
            if(mn==0){
                break;
            }
            answ += (mn*mx);
        }
        cout << answ << '\n';
    }

    return 0;
}