#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll teto(ll a, ll b){
    return a/b + ((a%b)!=0);
}

int main(){

    int t;
    cin >> t;
    while(t--){
        ll n, m, x, y, acm;
        cin >> n >> m >> x >> y;
        acm = n;
        
        if(x<=y){
            cout << m <<"\n";
        }
        else{
          cout << min(m,(n + (m-1)*y)/x) <<"\n";
        }
    }

    return 0;
}