#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll teste(ll x){
    if(x<10)
        return x;
    ll acm = 0;
    while(x){
        acm += x%10;
        x/=10;
    }
    return teste(acm);
}

int main(){
    int q;  
    cin >> q;
    
    while(q--){
        ll l, r, ciclos, answ = 0;
        cin >> l >> r;

        
        for(;teste(l)!=1 && l<=r;l++){
            answ += teste(l);
        }

        for(;teste(r)!=9 && r>=l;r--){
            answ += teste(r);
        }
        ciclos = (max(r-l+1,0ll))/9;
        answ = answ + ciclos*45;
        //cout << l << " " << r <<"\n";
        cout << answ << "\n";
    }

    return 0;
}
