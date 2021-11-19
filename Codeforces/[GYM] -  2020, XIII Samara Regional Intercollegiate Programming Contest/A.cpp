#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int main(){
    fastio();
    int n, q;
    vector<ll> arr;
    ll answ = 0;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr){
        cin >> x;
    }

    ll sinal = 1;
    for(int i=n-1;i>=0;i--){
        answ += sinal*arr[i]; 
        sinal = -sinal;    
    }

    
    cin >> q;
    while(q--){
        int l, r, v;
        cin >> l >> r >> v;
        if((r-l+1)%2){
            if((n-l+1)%2){
                answ += v;
            }
            else{
                answ -= v;
            }        
        }

        cout << answ <<"\n";        
    }

    return 0;
}