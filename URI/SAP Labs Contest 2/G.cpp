#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll max(ll a, ll b){
    return (a<b) ? b : a;
}

ll min(ll a, ll b){
    return (a<b) ? a : b;
}

ll ceil(ll a, ll b){
    return a/b + ((a%b)!=0);
}

int main(){
    ll n, m, k, answ; 

    cin >> n >> m >> k;

    ll x, y;
    answ = max(n,m);
    for(int x=1;x<=k;x++){
        y = k/(x+1) - 1;
        if(y>=0){
            answ = min(answ,max(ceil(n,(x+1)),ceil(m,(y+1))));    
        }      
    }
    for(int x=1;x<=k;x++){
        y = k/(x+1) - 1;
        if(y>=0){
            answ = min(answ,max(ceil(n,(y+1)),ceil(m,(x+1))));    
        }      
    }

    cout << answ << '\n';

    return 0;
}