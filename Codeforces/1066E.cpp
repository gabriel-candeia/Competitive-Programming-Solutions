#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;

int main(){
    int n, m, ptr;
    vector<int> a, b;
    ll pw=1, answ=0, acm=0;
    char x;
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> x;
        a.push_back(x-'0');
    }
    for(int i=0;i<m;i++){
        cin >> x;
        b.push_back(x-'0');
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    for(int i=0; i<m; i++){
        if(i < n && a[i]==1){
            acm = (acm+pw)%mod;
        }
        if(b[i]==1){
            answ = (answ+acm)%mod;
        }
        pw = (pw+pw)%mod;
    }

    cout << answ << '\n';

    return 0;
}