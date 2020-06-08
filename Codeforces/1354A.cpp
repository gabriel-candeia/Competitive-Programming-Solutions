#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ceil(ll a, ll b){
    return (a/b) + (a%b!=0);
}

int main(){
    ll t, a, b, c, d;

    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;

        a-=b;
        if(a<=0){
            cout << b << '\n';
        }
        else{
            if(c-d>0){
                cout << b + ceil(a,(c-d))*c<<"\n";
            }
            else{
                cout << "-1\n";
            }
        }   
    }

    return 0;
}