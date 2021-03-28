#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m, answ=0, a, b;
    vector<ll> items;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        items.push_back(b);
    }

    sort(items.rbegin(),items.rend());
    ll i=0, j=0;
    for(i=1;i*(i-1)/2+1<=n;i+=2);
    for(j=0;(j-1)*j/2+j/2<=n;j+=2);
    i-=2; j-=2;
    for(int k=0;k<min(m,max(i,j));k++){
        answ += items[k];
    }
    cout << answ <<'\n';

    return 0;
}