#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll x;

    cin >> x;
    ll answ = 0;
    for(int i=2;i<=x/i && x!=1;i++){
        ll qtd = 0;
        while(x%i==0){
            qtd++;
            x/=i;
        }
        answ = answ^qtd;
    }

    if(x!=1)
        answ = answ^1;

    cout << ((answ) ? "yes" : "no") <<"\n";

    return 0;
}