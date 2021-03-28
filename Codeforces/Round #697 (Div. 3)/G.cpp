#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
using namespace std;
ll qtd[maxn];

int main(){
    fastio();
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n,0);
        for(auto &x:arr)
            cin >> x;
        sort(arr.begin(),arr.end());

        ll answ = 0;
        for(int i=0;i<n;i++){
            ll mx = 0;
            if(arr[i]==arr[i-1])
                mx = qtd[arr[i]];
            else
                for(int j=1;j*j<=arr[i];j++)
                    if(arr[i]%j==0)
                        mx = max({qtd[j],qtd[arr[i]/j],mx});
            qtd[arr[i]] = mx+1;
            answ = max(qtd[arr[i]],answ);
        }

        for(auto x:arr)
            qtd[x] = 0;

        cout << n-answ <<'\n';
    }

    return 0;
}