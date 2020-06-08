#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t, y1, y2, x1, x2;

    cin >> t;
    while(t--){
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1==x2 || y1==y2){
            cout << 1 << '\n';
        }
        else{
            cout << 1ll*(y2-y1)*(x2-x1)+1 << '\n';
        }
    }


    return 0;
}