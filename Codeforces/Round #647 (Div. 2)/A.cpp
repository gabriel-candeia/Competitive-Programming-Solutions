#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool pot2(ll x){
    return (x == (x&(-1ll*x)));
}

int cnt(ll x){
    int answ = 0;
    while(x!=1){
        x/=2;
        answ++;
    }
    return answ/3 + (answ%3)/2 + ((answ%3)%2);
}

int main(){
    ll a, b, t, temp;
    
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a<b){
            temp = a;
            a = b;
            b = temp;
        }

        if(a%b==0 && pot2(a/b)){
            cout << cnt(a/b) << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }

    return 0;
}