#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        ll answ = 0;
        for(ll i=1;i<=n;i++){
            answ += i*i*m;
        }

        cout << answ <<"\n";
    }

    return 0;
}