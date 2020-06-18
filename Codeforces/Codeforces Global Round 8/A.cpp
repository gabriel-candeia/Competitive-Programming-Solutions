#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    ll a, b, c, n;

    cin >> t;
    while(t--){
        cin >> a >> b >> n;
        if(a>b){
            c = a;
            a = b;
            b = c;
        }
        int cnt=0;
        while(b<=n){
            cnt++;
            c = a+b;
            a = b;
            b = c;
        }

        cout << cnt << '\n';
    }

    return 0;
}