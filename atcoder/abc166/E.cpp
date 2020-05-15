#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n, a;
    map<ll,int> cnt1, cnt2;

    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> a;
        cnt1[i+a]++;
        cnt2[i-a]++;
    }

    ll acm = 0, qtd;
    for(auto p:cnt1){
        qtd = cnt2[p.first];
        acm += qtd*(p.second);
    }  

    cout << acm << '\n';

    return 0;
}
