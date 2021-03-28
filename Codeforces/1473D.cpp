#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q, l, r;
        
        cin >> n >> q;
        vector<ll> mxpref(n+2,0), mxsuff(n+2,0), mnpref(n+2,0) , mnsuff(n+2,0);
        vector<ll> val(n+2,0), aux(n+2), arr(n+2,0);


        for(int i=1;i<=n;i++){
            char c;
            cin >> c;
            arr[i] = ((c=='-') ? -1 : +1);
        }
        
        for(int i=1;i<=n;i++){
            val[i] = val[i-1] + arr[i];
            mxpref[i] = max(mxpref[i-1],val[i]);
            mnpref[i] = min(mnpref[i-1],val[i]);
        }

        for(int i=n;i>=0;i--){
            aux[i] =  aux[i+1]+arr[i];
            mxsuff[i] = max(mxsuff[i+1],aux[i]);
            mnsuff[i] = min(mnsuff[i+1],aux[i]);
        }

        
        for(int i=0;i<=n;i++){
            int a = aux[i] - mnsuff[i];
            int b = aux[i] - mxsuff[i];
            mxsuff[i] = a; mnsuff[i] = b;
        }
        
        
        for(int i=0;i<q;i++){
            cin >> l >> r;
            cout << max(mxpref[l-1],val[l-1]+mxsuff[r+1]) - min(mnpref[l-1],val[l-1]+mnsuff[r+1]) + 1  << '\n';
        }
    }
    return 0;
}