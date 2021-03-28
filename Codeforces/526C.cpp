#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll c, hr, hb, wr, wb, answ=0;

    cin >> c >> hr >> hb >> wr >> wb;

    ll lim = sqrt(c)+1;

    if(wr>=lim ||(wb<lim && hb*wr>=hr*wb)){
        swap(hb,hr);
        swap(wb,wr);
    }

    for(ll i=0;i<=lim;i++){
        if(i*wb<=c)
            answ = max(answ, i*hb + (max(c-i*wb,0ll)/wr)*hr);
    }
    
    cout << answ << '\n';
    

    return 0;
}