#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){ 
    int t;  

    cin >> t;
    while(t--){
        ll red, blue, a, b;
        ll answ = 0;
        cin >> red >> blue >> a >> b;

        ll t = min(red/a,blue/b);
        answ = t + min((red-t*a)/b,(blue-t*b)/a);
        swap(a,b);
        t = min(red/a,blue/b);
        answ = max(answ,t + min((red-t*a)/b,(blue-t*b)/a));
        swap(a,b);
        for(ll k=0;k<2;k++){
            for(ll i=0;i*i<=max(red,blue);i++){
                if(red-i*a>=0 && blue-i*b>=0)
                    answ = max(answ,i+min((red-i*a)/b,(blue-i*b)/a));
                if(blue-i*a>=0 && red-i*b>=0)
                    answ = max(answ,i+min((blue-i*a)/b,(red-i*b)/a));
            }
            swap(a,b);
        }

        cout << answ <<"\n";

    }

    return 0;
}