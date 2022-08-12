#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        ll h1, h2, d1, d2, incW, incH, k;
        bool ok = false;

        cin >> h1 >> d1;
        cin >> h2 >> d2;
        cin >> k >> incW >> incH;

        for(int i=0;i<=k && !ok;i++){
            ll lose, win;
            lose = (h1+(k-i)*incH)/d2 + (((h1+(k-i)*incH)%d2)!=0);
            win = h2/(d1+incW*i) + ((h2%(d1+incW*i))!=0);
            ok = ok || (win<=lose);
        }

        cout << ((ok) ? "YES" : "NO") <<"\n";   

    }

    return 0;
}