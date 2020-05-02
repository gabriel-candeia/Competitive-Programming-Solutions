#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, t;

    cin >> t;
    while(t--){
        cin >> n;
        ll acm=2, soma=0;
        int i=0;
        for(i=1;i<n/2;i++){
            soma += acm;
            acm *= 2ll;
        }
        for(;i<n-1;i++){
            soma -= acm;
            acm *= 2ll;
        }
        soma+=acm;

        cout << soma <<'\n';
    }
    return 0;
}