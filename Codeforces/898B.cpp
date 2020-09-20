#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, a, b;

    cin >> n >> a >> b;
    bool pos=false;
    ll x, y;
    for(int i=0;i<=n/a;i++){
        if((n-a*i)%b==0){
            pos = true;
            x = i;
            y = (n-a*i)/b;
            break;
        }
    }
    if(pos){
        cout << "YES\n";
        cout << x << " " << y <<'\n';
    }
    else{
        cout << "NO\n";
    }
    return 0;
}