#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, caso = 0;
    cin >> t;
    while(t--){
        int n, k, mx = 0;
        map<int,int> freq;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            mx = max(mx,++freq[a]);
        }

        bool ok = (mx<=2 && n<=2*k);
        cout <<"Case #" <<  ++caso << ": " << ((ok) ? "YES" : "NO") << "\n";
    }

    return 0;
}