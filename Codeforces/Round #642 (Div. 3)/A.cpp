#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        if(n==1){
            cout << 0 << '\n';
        }
        else if(n==2){
            cout << m << '\n';
        }
        else{
            cout << 2ll*m << '\n';
        }
    }
    
    return 0;
}