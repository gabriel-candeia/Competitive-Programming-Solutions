#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        ll a, b;
        ll answ = -1;
        ll safe = 1;

        cin >> a >> b;

        while(answ==-1){
            b = b*10;
            safe = safe*10;
            ll op = b + (a-b%a)%a;
            if(op-b<safe){
                answ = op;
                break;
            }
        }

        cout << answ <<"\n";
    }

    return 0;
}