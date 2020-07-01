#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m, x, y;
    vector<ll> num,saltos;

    cin >> n >> m;
    num.assign(n+1,0);
    num[0] = 1; num[n+1] = m;

    for(int i=1;i<=n;i++){
        cin >> num[i];
    }

    cin >> x >> y;
    saltos.push_back(num[1]-num[0]);
    for(int i=2;i<=n+1;i++){
        if(num[i]-num[i-1]+saltos.back()<=x){
            saltos.back()+=(num[i]-num[i-1]);
        }
        else if(num[i]-num[i-1]<=y){
            saltos.back()+=(num[i]-num[i-1]);
        }
    }

    return 0;
}