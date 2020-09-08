#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll q, a, b, m, k;

    cin >> q;
    while(q--){
        cin >> a >> b >> m;
        k = -1;
        for(int i=1;i<=49;i++){
            if(b-a*i<=(i-1)*m && b-a*i>=(i-1)){
                k = i;
                break;
            }
        }
        if(a==b){
            cout << 1 << " " << a <<'\n';
        }
        else if(k==-1){
            cout << k << ' ';
        }
        else if(k!=-1){
            ll x = a, rem = b-a*(k), inc = rem/(k-1);
            cout << k+1 <<' ';
            cout << x << ' ';
            x+=inc;
            rem -=inc;
            for(int i=0;i<k;i++){
                cout << x << ' ';
                if(k-i>rem){
                    inc = 1;
                }
                x+=inc+a;
                rem-=inc;
            }
        }
        cout <<'\n';
    }

    return 0;
}