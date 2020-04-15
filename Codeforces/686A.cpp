#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, x, d;
    char op;
    ll kids=0;

    cin >> n >> x;
    while(n--){
        cin >> op >> d;
        if(op=='+'){
            x+=d;
        }
        else if(x>=d){
            x-=d;
        }
        else{
            kids++;
        }
    }

    cout << x << ' ' << kids << '\n';

    return 0;
}